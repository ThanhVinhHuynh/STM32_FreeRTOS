/*
 * RCC_driver.c
 *
 *  Created on: Aug 22, 2019
 *      Author: vinht
 */

#include "RCC_driver.h"

void Set_RCC_AHB1Periph_Port_Status(uint32_t AHB1periph_port, RCC_AHB1_STATUS status)
{
	if(status == RCC_STATUS_DISABLE)
	{
		RCC_REG->RCC_AHB1ENR &= ~AHB1periph_port;
	}else
	{
		RCC_REG->RCC_AHB1ENR |= AHB1periph_port;
	}
}

void Set_RCC_APB1Periph_Port_Status(uint32_t APB1periph_port, RCC_AHB1_STATUS status)
{
	if(status == RCC_STATUS_DISABLE)
	{
		RCC_REG->RCC_APB1ENR &= ~APB1periph_port;
	}else
	{
		RCC_REG->RCC_APB1ENR |= APB1periph_port;
	}
}
