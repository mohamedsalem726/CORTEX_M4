 /****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: NVIC_program.c
 *       Module: NVIC
 * 
 *   Description: Source file for NVIC Module Types
 * 
 ***************************************************************************************/
 
 #include "Std_Types.h"
 #include "Bit_Math.h"
 
 #include "NVIC_interface.h"
 #include "NVIC_private.h"
 #include "NVIC_Pconfig.h"
 
 
void NVIC_voidEnableInterrupt(NVIC_IRQ_Type IRQ_Type)
{
	uint8 Reg_Address = IRQ_Type / 32;
	uint8 Pin = IRQ_Type % 32;
	
	if(Reg_Address == 0)
	{
		SET_BIT(NVIC->EN[0], Pin);
	}
	else if(Reg_Address == 1)
	{
		Pin = Pin - 32;
		SET_BIT(NVIC->EN[1], Pin);
	}
	else if(Reg_Address == 2)
	{
		Pin = Pin - 64;
		SET_BIT(NVIC->EN[2], Pin);
	}
	else if(Reg_Address == 3)
	{
		Pin = Pin - 96;
		SET_BIT(NVIC->EN[3], Pin);
	}
	else if(Reg_Address == 4)
	{
		Pin = Pin - 128;
		SET_BIT(NVIC->EN[4], Pin);
	}

}
void NVIC_voidDisableInterrupt(NVIC_IRQ_Type IRQ_Type)
{
		uint8 Reg_Address = IRQ_Type / 32 ;
		uint8 Pin = IRQ_Type % 32 ;

		if(Reg_Address == 0)
		{
			NVIC->DIS[0] = 1 << Pin ;
		}
		else if(Reg_Address == 1 )
		{
			Pin = Pin - 32 ;
			NVIC->DIS[1] = 1 << Pin ;
		}
		else if (Reg_Address == 2 )
		{
			Pin = Pin - 64 ;
			NVIC->DIS[2] = 1 << Pin ;
		}
		else if (Reg_Address == 3 )
		{
			Pin = Pin - 96 ;
			NVIC->DIS[3] = 1 << Pin ;
		}
		else if (Reg_Address == 4 )
		{
			Pin = Pin - 128 ;
			NVIC->DIS[4] = 1 << Pin ;
		}
		
}
 
void NVIC_voidSetPendingFlag(NVIC_IRQ_Type IRQ_Type) 
{
	uint8 Reg_Address = IRQ_Type / 32;
	uint8 Pin = IRQ_Type % 32;
	
	if(Reg_Address == 0)
	{
		SET_BIT(NVIC->PEND[0], Pin);
	}
	else if(Reg_Address == 1)
	{
		Pin = Pin - 32;
		SET_BIT(NVIC->PEND[1], Pin);
	}
	else if(Reg_Address == 2)
	{
		Pin = Pin - 64;
		SET_BIT(NVIC->PEND[2], Pin);
	}
	else if(Reg_Address == 3)
	{
		Pin = Pin - 96;
		SET_BIT(NVIC->PEND[3], Pin);
	}
	else if(Reg_Address == 4)
	{
		Pin = Pin - 128;
		SET_BIT(NVIC->PEND[4], Pin);
	}
	
}
	
		
void NVIC_voidClearPendingFlag(NVIC_IRQ_Type IRQ_Type)
{
	uint8 Reg_Address = IRQ_Type / 32;
	uint8 Pin = IRQ_Type % 32;
	if(Reg_Address == 0)
	{
		SET_BIT(NVIC->UNPEND[0], Pin);
	}
	else if(Reg_Address == 1)
	{
		Pin = Pin - 32;
		SET_BIT(NVIC->UNPEND[1], Pin);
	}
	else if(Reg_Address == 2)
	{
		Pin = Pin - 64;
		SET_BIT(NVIC->UNPEND[2], Pin);
	}
	else if(Reg_Address == 3)
	{
		Pin = Pin - 96;
		SET_BIT(NVIC->UNPEND[3], Pin);
	}
	else if(Reg_Address == 4)
	{
		Pin = Pin - 128;
		SET_BIT(NVIC->UNPEND[4], Pin);
	}
	
}

void NVIC_voidTriggerInterrupt(NVIC_IRQ_Type IRQ_Type)
{
	NVIC_SWTRIG = 0;
	NVIC_SWTRIG = IRQ_Type;
}

NVIC_IRQ_State NVIC_u8GetActiveFlag(NVIC_IRQ_Type IRQ_Type)
{
	uint8 Reg_Address = IRQ_Type / 32;
	uint8 Pin = IRQ_Type % 32;
	NVIC_IRQ_State State = DISABLE;
	
	if(Reg_Address == 0)
	{
		State = GET_BIT(NVIC->ACTIVE[0], Pin);
	}
	else if(Reg_Address == 1)
	{
		Pin = Pin - 32;
		State = GET_BIT(NVIC->ACTIVE[1], Pin);
	}
	else if(Reg_Address == 2)
	{
		Pin = Pin - 64;
		State = GET_BIT(NVIC->ACTIVE[2], Pin);
	}
	else if(Reg_Address == 3)
	{
		Pin = Pin - 96;
		State = GET_BIT(NVIC->ACTIVE[3], Pin);
	}
	else if(Reg_Address == 4)
	{
		Pin = Pin - 128;
		State = GET_BIT(NVIC->ACTIVE[4], Pin);
	}
	
	return State;
}

static void change_irq_state ( NVIC_IRQ_Type IRQ_type , NVIC_IRQ_State state )
{
	if ( state == ENABLE )
	{
		NVIC_voidEnableInterrupt ( IRQ_type );
	}
	else if ( state == DISABLE )
	{
		NVIC_voidDisableInterrupt ( IRQ_type );
	}
}

static void SCB_void_setNVICpriority ( void)
{
	SCB_APINT = ( 0x05FA0000 | (SET_PRIORITY<<8)) ;
}

void NVIC_voidInit(NVIC_Config_Type * config_ptr)
{
	uint8 Index = 0;
	SCB_void_setNVICpriority();
	
	for(Index = 0; Index < TOTAL_NUM_OF_IRQs; Index++)
	{
		change_irq_state(config_ptr[Index].IRQ_Num , config_ptr[Index].IRQ_State);
		
		NVIC->PRI[config_ptr[Index].IRQ_Num] = ((config_ptr[Index].IRQ_Priority) << 5);
	}
	
}