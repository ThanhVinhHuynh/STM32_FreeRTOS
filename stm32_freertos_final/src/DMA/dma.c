/*
 * dma.c
 *
 *  Created on: Aug 29, 2019
 *      Author: VinhHT2
 */
#include "dma.h"

uint32_t DMA_Get_Stream_ID(uint32_t stream_id)
{
	switch(stream_id)
	{
		case DMA_CHANNEL_SELECTED_0:
			return 0;

		case DMA_CHANNEL_SELECTED_1:
			return 1;

		case DMA_CHANNEL_SELECTED_2:
			return 2;

		case DMA_CHANNEL_SELECTED_3:
			return 3;

		case DMA_CHANNEL_SELECTED_4:
			return 4;

		case DMA_CHANNEL_SELECTED_5:
			return 5;

		case DMA_CHANNEL_SELECTED_6:
			return 6;

		case DMA_CHANNEL_SELECTED_7:
			return 7;

		default:
			return 0;
	}
}

void DMA_Clean_ITR_Pending(DMAx_Struct* dma_x)
{
	//clean all interrupt for low and high stream.
	uint32_t itr_low_str 	= dma_x->DMA_LIFCR;
	uint32_t itr_high_str 	= dma_x->DMA_HIFCR;

	itr_low_str &= DMA_ITR_FLG_MASK;
	itr_low_str |= (uint32_t)~DMA_ITR_FLG_MASK;

	itr_high_str &= DMA_ITR_FLG_MASK;
	itr_high_str |= (uint32_t)~DMA_ITR_FLG_MASK;

	dma_x->DMA_LIFCR = itr_low_str;
	dma_x->DMA_HIFCR = itr_high_str;
}

void DMA_Set_Config(DMAx_Struct* dma_x, DMAx_Config* dmax_cfg)
{
	uint32_t add_stremx = 0x10 + (0x18 * DMA_Get_Stream_ID(dmax_cfg->stream_config.channel_select));
	uint32_t* address_cfg = (uint32_t*)dma_x + add_stremx/4;

	DMAx_Config_Common* cfg_common = (DMAx_Config_Common*)address_cfg;

	//clean all interrupt for low and high stream.
	uint32_t itr_low_str 	= dma_x->DMA_LIFCR;
	uint32_t itr_high_str 	= dma_x->DMA_HIFCR;

	itr_low_str &= DMA_ITR_FLG_MASK;
	itr_low_str |= (uint32_t)~DMA_ITR_FLG_MASK;

	itr_high_str &= DMA_ITR_FLG_MASK;
	itr_high_str |= (uint32_t)~DMA_ITR_FLG_MASK;

	dma_x->DMA_LIFCR = itr_low_str;
	dma_x->DMA_HIFCR = itr_high_str;

	//Set address data transfer for peripheral data and memory data

	cfg_common->DMA_SxPAR 	= dmax_cfg->phe_address_trans;
	cfg_common->DMA_SxM0AR 	= dmax_cfg->mem0_address_tras;

	// set data size to transfer
	cfg_common->DMA_SxNDTR = dmax_cfg->sizeof_data;

	//Check double buffer status and set memory if it's enable

	if( dmax_cfg->stream_config.double_buff == DMA_DOUBLE_BUFFER_MODE_ENA)
	{
		cfg_common->DMA_SxM1AR 	= dmax_cfg->mem1_address_tras;
	}

	//clean stream config
	uint32_t str_cfg = cfg_common->DMA_SxCR;

	str_cfg &= DMA_STR_CFG_MASK;

	//Set stream config from user setting

	str_cfg |= dmax_cfg->stream_config.channel_select 				|
			   dmax_cfg->stream_config.double_buff	 				|
			   dmax_cfg->stream_config.data_trans_dir 				|
			   dmax_cfg->stream_config.mem_data_size  				|
			   dmax_cfg->stream_config.phe_data_size  				|
			   dmax_cfg->stream_config.mem_inc_mode 				|
			   dmax_cfg->stream_config.phe_inc_mode  				|
			   dmax_cfg->stream_config.priority		  				|
			   dmax_cfg->stream_config.trans_complete_itr_status 	|
			   dmax_cfg->stream_config.tras_error_itr_status;

	cfg_common->DMA_SxCR = str_cfg;
}

void DMA_Set_Status(DMAx_Struct* dma_x, DMAx_Config* dmax_cfg, uint32_t dma_status)
{
	uint32_t add_stremx = 0x10 + (0x18 * DMA_Get_Stream_ID(dmax_cfg->stream_config.channel_select));
	uint32_t* address_cfg = (uint32_t*)dma_x + add_stremx/4;

	DMAx_Config_Common* cfg_common = (DMAx_Config_Common*)address_cfg;

	if(dma_status == DMA_STREAM_ENA)
	{
		cfg_common->DMA_SxCR |= DMA_STREAM_ENA;
	}else
	{
		cfg_common->DMA_SxCR &= (uint32_t)~DMA_STREAM_ENA;
	}

}


void DMA_Enabe_ITR(uint8_t dma_channel)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = dma_channel;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

uint8_t DMA_Get_Status_Tranfer(DMAx_Struct* dma_x, uint32_t streamId)
{
	uint32_t itr_complete, itr_error;
	itr_complete = itr_error = DMA_ITR_TRAN_NONE;

	//Read status itr when transfers completed
	switch(streamId)
	{
		case DMA_CHANNEL_SELECTED_0:
		case DMA_CHANNEL_SELECTED_4:
			itr_complete = (((dma_x->DMA_LISR & DMA_ITR_STREAM_0_MASK) & DMA_ITR_TREAM_0_BIT_TRAN_COMPLETE) == DMA_ITR_TREAM_0_BIT_TRAN_COMPLETE) ? DMA_ITR_TRAN_COMPLETE : DMA_ITR_TRAN_NONE;
			itr_error 	 = (((dma_x->DMA_LISR & DMA_ITR_STREAM_0_MASK) & DMA_ITR_TREAM_0_BIT_TRAN_ERROR) == DMA_ITR_TREAM_0_BIT_TRAN_ERROR) ? DMA_ITR_TRAN_ERROR : DMA_ITR_TRAN_NONE;
			break;

		case DMA_CHANNEL_SELECTED_1:
		case DMA_CHANNEL_SELECTED_5:
			itr_complete = (((dma_x->DMA_LISR & DMA_ITR_STREAM_1_MASK) & DMA_ITR_TREAM_1_BIT_TRAN_COMPLETE) == DMA_ITR_TREAM_1_BIT_TRAN_COMPLETE) ? DMA_ITR_TRAN_COMPLETE : DMA_ITR_TRAN_NONE;
			itr_error 	 = (((dma_x->DMA_LISR & DMA_ITR_STREAM_1_MASK) & DMA_ITR_TREAM_1_BIT_TRAN_ERROR) == DMA_ITR_TREAM_1_BIT_TRAN_ERROR) ? DMA_ITR_TRAN_ERROR : DMA_ITR_TRAN_NONE;
			break;

		case DMA_CHANNEL_SELECTED_2:
		case DMA_CHANNEL_SELECTED_6:
			itr_complete = (((dma_x->DMA_LISR & DMA_ITR_STREAM_2_MASK) & DMA_ITR_TREAM_2_BIT_TRAN_COMPLETE) == DMA_ITR_TREAM_2_BIT_TRAN_COMPLETE) ? DMA_ITR_TRAN_COMPLETE : DMA_ITR_TRAN_NONE;
			itr_error 	 = (((dma_x->DMA_LISR & DMA_ITR_STREAM_2_MASK) & DMA_ITR_TREAM_2_BIT_TRAN_ERROR) == DMA_ITR_TREAM_2_BIT_TRAN_ERROR) ? DMA_ITR_TRAN_ERROR : DMA_ITR_TRAN_NONE;
			break;

		case DMA_CHANNEL_SELECTED_3:
		case DMA_CHANNEL_SELECTED_7:
			itr_complete = (((dma_x->DMA_LISR & DMA_ITR_STREAM_3_MASK) & DMA_ITR_TREAM_3_BIT_TRAN_COMPLETE) == DMA_ITR_TREAM_3_BIT_TRAN_COMPLETE) ? DMA_ITR_TRAN_COMPLETE : DMA_ITR_TRAN_NONE;
			itr_error 	 = (((dma_x->DMA_LISR & DMA_ITR_STREAM_3_MASK) & DMA_ITR_TREAM_3_BIT_TRAN_ERROR) == DMA_ITR_TREAM_3_BIT_TRAN_ERROR) ? DMA_ITR_TRAN_ERROR : DMA_ITR_TRAN_NONE;
			break;
	}

	if(itr_error != DMA_ITR_TRAN_NONE)
	{
		return DMA_ITR_TRAN_ERROR;
	} else if(itr_complete != DMA_ITR_TRAN_NONE)
	{
		return DMA_ITR_TRAN_COMPLETE;
	} else
	{
		return DMA_ITR_TRAN_NONE;
	}
}
