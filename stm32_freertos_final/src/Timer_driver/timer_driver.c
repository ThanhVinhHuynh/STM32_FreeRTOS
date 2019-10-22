/*
 * timer_driver.c
 *
 *  Created on: Aug 22, 2019
 *      Author: VinhHT2
 */
#include "timer_driver.h"

void 		Timer_Set_Config(Timer_Struct* timerID, Timerx_Config* timer)
{
	uint16_t u16_config = timerID->TIMx_CR1;

	//reset all setting.
	u16_config &= (uint16_t)0xFC00;

	//Setting
//	u16_config |= timer->TIMER_Counter_mode;

	u16_config &= (uint16_t)(~(TIM_CR1_DIR | TIM_CR1_CMS));
	u16_config |= (uint32_t)timer->TIMER_Counter_mode;

//	u16_config |= timer->TIMER_ClockDivision;

	u16_config &=  (uint16_t)(~TIM_CR1_CKD);
	u16_config |= (uint32_t)timer->TIMER_ClockDivision;

	timerID->TIMx_CR1 = u16_config;

	timerID->TIMx_PSC = timer->TIMER_Prescaler;

	timerID->TIMx_ARR = timer->TIMER_Period;
}

void 		Timer_Delay_Start(Timer_Struct* timerID, uint16_t status_timer)
{
	if(status_timer == TIMER_ENABLE)
	{
		timerID->TIMx_CR1 |= TIMER_ENABLE;
	}else
	{
		timerID->TIMx_CR1 &= (uint16_t)~TIMER_ENABLE;
	}
}


void		Timer_Set_Interrupt(Timer_Struct* timerID, uint16_t status_interrupt)
{
	if(status_interrupt == TIMER_INTERRUPT_ENABLE)
	{
		timerID->TIMx_DIER |= TIMER_INTERRUPT_ENABLE;
	}else
	{
		timerID->TIMx_DIER &= (uint16_t)~TIMER_INTERRUPT_ENABLE;
	}
}

ITStatus Timer_GetITStatus(Timer_Struct* timerID, uint16_t status_interrupt)
{
  ITStatus bitstatus = RESET;
  uint16_t itstatus = 0x0, itenable = 0x0;
  /* Check the parameters */

  itstatus = timerID->TIMx_SR & status_interrupt;

  itenable = timerID->TIMx_DIER & status_interrupt;
  if ((itstatus != (uint16_t)RESET) && (itenable != (uint16_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

void Timer_ClearITPendingBit(Timer_Struct* timerID, uint16_t status_interrupt)
{

  /* Clear the IT pending Bit */
	timerID->TIMx_SR = (uint16_t)~status_interrupt;
}
