/*
 * gpio_driver.c
 *
 *  Created on: Aug 22, 2019
 *      Author: vinht
 */
#include "gpio_driver.h"

void	GPIO_Port_Init(GPIO_Port_Common* port_cfg)
{
	port_cfg->GPIO_pin				= GPIO_Pin_All;
	port_cfg->GPIO_mode 			= GPIO_MODER_OUTPUT;
	port_cfg->GPIO_out_type			= GPIO_OUT_PUSH_PULL;
	port_cfg->GPIO_output_speed		= GPIO_Output_Speed_Hight;
	port_cfg->GPIO_pull				= GPIO_Pull_Up;
}

void 	GPIO_Port_Set_Config(GPIO_TypeDef* port, GPIO_Port_Common* port_cfg)
{
	uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

	 for (pinpos = 0x00; pinpos < 0x10; pinpos++)
	  {
	    pos = ((uint32_t)0x01) << pinpos;
	    /* Get the port pins position */
	    currentpin = (port_cfg->GPIO_pin) & pos;

	    if (currentpin == pos)
	    {
	    	port->MODER  &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
	    	port->MODER |= (((uint32_t)port_cfg->GPIO_mode) << (pinpos * 2));

	      if ((port_cfg->GPIO_mode == GPIO_MODER_OUTPUT) || (port_cfg->GPIO_mode == GPIO_MODER_ALTERNATE_FUNCTION))
	      {

	        /* Speed mode configuration */
	        port->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
	        port->OSPEEDR |= ((uint32_t)(port_cfg->GPIO_output_speed) << (pinpos * 2));


	        /* Output mode configuration*/
	        port->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos)) ;
	        port->OTYPER |= (uint16_t)(((uint16_t)port_cfg->GPIO_out_type) << ((uint16_t)pinpos));
	      }

	      /* Pull-up Pull down resistor configuration*/
	      port->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
	      port->PUPDR |= (((uint32_t)port_cfg->GPIO_pull) << (pinpos * 2));
	    }
	  }
}

void	GPIO_Set_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin)
{
	port->BSRRL |= GPIO_Pin;
}

void	GPIO_Reset_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin)
{
	port->BSRRH |= GPIO_Pin;
}

void GPIO_Toggle_Bit(GPIO_TypeDef* port, uint16_t GPIO_Pin)
{

	port->ODR ^= GPIO_Pin;
}
