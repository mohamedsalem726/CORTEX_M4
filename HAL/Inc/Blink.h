/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: Blink.h
 *       Module: Blink Led
 * 
 *   Description: Header file for blinking led Module 
 * 
 ***************************************************************************************/
 
 #ifndef BLINK_H_
 #define BLINK_H_
 
 #include "SYSTICK_interface.h"
 #include "GPIO_interface.h"
 #include "RCC_interface.h"
 #include "NVIC_interface.h"
 
 
 void Func(void);
 
 void Blink_voidLedInit(void);
 
 void Blink_voidLedRunnable(Port_Type Port, Pin_Type Pin, uint8 TimeOn, uint8 TimeOff);  
 
 
 
 #endif /* BLINK_H_ */