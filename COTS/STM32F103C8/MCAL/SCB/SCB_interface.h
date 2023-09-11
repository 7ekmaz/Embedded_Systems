/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/


#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_



void SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping);


void DisableGlobalInterrupts(void); 


void EnableGlobalInterrupts(void);


void SCB_EnableMemFault(void);


void SCB_EnableBusFault(void);


void SCB_EnableUsageFault(void);


void SCB_ClearMemFault(void);



void SCB_ClearBusFault(void);


void SCB_ClearUsageFault(void);










#endif 