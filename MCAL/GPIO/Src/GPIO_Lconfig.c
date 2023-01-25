/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: GPIO_Lconfig.c
 *       Module: General Purpose Input Output 
 * 
 *   Description: Source file for GPIO Module Types
 * 
 ***************************************************************************************/

#include "GPIO_interface.h"
#include "GPIO_Pconfig.h"


const Pin_Config_Type PIN_ARR[3] = {
		{PORTA , PIN0 , DIO , HIGH , OUTPUT , PULLUP , MA_AMPERE_2 } ,
		{PORTB , PIN0 , DIO , LOW , INPUT , PULLUP, MA_AMPERE_2 } ,
		{PORTB , PIN1 , DIO , LOW , INPUT , PULLUP, MA_AMPERE_2 } 
};