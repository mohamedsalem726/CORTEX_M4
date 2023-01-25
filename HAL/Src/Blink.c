/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: Blink.c
 *       Module: Blink Led
 * 
 *   Description: Source file for blinking led Module 
 * 
 ***************************************************************************************/
 
 #include "Std_Types.h"
 
 #include "Blink.h"
 
 static uint8 Flag_SysTick;
 extern const Pin_Config_Type PIN_ARR[3];
 extern const NVIC_Config_Type NVIC_Configurition[78];
 
 void Func(void)
{
	Flag_SysTick++;
	SYSTICK_voidDelayOneSec();
}
		
 
void Blink_voidLedInit(void)
{
	RCC_voidEnableSysClock();
	GPIO_voidInit(PIN_ARR);
	NVIC_voidInit(NVIC_Configurition);
	
	SYSTICK_SetCallBack(Func);
	SYSTICK_voidDelayOneSec();
	
}	
 
void Blink_voidLedRunnable(Port_Type Port, Pin_Type Pin, uint8 TimeOn, uint8 TimeOff)
{
	static uint8 LED_Flag = 0;
	if(LED_Flag == 0)
	{
		GPIO_voidWritePin(Port , Pin , HIGH);
		if(Flag_SysTick == TimeOn)
		{
			Flag_SysTick = 0;
			LED_Flag = 1;
		}
	}
	else if(LED_Flag == 1)
	{
		GPIO_voidWritePin(Port , Pin , LOW);
		if(Flag_SysTick == TimeOff)
		{
			Flag_SysTick = 0;
			LED_Flag = 0;
		}
	}
}