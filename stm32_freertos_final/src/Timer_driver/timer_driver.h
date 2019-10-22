/*
 * timer_driver.h
 *
 *  Created on: Aug 22, 2019
 *      Author: VinhHT2
 */

#ifndef TIMER_DRIVER_TIMER_DRIVER_H_
#define TIMER_DRIVER_TIMER_DRIVER_H_
#include "../Common/stm32f411_common_vht2.h"

/*Define fir common Timer ___BEGIN___*/

#define TIMER_2	((Timer_Struct*)TIMER2_ADDRESS_REGISTER)

#define TIMER_3	((Timer_Struct*)TIMER3_ADDRESS_REGISTER)

#define TIMER_4	((Timer_Struct*)TIMER4_ADDRESS_REGISTER)

#define TIMER_5	((Timer_Struct*)TIMER5_ADDRESS_REGISTER)

#define __IO	volatile

/*Define fir common Timer ___END___*/


#define TIMER_COUNTER_DOWNCOUNTER		((uint16_t)0x0010)
#define TIMER_COUNTER_UPCOUNTER			((uint16_t)0x0000)



#define TIMER_CLOCK_DIV1				((uint16_t)0x0000)
#define TIMER_CLOCK_DIV2				((uint16_t)0x0100)
#define TIMER_CLOCK_DIV4				((uint16_t)0x0200)


#define  TIMER_ENABLE                    ((uint16_t)0x0001)            /*!<Counter enable        */
#define  TIMER_DISABLE                   ((uint16_t)0x0000)            /*!<Counter enable        */

#define  TIMER_INTERRUPT_ENABLE          ((uint16_t)0x0001)            /*!<interrupt enable        */
#define  TIMER_INTERRUPT_DISABLE         ((uint16_t)0x0000)            /*!<interrupt enable        */


#define  TIM_CR1_CEN                         ((uint16_t)0x0001)            /*!<Counter enable        */
#define  TIM_CR1_UDIS                        ((uint16_t)0x0002)            /*!<Update disable        */
#define  TIM_CR1_URS                         ((uint16_t)0x0004)            /*!<Update request source */
#define  TIM_CR1_OPM                         ((uint16_t)0x0008)            /*!<One pulse mode        */
#define  TIM_CR1_DIR                         ((uint16_t)0x0010)            /*!<Direction             */

#define  TIM_CR1_CMS                         ((uint16_t)0x0060)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       ((uint16_t)0x0020)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       ((uint16_t)0x0040)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        ((uint16_t)0x0080)            /*!<Auto-reload preload enable     */

#define  TIM_CR1_CKD                         ((uint16_t)0x0300)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       ((uint16_t)0x0100)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       ((uint16_t)0x0200)            /*!<Bit 1 */


typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef struct TIMERX_Config_Struct
{
	uint16_t TIMER_Prescaler;		//TIMx prescaler (TIMx_PSC)

	uint16_t TIMER_Counter_mode;	//TIMx control register 1 (TIMx_CR1)

	uint32_t TIMER_Period;			//TIMx auto-reload register (TIMx_ARR)

	uint16_t TIMER_ClockDivision;	//TIMx control register 1 (TIMx_CR1)

}Timerx_Config;

typedef struct Timer_Struct
{
	__IO uint16_t TIMx_CR1;			//TIMx control register 1 (TIMx_CR1) 					0x00
	__IO uint16_t reserverd1;		//reserver1

	__IO uint16_t TIMx_CR2;			//TIMx control register 1 (TIMx_CR1) 					0x04
	__IO uint16_t reserverd2;		//reserver2

	__IO uint16_t TIMx_SMCR;		//TIMx slave mode control register (TIMx_SMCR) 			0x08
	__IO uint16_t reserverd3;		//reserver2

	__IO uint16_t TIMx_DIER;		//TIMx DMA/Interrupt enable register (TIMx_DIER) 		0x0C
	__IO uint16_t reserverd4;		//reserver2

	__IO uint16_t TIMx_SR;			//TIMx status register (TIMx_SR)						0x10
	__IO uint16_t reserverd5;		//reserver2

	__IO uint16_t TIMx_EGR;			//TIMx event generation register (TIMx_EGR)				0x14
	__IO uint16_t reserverd6;		//reserver2

	__IO uint16_t TIMx_CCMR1;		//TIMx capture/compare mode register 1 (TIMx_CCMR1)		0x18
	__IO uint16_t reserverd7;		//reserver2

	__IO uint16_t TIMx_CCMR2;		//TIMx capture/compare mode register 2 (TIMx_CCMR2)		0x1C
	__IO uint16_t reserverd8;		//reserver2

	__IO uint16_t TIMx_CCER;		//TIMx capture/compare enable register (TIMx_CCER)		0x20
	__IO uint16_t reserverd9;		//reserver2

	__IO uint32_t TIMx_CNT;			//TIMx counter (TIMx_CNT)								0x24

	__IO uint16_t TIMx_PSC;			//TIMx prescaler (TIMx_PSC)								0x28
	__IO uint16_t reserverd10;		//reserver2

	__IO uint32_t TIMx_ARR;			//TIMx auto-reload register (TIMx_ARR)					0x2C
	__IO uint32_t reserved1;		//Don't user --> Reserved								0x30

	__IO uint32_t TIMx_CCR1;		//TIMx capture/compare register 1 (TIMx_CCR1)			0x34

	__IO uint32_t TIMx_CCR2;		//TIMx capture/compare register 2 (TIMx_CCR2)			0x38

	__IO uint32_t TIMx_CCR3;		//TIMx capture/compare register 3 (TIMx_CCR3)			0x3C

	__IO uint32_t TIMx_CCR4;		//TIMx capture/compare register 4 (TIMx_CCR4)			0x40

	__IO uint32_t reserved2;		//Don't user --> Reserved								0x44

	__IO uint16_t TIMx_DCR;			//TIMx DMA control register (TIMx_DCR)					0x48
	__IO uint16_t reserverd11;		//reserver2

	__IO uint16_t TIMx_DMAR;		//TIMx DMA address for full transfer (TIMx_DMAR)		0x4C
	__IO uint16_t reserverd12;		//reserver2

	__IO uint16_t TIM2_OR_TIM5;		//TIM2 or TIM5 option register (TIM2_OR_TIM5)			0x50
	__IO uint16_t reserverd13;		//reserver2
}Timer_Struct;


void 		Timer_Set_Config(Timer_Struct* timerID, Timerx_Config* timer);

void 		Timer_Delay_Start(Timer_Struct* timerID, uint16_t status_timer);

void		Timer_Set_Interrupt(Timer_Struct* timerID, uint16_t status_interrupt);

ITStatus 	Timer_GetITStatus(Timer_Struct* timerID, uint16_t status_interrupt);

void 		Timer_ClearITPendingBit(Timer_Struct* timerID, uint16_t status_interrupt);

#endif /* TIMER_DRIVER_TIMER_DRIVER_H_ */
