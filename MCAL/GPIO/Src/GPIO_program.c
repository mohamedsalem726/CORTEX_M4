 /****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: GPIO_program.c
 *       Module: General Purpose Input Output
 * 
 *   Description: Source file for GPIO Module Types
 * 
 ***************************************************************************************/
 
 
 #include "Std_Types.h"
 #include "Bit_Math.h"
 
 #include "GPIO_interface.h"
 #include "GPIO_private.h"
 #include "GPIO_Pconfig.h"
 
 
 void GPIO_voidInit(Pin_Config_Type* Config_ptr)
 {
	 uint8 Index = 0;
	 uint8 PIN;
	 /* Enable the clock for the GPIO */
	 SET_BIT(RCGCGPIO,0);
	 SET_BIT(RCGCGPIO,1);
	 SET_BIT(RCGCGPIO,2);
	 SET_BIT(RCGCGPIO,3);
	 SET_BIT(RCGCGPIO,4);
	 SET_BIT(RCGCGPIO,5);
	 
	 for(Index = 0; Index<TOTAL_PINS_NUM ; Index++)
	 {
		 PIN = Config_ptr[Index].Pin;
		 
		 switch(Config_ptr[Index].Port)
		 {
			 case PORTA:
				 /* Unlock Port A */
				 REG(GPIOA+GPIOLOCK) = GPIOLOCK_KEY;
				 REG(GPIOA+GPIOCR) = 0xFF;
				 /* Setting Pin Direction */
				 CLR_BIT(REG(GPIOA+GPIODIR),PIN);
				 REG(GPIOA+GPIODIR) |= (Config_ptr[Index].Direction)<<PIN;
				 /* Enable Digital */
				 SET_BIT(REG(GPIOA+GPIODEN),PIN);
				 /* Setting the Ampere */
				 switch(Config_ptr[Index].Current)
				 {
					 case MA_AMPERE_2: SET_BIT(REG(GPIOA+GPIODR2R),PIN); break;
					 case MA_AMPERE_4: SET_BIT(REG(GPIOA+GPIODR4R),PIN); break;
					 case MA_AMPERE_8: SET_BIT(REG(GPIOA+GPIODR8R),PIN); break;
				 }
				 /* Setting Pull Attach Type */
				 switch(Config_ptr[Index].Attach)
				 {
					 case OPEN_DRAIN: SET_BIT(REG(GPIOA+GPIOODR),PIN); CLR_BIT(REG(GPIOA+GPIOPUR),PIN); CLR_BIT(REG(GPIOA+GPIOPDR),PIN); break;
					 case PULLDOWN  : CLR_BIT(REG(GPIOA+GPIOODR),PIN); SET_BIT(REG(GPIOA+GPIOPDR),PIN); break;
					 case PULLUP    : CLR_BIT(REG(GPIOA+GPIOODR),PIN); SET_BIT(REG(GPIOA+GPIOPUR),PIN); break;
				 }
				 /* Setting Initial Level Value */
				 CLR_BIT(REG(GPIOA+GPIODATA),PIN);
				 REG(GPIOA+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN); 
				 /* Setting Mode */
				 switch(PIN)
				 {
					 case PIN0:
						 if(Config_ptr[Index].Mode == UART)
						 {
							 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							 REG(GPIOA+GPIOPCTL) |= 0x1;
						 }
						 else if(Config_ptr[Index].Mode == CAN)
						 {
							 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							 REG(GPIOA+GPIOPCTL) |= 0x8;
						 }
						break;
					 case PIN1:
						 if(Config_ptr[Index].Mode == UART)
						 {
							 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							 REG(GPIOA+GPIOPCTL) |= 0x1 << 4;
						 }
						 else if(Config_ptr[Index].Mode == CAN)
						 {
							 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							 REG(GPIOA+GPIOPCTL) |= 0x8 << 4;
						 }
						break;
					 case PIN2:
						 if(Config_ptr[Index].Mode == SSI )
						 {
							 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							 REG(GPIOA+GPIOPCTL) |= 0x2 << 8;
						 }
					  break;
				   case PIN3:
					   if(Config_ptr[Index].Mode == SSI )
						{
							SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							REG(GPIOA+GPIOPCTL) |= 0x2 << 12;
						}
					 break;
				  case PIN4:
				   if(Config_ptr[Index].Mode == SSI )
					 {
						 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
						 REG(GPIOA+GPIOPCTL) |= 0x2 << 16 ;
					 }
					break;
				 case PIN5:
					 if(Config_ptr[Index].Mode == SSI )
					 {
						 SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
						 REG(GPIOA+GPIOPCTL) |= 0x2 << 20 ;
					 }
					break;
				 case PIN6:
					 if(Config_ptr[Index].Mode == I2C )
					 {
							SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							REG(GPIOA+GPIOPCTL) |= 0x3 << 24 ;
					 }
					 else if(Config_ptr[Index].Mode == PWM  )
					 {
							SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
							REG(GPIOA+GPIOPCTL) |= 0x5 << 24 ;
			     }
				  break;
				 case PIN7:
					if(Config_ptr[Index].Mode == I2C )
					{
						SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
						REG(GPIOA+GPIOPCTL) |= 0x3 << 28 ;
					}
					else if(Config_ptr[Index].Mode == PWM  )
					{
						SET_BIT(REG(GPIOA+GPIOAFSEL),PIN);
						REG(GPIOA+GPIOPCTL) |= 0x5 << 28 ;
					}
			   break ;
			}
		 break;
	  case PORTB:
	 	/* Unlocking GPIOB */
 	 	REG(GPIOB+GPIOLOCK) = GPIOLOCK_KEY ;
	 	REG(GPIOB+GPIOCR) = 0xff;
	 	/* Setting Pin Direction */
	 	CLR_BIT(REG(GPIOB+GPIODIR),PIN);
	 	REG(GPIOB+GPIODIR) |= (Config_ptr[Index].Direction)<<PIN ;
	 	/* Enable Digital */
	 	SET_BIT(REG(GPIOB+GPIODEN),PIN);
	 	/* Setting Ampere */
	 	switch (Config_ptr[Index].Current)
	 	{
	 		case MA_AMPERE_2: SET_BIT(REG(GPIOB+GPIODR2R),PIN); break;
	 		case MA_AMPERE_4: SET_BIT(REG(GPIOB+GPIODR4R),PIN); break;
	 		case MA_AMPERE_8: SET_BIT(REG(GPIOB+GPIODR8R),PIN); break;
	 	}
	 	/* Setting Pull Attach Type */
	 	switch (Config_ptr[Index].Attach)
	 	{
	 		case OPEN_DRAIN: SET_BIT(REG(GPIOB+GPIOODR),PIN); CLR_BIT(REG(GPIOB+GPIOPUR),PIN); CLR_BIT(REG(GPIOB+GPIOPDR),PIN); break;
	 		case PULLDOWN  : CLR_BIT(REG(GPIOB+GPIOODR),PIN); SET_BIT(REG(GPIOB+GPIOPDR),PIN); break;
	 		case PULLUP    : CLR_BIT(REG(GPIOB+GPIOODR),PIN); SET_BIT(REG(GPIOB+GPIOPUR),PIN); break;
	 	}
	 	/* Setting Initial Level Value */
	 	CLR_BIT(REG(GPIOB+GPIODATA),PIN) ;
	 	REG(GPIOB+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN) ;
	 	/* setting mode */
	 switch (PIN)
	 {
	 case PIN0:
	 	if(Config_ptr[Index].Mode == UART )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x1 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 ;
	 	}
	 	break;
	 case PIN1:
	 	if(Config_ptr[Index].Mode == UART )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x1 << 4 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 4;
	 	}
	 	break;
	 case PIN2:
	 	if(Config_ptr[Index].Mode == I2C )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x3 << 8;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 8;
	 	}
	 	break;
	 case PIN3:
	 	if(Config_ptr[Index].Mode == I2C )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x3 << 12;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 12;
	 	}
	 	break;
	 case PIN4:
	 	if ( Config_ptr[Index].Mode == SSI )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x2 << 16 ;
	 	}
	 	else if(Config_ptr[Index].Mode == PWM )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x4 << 16 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 16 ;
	 	}
	 	else if(Config_ptr[Index].Mode == CAN )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x8 << 16 ;
	 	}
	 	break;
	 case PIN5:
	 	if(Config_ptr[Index].Mode == SSI )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x2 << 20 ;
	 	}
	 	else if(Config_ptr[Index].Mode == PWM )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x4 << 20 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 20 ;
	 	}
	 	else if(Config_ptr[Index].Mode == CAN )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x8 << 20 ;
	 	}
	 	break;
	 case PIN6:
	 	if(Config_ptr[Index].Mode == SSI )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x2 << 24 ;
	 	}
	 	else if(Config_ptr[Index].Mode == PWM )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x4 << 24 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 24 ;
	 	}
	 	break;
	 case PIN7:
	 	if(Config_ptr[Index].Mode == SSI )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x2 << 28 ;
	 	}
	 	else if(Config_ptr[Index].Mode == PWM )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x4 << 28 ;
	 	}
	 	else if(Config_ptr[Index].Mode == TIMER )
	 	{
	 		SET_BIT(REG(GPIOB+GPIOAFSEL),PIN);
	 		REG(GPIOB+GPIOPCTL) |= 0x7 << 28 ;
	 	}
	 	break;
	 }
	 break; 
	 case PORTC:
		 /* Unlock GPIOC */
		 REG(GPIOC+GPIOLOCK) = GPIOLOCK_KEY;
		 REG(GPIOC+GPIOCR) = 0xFF;
		 /* Setting Pin Direction */
		 CLR_BIT(REG(GPIOC+GPIODIR),PIN);
		 REG(GPIOC+GPIODIR) |= ((Config_ptr[Index].Direction)<<PIN);
		 /* Enable Digital */
		 SET_BIT(REG(GPIOC+GPIODEN),PIN);
		 /* Setting Ampere */
		 switch(Config_ptr[Index].Current)
		 {
			 case MA_AMPERE_2: SET_BIT(REG(GPIOC+GPIODR2R),PIN); break;
			 case MA_AMPERE_4: SET_BIT(REG(GPIOC+GPIODR4R),PIN); break;
			 case MA_AMPERE_8: SET_BIT(REG(GPIOC+GPIODR8R),PIN); break;
		 }
		 /* Setting Pull Attach type */
		 switch(Config_ptr[Index].Attach)
		 {
			 case OPEN_DRAIN: SET_BIT(REG(GPIOC+GPIOODR),PIN); CLR_BIT(REG(GPIOC+GPIOPUR),PIN); CLR_BIT(REG(GPIOC+GPIOPDR),PIN); break;
			 case PULLDOWN: CLR_BIT(REG(GPIOC+GPIOODR),PIN); SET_BIT(REG(GPIOC+GPIOPDR),PIN); break;
			 case PULLUP: CLR_BIT(REG(GPIOC+GPIOODR),PIN); SET_BIT(REG(GPIOC+GPIOPUR),PIN); break;
		 }
		 /* Settinh Initial level Value */
		 CLR_BIT(REG(GPIOC+GPIODATA),PIN);
		 REG(GPIOC+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN);
		 /* Setting Mode */
		 switch(PIN)
		 {
			 case PIN0:
				 if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7;
				 }
				 break;
			 case PIN1:
				 if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<4;
				 }
				 break;
			 case PIN2:
				 if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7 <<8;
				 }
				 break;
			 case PIN3:
				 if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<12;
				 }
				 break;
			 case PIN4:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x1<<16;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x4<<16;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<16;
				 }
				 break;
			 case PIN5:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x1<<20;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x4<<20;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<20;
				 }
				 break;
			 case PIN6:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x1<<24;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<24;
				 }
				 break;
			 case PIN7:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x1<<28;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x7<<28;
				 }
				 break;
			 }
		 break;
			 case PORTD:
		 /* Unlock GPIOD */
		 REG(GPIOD+GPIOLOCK) = GPIOLOCK_KEY;
		 REG(GPIOD+GPIOCR) = 0xFF;
		 /* Setting Pin Direction */
		 CLR_BIT(REG(GPIOD+GPIODIR),PIN);
		 REG(GPIOD+GPIODIR) |= ((Config_ptr[Index].Direction)<<PIN);
		 /* Enable Digital */
		 SET_BIT(REG(GPIOD+GPIODEN),PIN);
		 /* Setting Ampere */
		 switch(Config_ptr[Index].Current)
		 {
			 case MA_AMPERE_2: SET_BIT(REG(GPIOD+GPIODR2R),PIN); break;
			 case MA_AMPERE_4: SET_BIT(REG(GPIOD+GPIODR4R),PIN); break;
			 case MA_AMPERE_8: SET_BIT(REG(GPIOD+GPIODR8R),PIN); break;
		 }
		 /* Setting Pull Attach type */
		 switch(Config_ptr[Index].Attach)
		 {
			 case OPEN_DRAIN: SET_BIT(REG(GPIOD+GPIOODR),PIN); CLR_BIT(REG(GPIOD+GPIOPUR),PIN); CLR_BIT(REG(GPIOD+GPIOPDR),PIN); break;
			 case PULLDOWN: CLR_BIT(REG(GPIOD+GPIOODR),PIN); SET_BIT(REG(GPIOD+GPIOPDR),PIN); break;
			 case PULLUP: CLR_BIT(REG(GPIOD+GPIOODR),PIN); SET_BIT(REG(GPIOD+GPIOPUR),PIN); break;
		 }
		 /* Settinh Initial level Value */
		 CLR_BIT(REG(GPIOD+GPIODATA),PIN);
		 REG(GPIOD+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN);
		 /* Setting Mode */
		 switch(PIN)
		 {
			 case PIN0:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1;
				 }
				 else if(Config_ptr[Index].Mode == I2C)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x3;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x4;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7;
				 }
				 break;
			 case PIN1:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<4;
				 }
				 else if(Config_ptr[Index].Mode == I2C)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x3<<4;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x4<<4;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<4;
				 }
				 break;
			 case PIN2:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<8;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x4<<8;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<8;
				 }
				 break;
			 case PIN3:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<12;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<12;
				 }
				 break;
			 case PIN4:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<16;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<16;
				 }
				 break;
			 case PIN5:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOC+GPIOAFSEL),PIN);
					 REG(GPIOC+GPIOPCTL) |= 0x1<<20;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<20;
				 }
				 break;
			 case PIN6:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<24;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<24;
				 }
				 break;
			 case PIN7:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x1<<28;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOD+GPIOAFSEL),PIN);
					 REG(GPIOD+GPIOPCTL) |= 0x7<<28;
				 }
				 break;
			 }
		 break;
			 case PORTE:
		 /* Unlock GPIOE */
		 REG(GPIOE+GPIOLOCK) = GPIOLOCK_KEY;
		 REG(GPIOE+GPIOCR) = 0xFF;
		 /* Setting Pin Direction */
		 CLR_BIT(REG(GPIOE+GPIODIR),PIN);
		 REG(GPIOE+GPIODIR) |= ((Config_ptr[Index].Direction)<<PIN);
		 /* Enable Digital */
		 SET_BIT(REG(GPIOE+GPIODEN),PIN);
		 /* Setting Ampere */
		 switch(Config_ptr[Index].Current)
		 {
			 case MA_AMPERE_2: SET_BIT(REG(GPIOE+GPIODR2R),PIN); break;
			 case MA_AMPERE_4: SET_BIT(REG(GPIOE+GPIODR4R),PIN); break;
			 case MA_AMPERE_8: SET_BIT(REG(GPIOE+GPIODR8R),PIN); break;
		 }
		 /* Setting Pull Attach type */
		 switch(Config_ptr[Index].Attach)
		 {
			 case OPEN_DRAIN: SET_BIT(REG(GPIOE+GPIOODR),PIN); CLR_BIT(REG(GPIOE+GPIOPUR),PIN); CLR_BIT(REG(GPIOE+GPIOPDR),PIN); break;
			 case PULLDOWN: CLR_BIT(REG(GPIOE+GPIOODR),PIN); SET_BIT(REG(GPIOE+GPIOPDR),PIN); break;
			 case PULLUP: CLR_BIT(REG(GPIOE+GPIOODR),PIN); SET_BIT(REG(GPIOE+GPIOPUR),PIN); break;
		 }
		 /* Settinh Initial level Value */
		 CLR_BIT(REG(GPIOE+GPIODATA),PIN);
		 REG(GPIOE+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN);
		 /* Setting Mode */
		 switch(PIN)
		 {
			 case PIN0:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x1;
				 }
				 break;
			 case PIN1:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x1<<4;
				 }
				 break;
			 case PIN2:
				 break;
			 case PIN3:
				 break;
			 case PIN4:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x1<<16;
				 }
				 else if(Config_ptr[Index].Mode == I2C)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x3<<16;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x4<<16;
				 }
				 else if(Config_ptr[Index].Mode == CAN)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x8<<16;
				 }
				 break;
			 case PIN5:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x1<<20;
				 }
				 else if(Config_ptr[Index].Mode == I2C)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x3<<20;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x4<<20;
				 }
				 else if(Config_ptr[Index].Mode == CAN)
				 {
					 SET_BIT(REG(GPIOE+GPIOAFSEL),PIN);
					 REG(GPIOE+GPIOPCTL) |= 0x8<<20;
				 }
				 break;
			 }
		 break;
			 case PORTF:
		 /* Unlock GPIOF */
		 REG(GPIOF+GPIOLOCK) = GPIOLOCK_KEY;
		 REG(GPIOF+GPIOCR) = 0xFF;
		 /* Setting Pin Direction */
		 CLR_BIT(REG(GPIOF+GPIODIR),PIN);
		 REG(GPIOF+GPIODIR) |= ((Config_ptr[Index].Direction)<<PIN);
		 /* Enable Digital */
		 SET_BIT(REG(GPIOF+GPIODEN),PIN);
		 /* Setting Ampere */
		 switch(Config_ptr[Index].Current)
		 {
			 case MA_AMPERE_2: SET_BIT(REG(GPIOF+GPIODR2R),PIN); break;
			 case MA_AMPERE_4: SET_BIT(REG(GPIOF+GPIODR4R),PIN); break;
			 case MA_AMPERE_8: SET_BIT(REG(GPIOF+GPIODR8R),PIN); break;
		 }
		 /* Setting Pull Attach type */
		 switch(Config_ptr[Index].Attach)
		 {
			 case OPEN_DRAIN: SET_BIT(REG(GPIOF+GPIOODR),PIN); CLR_BIT(REG(GPIOF+GPIOPUR),PIN); CLR_BIT(REG(GPIOF+GPIOPDR),PIN); break;
			 case PULLDOWN: CLR_BIT(REG(GPIOF+GPIOODR),PIN); SET_BIT(REG(GPIOF+GPIOPDR),PIN); break;
			 case PULLUP: CLR_BIT(REG(GPIOF+GPIOODR),PIN); SET_BIT(REG(GPIOF+GPIOPUR),PIN); break;
		 }
		 /* Settinh Initial level Value */
		 CLR_BIT(REG(GPIOF+GPIODATA),PIN);
		 REG(GPIOF+GPIODATA) |= ((Config_ptr[Index].Level_Value)<<PIN);
		 /* Setting Mode */
		 switch(PIN)
		 {
			 case PIN0:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x1;
				 }
				 else if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x2;
				 }
				 else if(Config_ptr[Index].Mode == CAN)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x3;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x5;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x7;
				 }
				 break;
			 case PIN1:
				 if(Config_ptr[Index].Mode == UART)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x1<<4;
				 }
				 else if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x2<<4;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x5<<4;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x7<<4;
				 }
				 break;
			 case PIN2:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x2<<8;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x5<<8;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x7<<8;
				 }
				 break;
			 case PIN3:
				 if(Config_ptr[Index].Mode == SSI)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x2<<16;
				 }
				 else if(Config_ptr[Index].Mode == CAN)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x3<<16;
				 }
				 else if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x5<<16;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x7<<16;
				 }
				 break;
			 case PIN4:
				 if(Config_ptr[Index].Mode == PWM)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x5<<20;
				 }
				 else if(Config_ptr[Index].Mode == TIMER)
				 {
					 SET_BIT(REG(GPIOF+GPIOAFSEL),PIN);
					 REG(GPIOF+GPIOPCTL) |= 0x7<<20;
				 }
				 break;
			 }
		 break;	 
		 }
	 }		 
 }

Pin_Level_Type GPIO_u8ReadPin(Port_Type Port,Pin_Type Pin)
{
		Pin_Level_Type Local_u8Result = LOW;
	 
		switch(Port)
		{
			case PORTA:
				Local_u8Result = GET_BIT(REG(GPIOA+GPIODATA),Pin);
			break;
			case PORTB:
				Local_u8Result = GET_BIT(REG(GPIOB+GPIODATA),Pin);
			break;
			case PORTC: 
				Local_u8Result = GET_BIT(REG(GPIOC+GPIODATA),Pin);
			break;
			case PORTD: 
				Local_u8Result = GET_BIT(REG(GPIOD+GPIODATA),Pin);
			break;
			case PORTE: 
				Local_u8Result = GET_BIT(REG(GPIOE+GPIODATA),Pin);
			break;
			case PORTF: 
				Local_u8Result = GET_BIT(REG(GPIOF+GPIODATA),Pin);
			break;
		}
		return Local_u8Result;
 }

void GPIO_voidWritePin(Port_Type Port , Pin_Type Pin , Pin_Level_Type Level)
{
	if(Level == HIGH)
	{
			switch(Port)
			{
				case PORTA:
					SET_BIT(REG(GPIOA+GPIODATA),Pin);
				break;
				case PORTB:
					SET_BIT(REG(GPIOB+GPIODATA),Pin);
				break;
				case PORTC:
					SET_BIT(REG(GPIOC+GPIODATA),Pin);
				break;
				case PORTD:
					SET_BIT(REG(GPIOD+GPIODATA),Pin);
				break;
				case PORTE:
					SET_BIT(REG(GPIOE+GPIODATA),Pin);
				break;
				case PORTF:
					SET_BIT(REG(GPIOF+GPIODATA),Pin);
				break;
			}
	}
	else if(Level == LOW)
	{
		switch(Port)
			{
				case PORTA:
					CLR_BIT(REG(GPIOA+GPIODATA),Pin);
				break;
				case PORTB:
					CLR_BIT(REG(GPIOB+GPIODATA),Pin);
				break;
				case PORTC:
					CLR_BIT(REG(GPIOC+GPIODATA),Pin);
				break;
				case PORTD:
					CLR_BIT(REG(GPIOD+GPIODATA),Pin);
				break;
				case PORTE:
					CLR_BIT(REG(GPIOE+GPIODATA),Pin);
				break;
				case PORTF:
					CLR_BIT(REG(GPIOF+GPIODATA),Pin);
				break;
			}
	}
		
}

void GPIO_voidWritePort(Port_Type Port , Port_Level_Type Level)
{
		switch(Port)
		{
			case PORTA:
				REG(GPIOA+GPIODATA) = Level;
			break;
			case PORTB:
				REG(GPIOB+GPIODATA) = Level;
			break;
			case PORTC:
				REG(GPIOC+GPIODATA) = Level;
			break;
			case PORTD:
				REG(GPIOD+GPIODATA) = Level;
			break;
			case PORTE:
				REG(GPIOE+GPIODATA) = Level;
			break;
			case PORTF:
				REG(GPIOF+GPIODATA) = Level;
			break;
		}
			
}

Pin_Level_Type GPIO_u8FlipPin(Port_Type Port , Pin_Type Pin)
{
	Pin_Level_Type Local_u8Result;
	
	switch(Port)
	{
		case PORTA:
			TOGGLE_BIT(REG(GPIOA+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOA+GPIODATA),Pin);
		break;
		case PORTB:
			TOGGLE_BIT(REG(GPIOB+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOB+GPIODATA),Pin);
		break;
		case PORTC:
			TOGGLE_BIT(REG(GPIOC+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOC+GPIODATA),Pin);
		break;
		case PORTD:
			TOGGLE_BIT(REG(GPIOD+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOD+GPIODATA),Pin);
		break;
		case PORTE:
			TOGGLE_BIT(REG(GPIOE+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOE+GPIODATA),Pin);
		break;
		case PORTF:
			TOGGLE_BIT(REG(GPIOF+GPIODATA),Pin);
			Local_u8Result = GET_BIT(REG(GPIOF+GPIODATA),Pin);
		break;
	}
	return Local_u8Result;
}