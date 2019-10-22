/*
 * gpio_driver.h
 *
 *  Created on: Aug 21, 2019
 *      Author: vinht
 */

#ifndef GPIO_DRIVER_GPIO_DRIVER_H_
#define GPIO_DRIVER_GPIO_DRIVER_H_

#include "../Common/stm32f411_common_vht2.h"

//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
typedef enum GPIO_Moder_Enum
{
	GPIO_MODER_INPUT,
	GPIO_MODER_OUTPUT,
	GPIO_MODER_ALTERNATE_FUNCTION,
	GPIO_MODER_ANALOG_MODE
}GPIO_Moder;

//GPIO port output type register (GPIOx_OTYPER)
typedef enum GPIO_Output_Type_Enum
{
	GPIO_OUT_PUSH_PULL,
	GPIO_OUT_OPEN_DRAIN
}GPIO_Output_Type;

//GPIO port output speed register (GPIOx_OSPEEDR)
typedef enum GPIO_Output_Speed_Enum
{
	GPIO_Output_Speed_Low,
	GPIO_Output_Speed_Medium,
	GPIO_Output_Speed_Fast,
	GPIO_Output_Speed_Hight
}GPIO_Output_Speed;

//GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..E and H)
typedef enum GPIO_Pull_Enum
{
	GPIO_Pull_None,
	GPIO_Pull_Up,
	GPIO_Pull_Down,
	GPIO_Pull_Reserved
}GPIO_Pull;


typedef struct	GPIO_Port_Common_Struct
{
	uint16_t 			GPIO_pin;				//Select pin;

	GPIO_Moder			GPIO_mode;				//Set moder;

	GPIO_Output_Type	GPIO_out_type;			//Set output type

	GPIO_Output_Speed	GPIO_output_speed;		//Set speed for output

	GPIO_Pull			GPIO_pull;				// Set Port pull status

}GPIO_Port_Common;

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  __IO uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/*Define Port ___BEGIN___*/
typedef uint32_t GPIO_PORT;


#define GPIO_PORT_A		((GPIO_TypeDef*)GPIOA_ADDRESS_REGISTER)
#define GPIO_PORT_B		((GPIO_TypeDef*)GPIOB_ADDRESS_REGISTER)
#define GPIO_PORT_C		((GPIO_TypeDef*)GPIOC_ADDRESS_REGISTER)
#define GPIO_PORT_D		((GPIO_TypeDef*)GPIOD_ADDRESS_REGISTER)
#define GPIO_PORT_E		((GPIO_TypeDef*)GPIOE_ADDRESS_REGISTER)
#define GPIO_PORT_H		((GPIO_TypeDef*)GPIOH_ADDRESS_REGISTER)

/*Define Port ___END___*/

/*Define Pin ___BEGIN___*/
#define GPIO_Pin_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /* All pins selected */
/*Define Pin ___END___*/

#define GPIO_MODER_MODER0                    ((uint32_t)0x00000003)

#define GPIO_OSPEEDER_OSPEEDR0               ((uint32_t)0x00000003)

#define GPIO_OTYPER_OT_0                     ((uint32_t)0x00000001)

#define GPIO_PUPDR_PUPDR0                    ((uint32_t)0x00000003)


void	GPIO_Reset_Port_Setting(GPIO_TypeDef* port, GPIO_Port_Common port_cfg);

void	GPIO_Port_Init(GPIO_Port_Common* port_cfg);

void 	GPIO_Port_Set_Config(GPIO_TypeDef* port, GPIO_Port_Common* port_cfg);

void	GPIO_Set_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin);

void	GPIO_Reset_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin);

void 	GPIO_Toggle_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin);

#endif /* GPIO_DRIVER_GPIO_DRIVER_H_ */
