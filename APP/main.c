

#include "Std_Types.h"
#include "Bit_Math.h"

#include "GPIO_interface.h"
#include "Blink.h"


int main(void)
{
	static uint8 OnTime=2;
	static uint8 OffTime=2;
	Blink_voidLedInit();
	
	if((GPIO_u8ReadPin(PORTB,PIN0)) == 1)
		{
			OnTime++;
			OffTime--;
			if(OffTime == 0)
			{
				OffTime = 1;
			}
		}
		else if((GPIO_u8ReadPin(PORTB,PIN1)) == 1)
		{
			OffTime++;
			OnTime--;
			if(OnTime == 0)
			{
				OnTime = 1;
			}
		}
	while(1)
	{
		Blink_voidLedRunnable(PORTA , PIN0 , OnTime,OffTime);
	}
	
	return 0;
}