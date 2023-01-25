/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: GPIO_priavte.h
 *       Module: General Purpose Input Output
 * 
 *   Description: Header file for GPIO Module Types
 * 
 ***************************************************************************************/
 
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
 
#define TOTAL_PINS_NUM     43
 
#define GPIOLOCK_KEY       0x4C4F434B

#define GPIOA              0x40004000
#define GPIOB              0x40005000
#define GPIOC              0x40006000
#define GPIOD              0x40007000
#define GPIOE              0x40024000
#define GPIOF              0x40025000

#define 	GPIODATA							 						 0x3FC
#define 	GPIODIR                        	 	 0x400
#define 	GPIOIS                          	 0x404
#define 	GPIOIBE                         	 0x408
#define 	GPIOIEV                         	 0x40C
#define 	GPIOIM                          	 0x410
#define 	GPIORIS                         	 0x414
#define 	GPIOMIS                         	 0x418
#define 	GPIOICR                         	 0x41C
#define 	GPIOAFSEL                       	 0x420
#define 	GPIODR2R                        	 0x500
#define 	GPIODR4R                        	 0x504
#define 	GPIODR8R                        	 0x508
#define 	GPIOODR                         	 0x50C
#define 	GPIOPUR                         	 0x510
#define 	GPIOPDR                       		 0x514
#define 	GPIOSLR                        		 0x518
#define 	GPIODEN                         	 0x51C
#define 	GPIOLOCK 					   		 					 0x520
#define 	GPIOCR                          	 0x524
#define 	GPIOAMSEL 					 	             0x528
#define 	GPIOPCTL	    					           0x52C
#define 	GPIOADCCTL                   	     0x530
#define 	GPIODMACTL              	         0x534
#define 	GPIOPeriphID4      		             0xFD0
#define 	GPIOPeriphID5 			       	       0xFD4
#define 	GPIOPeriphID6           	         0xFD8
#define 	GPIOPeriphID7      		             0xFDC
#define 	GPIOPeriphID0 	                   0xFE0
#define 	GPIOPeriphID1         	           0xFE4
#define 	GPIOPeriphID2    	                 0xFE8
#define 	GPIOPeriphID3                   	 0xFEC
#define 	GPIOPCellID0                   		 0xFF0
#define 	GPIOPCellID1             	         0xFF4
#define 	GPIOPCellID2        	             0xFF8
#define 	GPIOPCellID3  		                 0xFFC

#define RCGCGPIO                  *((volatile uint32*)0x400FE608)

#endif /* GPIO_PRIVATE_H_ */