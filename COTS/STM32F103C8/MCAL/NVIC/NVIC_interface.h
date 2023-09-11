/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/



#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
#include "STD_TYPES.h"


typedef u8      IRQn_Type;


#define NONE            ((INVALID_VALUE)-1) 

typedef enum In;

Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn);                   //Enables an interrupt or exception.//IRQ=Interrupt Request


Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn);                   //Disables an interrupt or exception.


Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn);               //Sets the pending status of interrupt or exception to 1.


Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn);             //Clears the pending status of interrupt or exception to 0.


Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag); //Reads the pending status of interrupt or exception. This function returns non-zero value if the pending status is set to 1.


Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn, u32 Copy_Priority);//Sets the priority of an interrupt or exception with configurable priority level to 1


Std_ReturnType MCAL_NVIC_vSetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority);


Std_ReturnType MCAL_NVIC_xGetPriority(IRQn_Type IRQn, u8 *Copy_Priority);   //Reads the priority of an interrupt or exception with configurable priority level. This function return the current priority level.



#endif