/*
 * freertos_main.c
 *
 *  Created on: Oct 18, 2019
 *      Author: suss
 */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "GPIO_Driver/gpio_driver.h"
#include "Timer_driver/timer_driver.h"
#include "RCC_driver/RCC_driver.h"
#include "Core/misc.h"
#include "Common/build_config.h"
#ifdef BUILD_DELAY
#include "SysTick/delay.h"
#endif
#ifdef BUILD_DMA
#include "DMA/dma.h"
#endif

//define unuse function with extern
/***********************************************************************/
#if 0
void vPortResetPrivilege( BaseType_t xRunningPrivileged )
{

}

BaseType_t xPortRaisePrivilege( void )
{
	__asm volatile
	(
		"	mrs r0, control						\n"
		"	tst r0, #1							\n" /* Is the task running privileged? */
		"	itte ne								\n"
		"	movne r0, #0						\n" /* CONTROL[0]!=0, return false. */
		"	svcne %0							\n" /* Switch to privileged. */
		"	moveq r0, #1						\n" /* CONTROL[0]==0, return true. */
		"	bx lr								\n"
		:: "i" (portSVC_RAISE_PRIVILEGE) : "r0", "memory"
	);

	return 0;
}
#endif
void vApplicationTickHook( void )
{

}

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
	/* The buffers used by the idle task must be static so they are persistent, and
	so exist after this function returns. */
	static StaticTask_t xIdleTaskTCB;
	static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

		/* configUSE_STATIC_ALLOCATION is set to 1, so the application has the
		opportunity to supply the buffers that will be used by the Idle task as its
		stack and to hold its TCB.  If these are set to NULL then the buffers will
		be allocated dynamically, just as if xTaskCreate() had been called. */
		*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
		*ppxIdleTaskStackBuffer = uxIdleTaskStack;
		*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE; /* In words.  NOT in bytes! */
}

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
	/* The buffers used by the Timer/Daemon task must be static so they are
	persistent, and so exist after this function returns. */
	static StaticTask_t xTimerTaskTCB;
	static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

		/* configUSE_STATIC_ALLOCATION is set to 1, so the application has the
		opportunity to supply the buffers that will be used by the Timer/RTOS daemon
		task as its	stack and to hold its TCB.  If these are set to NULL then the
		buffers will be allocated dynamically, just as if xTaskCreate() had been
		called. */
		*ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
		*ppxTimerTaskStackBuffer = uxTimerTaskStack;
		*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH; /* In words.  NOT in bytes! */
}

void vApplicationIdleHook( void )
{
	GPIO_Toggle_Bit(GPIO_PORT_D, GPIO_Pin_12);
}

void vApplicationMallocFailedHook( void )
{

}
/***********************************************************************/
#ifdef BUILD_DMA
void DMA2_Stream1_IRQHandler()
{
	volatile uint8_t itr_status = DMA_Get_Status_Tranfer(DMA2_REG, DMA_CHANNEL_SELECTED_1);
	volatile uint16_t pin;

	switch(itr_status)
	{
		case DMA_ITR_TRAN_COMPLETE:
			pin = GPIO_Pin_12;
			break;

		case DMA_ITR_TRAN_ERROR:
			pin = GPIO_Pin_13;
			break;

		case DMA_ITR_TRAN_NONE:
			pin = GPIO_Pin_14;
			break;
	}

	DMA_Clean_ITR_Pending(DMA2_REG);

	GPIO_Port_Common port;

	GPIO_Port_Init(&port);

	port.GPIO_pin = pin;

	GPIO_Port_Set_Config(GPIO_PORT_D, &port);

	GPIO_Set_Bit(GPIO_PORT_D, pin);
}

#endif
#ifdef BUILD_TIMER
void TIM2_IRQHandler()
{
	if (Timer_GetITStatus(TIMER_2, TIMER_INTERRUPT_ENABLE))
	{
		GPIO_Port_Common port;

		uint16_t pin = GPIO_Pin_13;

		GPIO_Port_Init(&port);

		port.GPIO_pin = pin;

		GPIO_Port_Set_Config(GPIO_PORT_D, &port);

		GPIO_Toggle_Bit(GPIO_PORT_D, GPIO_Pin_13);

		Timer_ClearITPendingBit(TIMER_2, TIMER_INTERRUPT_ENABLE);
	}
}
#endif

#ifdef RTOS
void vTaskRunLedBlink_1(void* pvParametersLed_1)
{
	for(;;)
	{
		GPIO_Toggle_Bit(GPIO_PORT_D, GPIO_Pin_12);

		for (int i = 0; i< 999999; i++)
		{

		}

	}
}

void vTaskRunLedBlink_2(void* pvParametersLed_2)
{

	for(;;)
	{
		GPIO_Toggle_Bit(GPIO_PORT_D, GPIO_Pin_13);

		for (int i = 0; i< 999999; i++)
		{

		}

	}
}

#define SRAM_ADDRESS	(uint8_t(0x20000000))

#define SRAM_HEAP_SIZE	(32 * 1024)
static uint8_t ucHEAP[SRAM_HEAP_SIZE];	//alocate in low address of the SRAM at compiler time
										// FreeRTOS always alocate heap memory in SRAM in run time

const HeapRegion_t	xHeapRegions[] =
{
		{ucHEAP			,	SRAM_HEAP_SIZE	},
		{NULL			, 	0				}
};
#endif

int main(void)
{
#ifdef BUILD_DMA
	Set_RCC_AHB1Periph_Port_Status(RCC_AHB1Periph_DMA2, RCC_STATUS_ENABLE);
#endif
#ifdef BUILD_TIMER
	Set_RCC_APB1Periph_Port_Status(RCC_APB1Periph_TIM2, RCC_STATUS_ENABLE);
#endif
	Set_RCC_AHB1Periph_Port_Status(RCC_AHB1Periph_GPIOD, RCC_STATUS_ENABLE);

	GPIO_Port_Common port;

	GPIO_Port_Init(&port);

	port.GPIO_pin = GPIO_Pin_12 | GPIO_Pin_13;

	GPIO_Port_Set_Config(GPIO_PORT_D, &port);

#ifdef BUILD_TIMER

	Timerx_Config timer_2;

	timer_2.TIMER_ClockDivision = TIMER_CLOCK_DIV1;
	timer_2.TIMER_Counter_mode 	= TIMER_COUNTER_DOWNCOUNTER;
	timer_2.TIMER_Period		= 9999;
	timer_2.TIMER_Prescaler		= 1599;
	Timer_Set_Config(TIMER_2, &timer_2);

	Timer_Set_Interrupt(TIMER_2, TIMER_INTERRUPT_ENABLE);

	Timer_Delay_Start(TIMER_2, TIMER_ENABLE);

	//Interrupt for timer 3
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
#endif

#ifdef BUILD_DELAY
	SysTick_gConfig sys_cfg;

	sys_cfg.reload_val = 100;	//1us second

	sys_cfg.clk_Source = SYSTICK_CLKSOURCE_PREOCESSOR;

	SysTick_Init(SysTick, &sys_cfg);

	//enable interrupt
	SysTick_Interrupt();
#endif

#ifdef BUILD_DMA

	uint32_t ARRAY_SIZE = 15500;
	//init data to source
	uint32_t source[ARRAY_SIZE];

	for(volatile uint32_t i = 0; i< ARRAY_SIZE; i++)
	{
		source[i] = i;
	}

	//int data destination
	uint32_t des[ARRAY_SIZE];

	DMAx_Config cfg;

	cfg.stream_config.channel_select					= DMA_CHANNEL_SELECTED_1;
	cfg.stream_config.data_trans_dir 					= DMA_DATA_TRANS_DIR_MEM2MEM;
	cfg.stream_config.mem_data_size 					= DMA_MEM_DATA_SIZE_WORD;
	cfg.stream_config.phe_data_size						= DMA_PHE_DATA_SIZE_WORD;
	cfg.stream_config.mem_inc_mode						= DMA_MEM_INC_MODE;
	cfg.stream_config.phe_inc_mode						= DMA_PHE_INC_MODE;
	cfg.stream_config.priority							= DMA_PRIORITY_MEDIUM;
	cfg.stream_config.trans_complete_itr_status 		= DMA_TRANS_COMPLETE_ITR_ENA;
	cfg.stream_config.tras_error_itr_status				= DMA_TRANS_ERROR_ITR_ENA;

	cfg.sizeof_data										= (uint32_t)ARRAY_SIZE;
	cfg.phe_address_trans								= (uint32_t)source;
	cfg.mem0_address_tras								= (uint32_t)des;

	DMA_Set_Config(DMA2_REG, &cfg);

	//Enable interrupt channel
	DMA_Enabe_ITR(DMA2_Stream1_IRQn);

	//Enable DMA to start transfers data.
	DMA_Set_Status(DMA2_REG, &cfg, DMA_STREAM_ENA);
#endif

#ifdef RTOS
	vPortDefineHeapRegions(xHeapRegions);


	xTaskCreate( vTaskRunLedBlink_1, "Task 1", 1000, NULL, configMAX_PRIORITIES - 1, NULL );

	/* Create the other task in exactly the same way and at the same priority. */
	xTaskCreate( vTaskRunLedBlink_2, "Task 2", 1000, NULL, configMAX_PRIORITIES - 1, NULL );

	/* Start the scheduler so the tasks start executing. */
	vTaskStartScheduler();
#endif

	while(1)
	{
		GPIO_Set_Bit(GPIO_PORT_D, GPIO_Pin_14);
#ifdef BUILD_DELAY
		delay_ns(1);
#endif
	}

	return 0;
}
