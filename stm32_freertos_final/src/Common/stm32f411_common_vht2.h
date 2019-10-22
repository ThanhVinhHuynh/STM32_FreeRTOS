#include <stdio.h>
#include <stdint.h>

#define     __IO    	volatile

// define base address register
#define ADDRESS_BASE					((uint32_t)0x40000000)

// define TIMER2 register
#define TIMER2_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE)

//define TIMER3 register
#define TIMER3_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x0400)

//define TIMER4 register
#define TIMER4_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x0800)

//define TIMER5 register
#define TIMER5_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x0C00)

//define RTC & BKP register
#define RTC_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x2800)

//define WWDG register
 #define WWDG_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x2C00)

//define IWDG register
 #define IWDG_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x3000)

/* SPI register map ___Begin___*/
#define I2S2ext_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x3400)

#define SPI2_I2S2_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x3800)

#define SPI3_I2S3_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x3C00)

#define I2S3ext_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x4000)
/* SPI register map ___End___*/

#define TIMER1_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x10000)

#define TIMER9_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x14000)

#define TIMER10_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x14400)

#define TIMER11_ADDRESS_REGISTER		((uint32_t)ADDRESS_BASE + 0x14800)
/* TO BE DEFINE */


//define GPIOA register
#define GPIOA_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x20000)

//define GPIOB register
#define GPIOB_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x20400)

//define GPIOC register
#define GPIOC_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x20800)

//define GPIOD register
#define GPIOD_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x20C00)

//define GPIOE register
#define GPIOE_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x21000)

//define GPIOH register
#define GPIOH_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x21C00)

//RCC clock control register (RCC_CR
#define RCC_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x23800)

//DMA1 register
#define DMA1_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x26000)

//DMA2 register
#define DMA2_ADDRESS_REGISTER			((uint32_t)ADDRESS_BASE + 0x26400)

