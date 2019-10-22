/*
 * delay.c
 *
 *  Created on: Aug 27, 2019
 *      Author: VinhHT2
 */

#include "delay.h"

void 	TimeTick_Decrement(void)
{
	if (sysTickCounter != 0x00) {
		sysTickCounter--;
	}
}

void delay_1ms(void)
{
	sysTickCounter = 1000;
	while (sysTickCounter != 0) {
	}
}

void delay_nms(uint32_t ms)
{
	while (ms--) {
		delay_1ms();
	}
}

void delay_ns(uint32_t sec)
{
	uint32_t second = sec * 1000;

	delay_nms(second);
}
