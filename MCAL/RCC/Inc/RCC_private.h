/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: RCC_private.h
 *       Module: RCC
 * 
 *   Description: Header file for System Clock Control Module Types
 * 
 ***************************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC      *((volatile uint32*)0x400FE060)
#define RCC2     *((volatile uint32*)0x400FE070)
	
#define PIOSC    0


#endif /* RCC_PRIVATE_H_ */