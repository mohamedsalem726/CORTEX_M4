/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: SYSTICK_private.h
 *       Module: System Tick Timer
 * 
 *   Description: Header file for System Tick Timer Control Module Types
 * 
 ***************************************************************************************/
 
 #ifndef SYSTICK_PRIVATE_H_
 #define SYSTICK_PRIVATE_H_

 
 
 #define STCTRL        *((volatile uint32*)0xE000E010)
 #define STRELOAD      *((volatile uint32*)0xE000E014)
 #define STCURRENT     *((volatile uint32*)0xE000E018)
	 

 void SysTick_Handler(void);
 
 
 #endif /* SYSTICK_PRIVATE_H_ */