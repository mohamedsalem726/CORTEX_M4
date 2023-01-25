/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: GPIO_interface.h
 *       Module: General Purpose Input Output
 * 
 *   Description: Header file for GPIO Module Types
 * 
 ***************************************************************************************/
 
 #ifndef GPIO_INTERFACE_H_
 #define GPIO_INTERFACE_H_
 
 #include "Std_Types.h"
 
 typedef enum
 {
	 PIN0,
	 PIN1,
	 PIN2,
	 PIN3,
	 PIN4,
	 PIN5,
	 PIN6,
	 PIN7
 }Pin_Type;
 
 typedef enum
 {
	 PORTA,
	 PORTB,
	 PORTC,
	 PORTD,
	 PORTE,
	 PORTF
 }Port_Type;
 
 typedef uint8 Port_Level_Type;
 
 typedef enum
 {
	 LOW,
	 HIGH
 }Pin_Level_Type;
 
 typedef enum
 {
	 INPUT,
	 OUTPUT
 }Pin_Diresction_Type;
 
 typedef enum
 {
	 PULLUP,
	 PULLDOWN, 
	 OPEN_DRAIN
 }Pin_Internal_Attach_Type;
 
 typedef enum
 {
	 DIO,
	 TIMER,
	 UART,
	 I2C,
	 PWM,
	 ADC,
	 CAN,
	 WDT,
	 SSI
}Pin_Mode_Type;
 
typedef enum
{
	MA_AMPERE_2,
	MA_AMPERE_4,
	MA_AMPERE_8
}Pin_Output_Current_Type;

typedef struct
{
	Port_Type Port;
	Pin_Type Pin;
	Pin_Mode_Type Mode;
	Pin_Level_Type Level_Value;
	Pin_Diresction_Type Direction;
	Pin_Internal_Attach_Type Attach;
	Pin_Output_Current_Type Current;
}Pin_Config_Type;

void GPIO_voidInit(Pin_Config_Type* Config_ptr);

Pin_Level_Type GPIO_u8ReadPin(Port_Type Port,Pin_Type Pin);

void GPIO_voidWritePin(Port_Type Port,Pin_Type Pin ,Pin_Level_Type Level);

void GPIO_voidWritePort(Port_Type Port,Port_Level_Type Level);

Pin_Level_Type GPIO_u8FlipPin(Port_Type Port,Pin_Type Pin);
 
 
 
 #endif /* GPIO_INTERFACE_H_ */