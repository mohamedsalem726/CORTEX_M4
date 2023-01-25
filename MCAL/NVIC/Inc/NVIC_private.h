 /****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: NVIC_private.h
 *       Module: NVIC
 * 
 *   Description: Source file for NVIC Module Types
 * 
 ***************************************************************************************/
 
 #ifndef NVIC_PRIVATE_H_
 #define NVIC_PRIVATE_H_
 
 #include "Std_Types.h"
 
#define GROUP_3_SUB_0    4
#define GROUP_2_SUB_1    5
#define GROUP_1_SUB_2    6
#define GROUP_0_SUB_3    7
 
 
#define TOTAL_NUM_OF_IRQs     78
 
 
#define SCB_INTCTRL       *((volatile uint32*)0xE000ED04)
#define SCB_APINT         *((volatile uint32*)0xE000ED0C)
	

typedef struct
{
	volatile uint32 EN[5];
	volatile uint32 RESERVED1[27];
	volatile uint32	DIS[5];
	volatile uint32	RESERVED2[27];
	volatile uint32	PEND[5];
	volatile uint32	RESERVED3[27];
	volatile uint32	UNPEND[5];
	volatile uint32	RESERVED4[27];
	volatile uint32	ACTIVE[5];
	volatile uint32 RESERVED5[59];
	volatile uint8  PRI[140];
}NVIC_Register;

#define NVIC           ((volatile NVIC_Register*)0xE000E100)
#define NVIC_SWTRIG   *((volatile uint32*)0xE000EF00)
 
 #endif /* NVIC_PRIVATE_H_ */