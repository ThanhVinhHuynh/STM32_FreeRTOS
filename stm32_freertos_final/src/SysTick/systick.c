/*
 * systick.c
 *
 *  Created on: Aug 27, 2019
 *      Author: VinhHT2
 */
#include "systick.h"

void 	SysTick_Set_Config(SysTick_Type* sys, SysTick_gConfig* sys_config)
{
	uint32_t ctr_reg = sys->CTRL;

	uint32_t reload_reg = sys->LOAD & SYSTICK_MASK_RVR;

	// Reset current config

	ctr_reg &= SYSTICK_MASK_CTL;

	ctr_reg |= sys_config->clk_Source;

	//Set config to control register
	sys->CTRL = ctr_reg;

	reload_reg |= sys_config->reload_val & (~SYSTICK_MASK_RVR);

	sys->LOAD = reload_reg;

	sys->VAL &= SYSTICK_MASK_RVR;
}

void 	SysTick_Set_Status(SysTick_Type* sys, uint32_t sys_status)
{
	if(SYSTICK_STATUS_ENABLE == sys_status)
	{
		sys->CTRL |= SYSTICK_STATUS_ENABLE;
	}else
	{
		sys->CTRL &= (uint16_t)~SYSTICK_STATUS_ENABLE;
	}
}

void 	SysTick_Init(SysTick_Type* sys, SysTick_gConfig* sys_config)
{
	SysTick_Set_Config(sys, sys_config);

	SysTick_Interrupt_Status(sys, SYSTICK_ITR_STATUS_ENABLE);

	SysTick_Set_Status(sys, SYSTICK_STATUS_ENABLE);
}

void SysTick_Interrupt_Status(SysTick_Type* sys, uint32_t interrupt_status)
{
	if(SYSTICK_ITR_STATUS_ENABLE == interrupt_status)
	{
		sys->CTRL |= SYSTICK_ITR_STATUS_ENABLE;
	}else
	{
		sys->CTRL &= (uint16_t)~SYSTICK_ITR_STATUS_ENABLE;
	}
}

void SysTick_Interrupt(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = SysTick_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void SysTick_Handler()
{
	TimeTick_Decrement();
}
