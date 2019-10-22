/*
 * RCC_driver.h
 *
 *  Created on: Aug 22, 2019
 *      Author: vinht
 */

#ifndef RCC_DRIVER_RCC_DRIVER_H_
#define RCC_DRIVER_RCC_DRIVER_H_

#include "../Common/stm32f411_common_vht2.h"

#define RCC_AHB1Periph_GPIOA             ((uint32_t)0x00000001)
#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOC             ((uint32_t)0x00000004)
#define RCC_AHB1Periph_GPIOD             ((uint32_t)0x00000008)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000010)
#define RCC_AHB1Periph_GPIOF             ((uint32_t)0x00000020)
#define RCC_AHB1Periph_GPIOG             ((uint32_t)0x00000040)
#define RCC_AHB1Periph_GPIOH             ((uint32_t)0x00000080)
#define RCC_AHB1Periph_GPIOI             ((uint32_t)0x00000100)
#define RCC_AHB1Periph_GPIOJ             ((uint32_t)0x00000200)
#define RCC_AHB1Periph_GPIOK             ((uint32_t)0x00000400)
#define RCC_AHB1Periph_CRC               ((uint32_t)0x00001000)
#define RCC_AHB1Periph_FLITF             ((uint32_t)0x00008000)
#define RCC_AHB1Periph_SRAM1             ((uint32_t)0x00010000)
#define RCC_AHB1Periph_SRAM2             ((uint32_t)0x00020000)
#define RCC_AHB1Periph_BKPSRAM           ((uint32_t)0x00040000)
#define RCC_AHB1Periph_SRAM3             ((uint32_t)0x00080000)
#define RCC_AHB1Periph_CCMDATARAMEN      ((uint32_t)0x00100000)
#define RCC_AHB1Periph_DMA1              ((uint32_t)0x00200000)
#define RCC_AHB1Periph_DMA2              ((uint32_t)0x00400000)
#define RCC_AHB1Periph_DMA2D             ((uint32_t)0x00800000)
#define RCC_AHB1Periph_ETH_MAC           ((uint32_t)0x02000000)
#define RCC_AHB1Periph_ETH_MAC_Tx        ((uint32_t)0x04000000)
#define RCC_AHB1Periph_ETH_MAC_Rx        ((uint32_t)0x08000000)
#define RCC_AHB1Periph_ETH_MAC_PTP       ((uint32_t)0x10000000)
#define RCC_AHB1Periph_OTG_HS            ((uint32_t)0x20000000)
#define RCC_AHB1Periph_OTG_HS_ULPI       ((uint32_t)0x40000000)


#define RCC_APB1Periph_TIM2              ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM3              ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM4              ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM5              ((uint32_t)0x00000008)
#define RCC_APB1Periph_TIM6              ((uint32_t)0x00000010)
#define RCC_APB1Periph_TIM7              ((uint32_t)0x00000020)
#define RCC_APB1Periph_TIM12             ((uint32_t)0x00000040)
#define RCC_APB1Periph_TIM13             ((uint32_t)0x00000080)
#define RCC_APB1Periph_TIM14             ((uint32_t)0x00000100)


typedef enum
{
	RCC_STATUS_DISABLE,
	RCC_STATUS_ENABLE
}RCC_AHB1_STATUS;

typedef struct
{
	__IO uint32_t RCC_CR;				//RCC clock control register (RCC_CR)						0x00
	__IO uint32_t RCC_PLLCFGR;			//RCC PLL configuration register (RCC_PLLCFGR)				0x04
	__IO uint32_t RCC_CFGR;				//RCC clock configuration register (RCC_CFGR)				0x08
	__IO uint32_t RCC_CIR;				//RCC clock interrupt register (RCC_CIR)					0x0C
	__IO uint32_t RCC_AHB1RSTR;			//RCC AHB1 peripheral reset register (RCC_AHB1RSTR)			0x10
	__IO uint32_t RCC_AHB2RSTR;			//RCC AHB2 peripheral reset register (RCC_AHB2RSTR)			0x14
	__IO uint32_t reserved1;				//Reversed1													0x18
	__IO uint32_t reserved2;				//Reversed2													0x1C
	__IO uint32_t RCC_APB1RSTR;			//RCC APB1 peripheral reset register for (RCC_APB1RSTR)		0x20
	__IO uint32_t RCC_APB2RSTR;			//RCC APB2 peripheral reset register (RCC_APB2RSTR)			0x24
	__IO uint32_t reserved3;				//Reversed1													0x28
	__IO uint32_t reserved4;				//Reversed2													0x2C
	__IO uint32_t RCC_AHB1ENR;			//RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)	0x30
	__IO uint32_t RCC_AHB2ENR;			//RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)	0x34
	__IO uint32_t reserved5;				//Reversed1													0x38
	__IO uint32_t reserved6;				//Reversed2													0x3C
	__IO uint32_t RCC_APB1ENR;			//RCC APB1 peripheral clock enable register (RCC_APB1ENR)	0x40
	__IO uint32_t RCC_APB2ENR;			//RCC APB2 peripheral clock enable register					0x44
	__IO uint32_t reserved7;				//Reversed1													0x48
	__IO uint32_t reserved8;				//Reversed2													0x4C
	__IO uint32_t RCC_AHB1LPENR;			//RCC AHB1 peripheral clock enable in low power mode register	0x50
	__IO uint32_t RCC_AHB2LPENR;			//RCC AHB2 peripheral clock enable in low power mode register	0x54
	__IO uint32_t reserved9;				//Reversed1													0x58
	__IO uint32_t reserved10;			//Reversed2													0x5C
	__IO uint32_t RCC_APB1LPENR;			//RCC APB1 peripheral clock enable in low power mode register	0x60
	__IO uint32_t RCC_APB2LPENR;			//RCC APB2 peripheral clock enabled in low power mode register	0x64
	__IO uint32_t reserved11;			//Reversed1													0x68
	__IO uint32_t reserved12;			//Reversed2													0x6C
	__IO uint32_t RCC_BDCR;				//RCC Backup domain control register (RCC_BDCR)				0x70
	__IO uint32_t RCC_CSR;				//RCC clock control & status register (RCC_CSR)				0x74
	__IO uint32_t reserved13;			//Reversed1													0x78
	__IO uint32_t reserved14;			//Reversed2													0x7C
	__IO uint32_t RCC_SSCGR;				//RCC spread spectrum clock generation register (RCC_SSCGR)	0x80
	__IO uint32_t RCC_PLLI2SCFGR;		//RCC PLLI2S configuration register (RCC_PLLI2SCFGR)		0x84
	__IO uint32_t reserved15;			//Reversed2													0x88
	__IO uint32_t RCC_DCKCFGR;			//RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)	0x8C
}RCC_TypeDef;

#define RCC_REG ((RCC_TypeDef*)RCC_ADDRESS_REGISTER)

void Set_RCC_AHB1Periph_Port_Status(uint32_t AHB1periph_port, RCC_AHB1_STATUS status);

void Set_RCC_APB1Periph_Port_Status(uint32_t APB1periph_port, RCC_AHB1_STATUS status);
#endif /* RCC_DRIVER_RCC_DRIVER_H_ */
