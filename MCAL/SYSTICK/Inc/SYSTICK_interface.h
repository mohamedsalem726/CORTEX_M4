/****************************************************************************************
 *   FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------
 *         File: SYSTICK_interface.h
 *       Module: System Tick Timer
 * 
 *   Description: Header file for System Tick Timer Control Module Types
 * 
 ***************************************************************************************/
 
 #ifndef SYSTICK_INTERFACE_H_
 #define SYSTICK_INTERFACE_H_
 
 void SYSTICK_voidDelayOneSec(void);
 
 void SYSTICK_SetCallBack(void (*Local_pFunc)(void));
 
 #endif /* SYSTICK_INTERFACE_H_ */