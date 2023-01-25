/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: RCC_program.c
 *       Module: RCC
 * 
 *   Description: Source file for System Clock Control Module Types
 * 
 ***************************************************************************************/

#include "Std_Types.h"
#include "Bit_Math.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidEnableSysClock(void)
{
	#if RCC_CLOCK_SOURCE == PIOSC
	
	SET_BIT(RCC,4);
	CLR_BIT(RCC,5);
	
	RCC &= (uint32)(~(0x07800000));
	
	#endif
}