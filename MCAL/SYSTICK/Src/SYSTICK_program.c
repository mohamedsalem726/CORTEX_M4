/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: SYSTICK_program.c
 *       Module: System Tick Timer
 * 
 *   Description: Source file for System Tick Timer Control Module Types
 * 
 ***************************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

static void (*pFunc_STK)(void);


void SYSTICK_voidDelayOneSec(void)
{
	/* Disable System Tick Before Init */
	//STCTRL = 0;
	
	/* Put the value in STRELOAD register */
	STRELOAD = 0x00F42400;
	
	/* Clear STCURRENT register */
	STCURRENT = 0;
	
	/* Setting system Tick Clock and interrupt Configuration */
	STCTRL |= 0x7;
	
	
}

 void SYSTICK_SetCallBack(void (*Local_pFunc)(void))
 {
	 pFunc_STK = Local_pFunc;
	 
 }
 
 void SysTick_Handler(void)
 {
	STCURRENT = 0;
	 
	 pFunc_STK();
 }