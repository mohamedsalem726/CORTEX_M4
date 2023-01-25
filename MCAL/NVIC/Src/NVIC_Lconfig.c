 /****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: NVIC_Lconfig.c
 *       Module: NVIC
 * 
 *   Description: Source file for NVIC Module Types
 * 
 ***************************************************************************************/
#include "Std_Types.h"
#include "NVIC_Pconfig.h"
#include "NVIC_interface.h"



const NVIC_Config_Type NVIC_Configurition[78] = {
		{INT_GPIOA , DISABLE , 1 } , {INT_GPIOB , DISABLE , 4 } , {INT_GPIOC , DISABLE , 4 } ,
		{INT_GPIOD , DISABLE , 4 } , {INT_GPIOE , DISABLE , 5 } , {INT_UART0 , DISABLE , 4 } ,
		{INT_UART1 , DISABLE , 0 } , {INT_SSI0 , DISABLE , 0 } , {INT_I2C0 , DISABLE , 0 } ,
		{INT_PWM0_FAULT , DISABLE , 0 } , {INT_PWM0_GEN0 , DISABLE , 0 } , {INT_PWM0_GEN1 , DISABLE , 0 } ,
		{INT_PWM0_GEN2 , DISABLE , 0 } , {INT_QEI0 , DISABLE , 0 } , {INT_ADC0_SEQ0 , DISABLE , 0 } ,
		{INT_ADC0_SEQ1 , DISABLE , 0 } , {INT_ADC0_SEQ2 , DISABLE , 0 } , {INT_ADC0_SEQ3 , DISABLE , 0 } ,
		{INT_WDT , DISABLE , 0 } , {INT_TIMER0A , DISABLE , 0 } , {INT_TIMER0B , DISABLE , 0 } ,
		{INT_TIMER1A , DISABLE , 0 } , {INT_TIMER1B , DISABLE , 0 } , {INT_TIMER2A , DISABLE , 0 } ,
		{INT_TIMER2B , DISABLE , 0 } , {INT_COMP0 , DISABLE , 0 } , {INT_COMP1 , DISABLE , 0 } ,
		{INT_SYSCTL , ENABLE , 0 } , {INT_FLASH , DISABLE , 0 } , {INT_GPIOF , DISABLE , 0 } ,
		{INT_UART2 , DISABLE , 0 } , {INT_SSI1 , DISABLE , 0 } , {INT_TIMER3A , DISABLE , 0 } ,
		{INT_TIMER3B , DISABLE , 0 } , {INT_I2C13 , DISABLE , 0 } , {INT_QEI1 , DISABLE , 0 } ,
		{INT_CAN0 , DISABLE , 0 } , {INT_CAN1 , DISABLE , 0 } , {INT_HIBERNATE , DISABLE , 0 } ,
		{INT_USB , DISABLE , 0 } , {INT_PWM0_GEN3 , DISABLE , 0 } , {INT_UDMA , DISABLE , 0 } ,
		{INT_UDMAERR , DISABLE , 0 } , {INT_ADC1_SEQ0 , DISABLE , 0 } , {INT_ADC1_SEQ1 , DISABLE , 0 } ,
		{INT_ADC1_SEQ2 , DISABLE , 0 } , {INT_ADC1_SEQ3 , DISABLE , 0 } , {INT_SSI2 , DISABLE , 0 } ,
		{INT_SSI3 , DISABLE , 0 } , {INT_UART3 , DISABLE , 0 } , {INT_UART4, DISABLE , 0 } ,
		{INT_UART5 , DISABLE , 0 } , {INT_UART6 , DISABLE , 0 } , {INT_UART7 , DISABLE , 0 } ,
		{INT_I2C2 , DISABLE , 0 } , {INT_I2C3 , DISABLE , 0 } , {INT_TIMER4A , DISABLE , 0 } ,
		{INT_TIMER4B , DISABLE , 0 } , {INT_TIMER5A , DISABLE , 0 } , {INT_TIMER5B , DISABLE , 0 } ,
		{INT_WTIMER0A , DISABLE , 0 } , {INT_WTIMER0B , DISABLE , 0 } , {INT_WTIMER1A , DISABLE , 0 } ,
		{INT_WTIMER1B , DISABLE , 0 } , {INT_WTIMER2A , DISABLE , 0 } , {INT_WTIMER2B , DISABLE , 0 } ,
		{INT_WTIMER3A , DISABLE , 0 } , {INT_WTIMER3B , DISABLE , 0 } , {INT_WTIMER4A , DISABLE , 0 } ,
		{INT_WTIMER4B , DISABLE , 0 } , {INT_WTIMER5A , DISABLE , 0 } , {INT_WTIMER5B , DISABLE , 0 } ,
		{INT_SYSEXC , DISABLE , 0 } , {INT_PWM1_GEN0 , DISABLE , 0 } , {INT_PWM1_GEN1 , DISABLE , 0 } ,
		{INT_PWM1_GEN2 , DISABLE , 0 } , {INT_PWM1_GEN3, DISABLE , 0 } , {INT_PWM1_FAULT , DISABLE , 0 } 
	
};
