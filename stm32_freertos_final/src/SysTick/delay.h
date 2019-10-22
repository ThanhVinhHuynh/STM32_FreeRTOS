/*
 * delay.h
 *
 *  Created on: Aug 27, 2019
 *      Author: VinhHT2
 */

#ifndef SYSTICK_DELAY_H_
#define SYSTICK_DELAY_H_

#include "systick.h"


static __IO uint32_t sysTickCounter;

void delay_nms(uint32_t ms);

void delay_1ms(void);

void delay_ns(uint32_t sec);

#endif /* SYSTICK_DELAY_H_ */
