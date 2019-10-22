/*
 * dma.h
 *
 *  Created on: Aug 27, 2019
 *      Author: VinhHT2
 */

#ifndef DMA_DMA_H_
#define DMA_DMA_H_

#include "../Common/stm32f411_common_vht2.h"
#include "../Core/misc.h"

#define DMA1_REG 	((DMAx_Struct*)DMA1_ADDRESS_REGISTER)
#define DMA2_REG 	((DMAx_Struct*)DMA2_ADDRESS_REGISTER)

/*DMA stream x configuration register (DMA_SxCR) (x = 0..7) ___BEGIN___*/

#define	DMA_STR_CFG_MASK				((uint32_t)0xF0100000)

//DMA interrupt flag for common register (high and low)
#define DMA_ITR_STREAM_0_MASK			((uint32_t)0x0000003D)
#define DMA_ITR_STREAM_1_MASK			((uint32_t)0x00000F40)
#define DMA_ITR_STREAM_2_MASK			((uint32_t)0x003D0000)
#define DMA_ITR_STREAM_3_MASK			((uint32_t)0xF4000030)

//Mask to check status bit
#define DMA_ITR_TREAM_0_BIT_TRAN_COMPLETE		((uint32_t)0x00000001 << 5)
#define DMA_ITR_TREAM_1_BIT_TRAN_COMPLETE		((uint32_t)0x00000001 << 11)
#define DMA_ITR_TREAM_2_BIT_TRAN_COMPLETE		((uint32_t)0x00000001 << 21)
#define DMA_ITR_TREAM_3_BIT_TRAN_COMPLETE		((uint32_t)0x00000001 << 27)

#define DMA_ITR_TREAM_0_BIT_TRAN_ERROR			((uint32_t)0x00000001 << 3)
#define DMA_ITR_TREAM_1_BIT_TRAN_ERROR			((uint32_t)0x00000001 << 9)
#define DMA_ITR_TREAM_2_BIT_TRAN_ERROR			((uint32_t)0x00000001 << 19)
#define DMA_ITR_TREAM_3_BIT_TRAN_ERROR			((uint32_t)0x00000001 << 25)

//Status transfer itr
#define DMA_ITR_TRAN_NONE						((uint8_t)0x00)
#define DMA_ITR_TRAN_COMPLETE					((uint8_t)0x01)
#define DMA_ITR_TRAN_ERROR						((uint8_t)0x02)

//CHSEL[2:0]: Channel selection
#define	DMA_CHANNEL_SELECTED_0			((uint32_t)0x00000000)
#define	DMA_CHANNEL_SELECTED_1			((uint32_t)0x02000000)
#define	DMA_CHANNEL_SELECTED_2			((uint32_t)0x04000000)
#define	DMA_CHANNEL_SELECTED_3			((uint32_t)0x06000000)
#define	DMA_CHANNEL_SELECTED_4			((uint32_t)0x08000000)
#define	DMA_CHANNEL_SELECTED_5			((uint32_t)0x0A000000)
#define	DMA_CHANNEL_SELECTED_6			((uint32_t)0x0C000000)
#define	DMA_CHANNEL_SELECTED_7			((uint32_t)0x0E000000)

//Bit 18 DBM: Double buffer mode
#define DMA_DOUBLE_BUFFER_MODE_DIS		((uint32_t)0x00000000)
#define DMA_DOUBLE_BUFFER_MODE_ENA		((uint32_t)0x00040000)

//PL[1:0]: Priority level
#define DMA_PRIORITY_LOW				((uint32_t)0x00000000)
#define DMA_PRIORITY_MEDIUM				((uint32_t)0x00010000)
#define DMA_PRIORITY_HIGH				((uint32_t)0x00020000)
#define DMA_PRIORITY_VRHIGH				((uint32_t)0x00030000)

//MSIZE[1:0]: Memory data size
#define	DMA_MEM_DATA_SIZE_BYTE			((uint32_t)0x00000000)
#define	DMA_MEM_DATA_SIZE_HALF_WORD		((uint32_t)0x00002000)
#define	DMA_MEM_DATA_SIZE_WORD			((uint32_t)0x00004000)

//PSIZE[1:0]: Peripheral data size
#define	DMA_PHE_DATA_SIZE_BYTE			((uint32_t)0x00000000)
#define	DMA_PHE_DATA_SIZE_HALF_WORD		((uint32_t)0x00000800)
#define	DMA_PHE_DATA_SIZE_WORD			((uint32_t)0x00001000)

//MINC: Memory increment mode
#define DMA_MEM_INC_MODE				((uint32_t)0x00000400)

//PINC: Peripheral increment mode
#define DMA_PHE_INC_MODE				((uint32_t)0x00000200)

//DIR[1:0]: Data transfer direction
#define	DMA_DATA_TRANS_DIR_PHE2MEM		((uint32_t)0x00000000)
#define	DMA_DATA_TRANS_DIR_MEM2PHE		((uint32_t)0x00000040)
#define	DMA_DATA_TRANS_DIR_MEM2MEM		((uint32_t)0x00000080)

//TCIE: Transfer complete interrupt enable
#define DMA_TRANS_COMPLETE_ITR_DIS		((uint32_t)0x00000000)
#define DMA_TRANS_COMPLETE_ITR_ENA		((uint32_t)0x00000010)

//TEIE: Transfer error interrupt enable
#define DMA_TRANS_ERROR_ITR_DIS			((uint32_t)0x00000000)
#define DMA_TRANS_ERROR_ITR_ENA			((uint32_t)0x00000004)

//Bit 0 EN: Stream enable / flag stream ready when read low
#define DMA_STREAM_DIS					((uint32_t)0x00000000)
#define DMA_STREAM_ENA					((uint32_t)0x00000001)
/*DMA stream x configuration register (DMA_SxCR) (x = 0..7) ___END___*/

/*DMA low and high interrupt flag clear register (DMA_LIFCR) ___BEGIN___*/
#define	DMA_ITR_FLG_MASK				((uint32_t)0xF082F082)
/*DMA low and high interrupt flag clear register (DMA_LIFCR) ___END___*/

typedef struct
{
	uint32_t	channel_select;					//CHSEL[2:0]: Channel selection

	uint32_t	double_buff;					//DBM: Double buffer mode

	uint32_t	priority;						//PL[1:0]: Priority level

	uint32_t	mem_data_size;					//MSIZE[1:0]: Memory data size

	uint32_t	phe_data_size;					//PSIZE[1:0]: Peripheral data size

	uint32_t	mem_inc_mode;					//MINC: Memory increment mode

	uint32_t	phe_inc_mode;					//PINC: Peripheral increment mode

	uint32_t	data_trans_dir;					//DIR[1:0]: Data transfer direction

	uint32_t	trans_complete_itr_status;		//TEIE: Transfer error interrupt enable

	uint32_t	tras_error_itr_status;			//TEIE: Transfer error interrupt enable

}Stream_Config;

typedef struct
{

	Stream_Config	stream_config;			//DMA stream x configuration register (DMA_SxCR) (x = 0..7)

	uint32_t		sizeof_data;			//DMA stream x number of data register (DMA_SxNDTR) (x = 0..7)

	uint32_t		phe_address_trans;		//DMA stream x peripheral address register (DMA_SxPAR) (x = 0..7)

	uint32_t		mem0_address_tras;		//DMA stream x memory 0 address register (DMA_SxM0AR) (x = 0..7)

	uint32_t		mem1_address_tras;		//DMA stream x memory 1 address register (DMA_SxM1AR) (x = 0..7)
}DMAx_Config;

typedef struct {
/*DMA config stream x __BEGIN___*/
__IO uint32_t	DMA_SxCR;					//DMA stream x configuration register (DMA_SxCR)
											//0x10 + 0x18 x stream number

__IO uint32_t	DMA_SxNDTR;					//DMA stream x number of data register (DMA_SxNDTR)
											//0x14 + 0x18 x stream number

__IO uint32_t	DMA_SxPAR;					//DMA stream x peripheral address register (DMA_SxPAR)
											//0x18 + 0x18 x stream number

__IO uint32_t	DMA_SxM0AR;					//DMA stream x memory 0 address register (DMA_SxM0AR)
											//0x1C + 0x18 x stream number

__IO uint32_t	DMA_SxM1AR;					//DMA stream x memory 1 address register (DMA_SxM1AR)
											//0x20 + 0x18 x stream number

__IO uint32_t 	DMA_SxFCR;					//DMA stream x FIFO control register (DMA_SxFCR)
											//0x24 + 0x18 x stream number
/*DMA config stream x __END___*/
}DMAx_Config_Common;

typedef struct
{
	__IO uint32_t	DMA_LISR;					//DMA low interrupt status register (DMA_LISR)
												//0x00

	__IO uint32_t	DMA_HISR;					//DMA high interrupt status register (DMA_HISR)
												//0x04

	__IO uint32_t	DMA_LIFCR;					//DMA low interrupt flag clear register (DMA_LIFCR)
												//0x08

	__IO uint32_t	DMA_HIFCR;					//DMA high interrupt flag clear register (DMA_HIFCR)
												//0x0C
	/*DMA config stream 0 __BEGIN___*/
	__IO uint32_t	DMA_S0CR;					//DMA stream 0 configuration register (DMA_S0CR)
												//0x10

	__IO uint32_t	DMA_S0NDTR;					//DMA stream 0 number of data register (DMA_S0NDTR)
												//0x14

	__IO uint32_t	DMA_S0PAR;					//DMA stream 0 peripheral address register (DMA_S0PAR)
												//0x18

	__IO uint32_t	DMA_S0M0AR;					//DMA stream 0 memory 0 address register (DMA_S0M0AR)
												//0x1C

	__IO uint32_t	DMA_S0M1AR;					//DMA stream 0 memory 1 address register (DMA_S0M1AR)
												//0x20

	__IO uint32_t 	DMA_S0FCR;					//DMA stream 0 FIFO control register (DMA_S0FCR)
												//0x24
	/*DMA config stream 0 __END___*/

	/*DMA config stream 1 __BEGIN___*/
	__IO uint32_t	DMA_S1CR;					//DMA stream 1 configuration register (DMA_SxCR)
												//0x28

	__IO uint32_t	DMA_S1NDTR;					//DMA stream 1 number of data register (DMA_SxNDTR)
												//0x2C

	__IO uint32_t	DMA_S1PAR;					//DMA stream 1 peripheral address register (DMA_SxPAR)
												//0x30

	__IO uint32_t	DMA_S1M0AR;					//DMA stream 1 memory 0 address register (DMA_S0MxAR)
												//0x34

	__IO uint32_t	DMA_S1M1AR;					//DMA stream 1 memory 1 address register (DMA_SxM1AR)
												//0x38

	__IO uint32_t 	DMA_S1FCR;					//DMA stream 1 FIFO control register (DMA_SxFCR)
												//0x3C
	/*DMA config stream 1 __END___*/

	/*DMA config stream 2 __BEGIN___*/
	__IO uint32_t	DMA_S2CR;					//DMA stream 2 configuration register (DMA_SxCR)
												//0x40

	__IO uint32_t	DMA_S2NDTR;					//DMA stream 2 number of data register (DMA_SxNDTR)
												//0x44

	__IO uint32_t	DMA_S2PAR;					//DMA stream 2 peripheral address register (DMA_SxPAR)
												//0x48

	__IO uint32_t	DMA_S2M0AR;					//DMA stream 2 memory 0 address register (DMA_S0MxAR)
												//0x4C

	__IO uint32_t	DMA_S2M1AR;					//DMA stream 2 memory 1 address register (DMA_SxM1AR)
												//0x50

	__IO uint32_t 	DMA_S2FCR;					//DMA stream 2 FIFO control register (DMA_SxFCR)
												//0x54
	/*DMA config stream 2 __END___*/

	/*DMA config stream 3 __BEGIN___*/
	__IO uint32_t	DMA_S3CR;					//DMA stream 3 configuration register (DMA_SxCR)
												//0x58

	__IO uint32_t	DMA_S3NDTR;					//DMA stream 3 number of data register (DMA_SxNDTR)
												//0x5C

	__IO uint32_t	DMA_S3PAR;					//DMA stream 3 peripheral address register (DMA_SxPAR)
												//0x60

	__IO uint32_t	DMA_S3M0AR;					//DMA stream 3 memory 0 address register (DMA_S0MxAR)
												//0x64

	__IO uint32_t	DMA_S3M1AR;					//DMA stream 3 memory 1 address register (DMA_SxM1AR)
												//0x68

	__IO uint32_t 	DMA_S3FCR;					//DMA stream 3 FIFO control register (DMA_SxFCR)
												//0x6C
	/*DMA config stream 3 __END___*/

	/*DMA config stream 4 __BEGIN___*/
	__IO uint32_t	DMA_S4CR;					//DMA stream 4 configuration register (DMA_SxCR)
												//0x70

	__IO uint32_t	DMA_S4NDTR;					//DMA stream 4 number of data register (DMA_SxNDTR)
												//0x74

	__IO uint32_t	DMA_S4PAR;					//DMA stream 4 peripheral address register (DMA_SxPAR)
												//0x78

	__IO uint32_t	DMA_S4M0AR;					//DMA stream 4 memory 0 address register (DMA_S0MxAR)
												//0x7C

	__IO uint32_t	DMA_S4M1AR;					//DMA stream 4 memory 1 address register (DMA_SxM1AR)
												//0x80

	__IO uint32_t 	DMA_S4FCR;					//DMA stream 4 FIFO control register (DMA_SxFCR)
												//0x84
	/*DMA config stream 4 __END___*/

	/*DMA config stream 5 __BEGIN___*/
	__IO uint32_t	DMA_S5CR;					//DMA stream 5 configuration register (DMA_SxCR)
												//0x88

	__IO uint32_t	DMA_S5NDTR;					//DMA stream 5 number of data register (DMA_SxNDTR)
												//0x8C

	__IO uint32_t	DMA_S5PAR;					//DMA stream 5 peripheral address register (DMA_SxPAR)
												//0x90

	__IO uint32_t	DMA_S5M0AR;					//DMA stream 5 memory 0 address register (DMA_S0MxAR)
												//0x94

	__IO uint32_t	DMA_S5M1AR;					//DMA stream 5 memory 1 address register (DMA_SxM1AR)
												//0x98

	__IO uint32_t 	DMA_S5FCR;					//DMA stream 5 FIFO control register (DMA_SxFCR)
												//0x9C
	/*DMA config stream 5 __END___*/

	/*DMA config stream 6 __BEGIN___*/
	__IO uint32_t	DMA_S6CR;					//DMA stream 6 configuration register (DMA_SxCR)
												//0xA0

	__IO uint32_t	DMA_S6NDTR;					//DMA stream 6 number of data register (DMA_SxNDTR)
												//0xA4

	__IO uint32_t	DMA_S6PAR;					//DMA stream 6 peripheral address register (DMA_SxPAR)
												//0xA8

	__IO uint32_t	DMA_S6M0AR;					//DMA stream 6 memory 0 address register (DMA_S0MxAR)
												//0xAC

	__IO uint32_t	DMA_S6M1AR;					//DMA stream 6 memory 1 address register (DMA_SxM1AR)
												//0xB0

	__IO uint32_t 	DMA_S6FCR;					//DMA stream 6 FIFO control register (DMA_SxFCR)
												//0xB4
	/*DMA config stream 6 __END___*/

	/*DMA config stream 7 __BEGIN___*/
	__IO uint32_t	DMA_S7CR;					//DMA stream 7 configuration register (DMA_SxCR)
												//0xB8

	__IO uint32_t	DMA_S7NDTR;					//DMA stream 7 number of data register (DMA_SxNDTR)
												//0xBC

	__IO uint32_t	DMA_S7PAR;					//DMA stream 7 peripheral address register (DMA_SxPAR)
												//0xC0

	__IO uint32_t	DMA_S7M0AR;					//DMA stream 7 memory 0 address register (DMA_S0MxAR)
												//0xC4

	__IO uint32_t	DMA_S7M1AR;					//DMA stream 7 memory 1 address register (DMA_SxM1AR)
												//0xC8

	__IO uint32_t 	DMA_S7FCR;					//DMA stream 7 FIFO control register (DMA_SxFCR)
												//0xCC
	/*DMA config stream 7 __END___*/
}DMAx_Struct;

void DMA_Set_Config(DMAx_Struct* dma_x, DMAx_Config* dmax_cfg);

void DMA_Set_Status(DMAx_Struct* dma_x, DMAx_Config* dmax_cfg, uint32_t dma_status);

void DMA_Enabe_ITR(uint8_t dma_channel);

uint8_t DMA_Get_Status_Tranfer(DMAx_Struct* dma_x, uint32_t streamId);

void DMA_Clean_ITR_Pending(DMAx_Struct* dma_x);

uint32_t DMA_Get_Stream_ID(uint32_t stream_id);

#endif /* DMA_DMA_H_ */
