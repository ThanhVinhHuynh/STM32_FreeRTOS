/*
 * systick.h
 *
 *  Created on: Aug 27, 2019
 *      Author: VinhHT2
 */

#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_

#include "../Core/core_cm4.h"
#include "../Core/misc.h"
#include "../Common/build_config.h"

typedef struct
{
	uint32_t 	clk_Source;		//Indicates the clock source:
								//0 = external clock
								//1 = processor clock.
								// Register SYST_CSR


	uint32_t	reload_val;		//Value to load into the SYST_CVR register when the counter is enabled and when it reaches 0
								//Register SYST_RVR

}SysTick_gConfig;

#define		SYSTICK_STATUS_ENABLE		((uint32_t)0x00000001)
#define 	SYSTICK_STATUS_DISABLE		((uint32_t)0x00000000)

#define		SYSTICK_ITR_STATUS_ENABLE		((uint32_t)0x00000002)
#define 	SYSTICK_ITR_STATUS_DISABLE		((uint32_t)0x00000000)

#define		SYSTICK_MASK_RVR			((uint32_t)0xFF000000)

#define 	SYSTICK_MASK_CTL			((uint32_t)0xFFFEFFF8)

#define 	SYSTICK_CLKSOURCE_EXTERNAL		((uint32_t)0x00000000)
#define 	SYSTICK_CLKSOURCE_PREOCESSOR	((uint32_t)0x00000004)

void 	SysTick_Set_Config(SysTick_Type* sys, SysTick_gConfig* sys_config);

void 	SysTick_Set_Status(SysTick_Type* sys, uint32_t sys_status);

void 	SysTick_Init(SysTick_Type* sys, SysTick_gConfig* sys_config);

void 	TimeTick_Decrement(void);

void 	SysTick_Interrupt(void);

void 	SysTick_Interrupt_Status(SysTick_Type* sys, uint32_t interrupt_status);
#ifndef RTOS
void 	SysTick_Handler();
#endif

#endif /* SYSTICK_SYSTICK_H_ */
