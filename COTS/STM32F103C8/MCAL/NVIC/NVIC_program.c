/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/



/************************<<LIB************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"




/************************<<MCAL************************/
#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

#include "SCB_interface.h"


/*****************************< Function Implementations *****************************/

Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn)   //Enables an interrupt or exception.//IRQ=Interrupt Request
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    
    if(Copy_IRQn < 32)
    {
        NVIC_ISER0 = (1 << Copy_IRQn);             //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn <= 63)
    {
        NVIC_ISER1 = (1 << (Copy_IRQn - 32));      //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISER2 = (1 << (Copy_IRQn - 64));      //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
    
}



Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn)      //Disable an interrupt or exception.
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_IRQn < 32)
    {
        NVIC_ICER0 = (1 << Copy_IRQn);             //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICER1 = (1 << (Copy_IRQn - 32));      //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICER2 = (1 << (Copy_IRQn - 64));      //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}









Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)   //Sets the pending status of interrupt or exception to 1.
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(Copy_IRQn < 32)
    {
        NVIC_ISPR0 = (1 << Copy_IRQn);            //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ISPR1 = (1 << (Copy_IRQn - 32));     //Atomic Access
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ISPR2 = (1 << (Copy_IRQn - 64));     //Atomic Access
        Local_FunctionStatus = E_OK; 
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }
    
    return Local_FunctionStatus;
}















Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn)     //Clears the pending status of interrupt or exception to 0.

{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_IRQn < 32)
    {
        NVIC_ICPR0 = (1U << Copy_IRQn);
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
        NVIC_ICPR1 = (1U << (Copy_IRQn - 32));
        Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 96)
    {
        NVIC_ICPR2 = (1U << (Copy_IRQn - 64));
        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}




Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag)   // return pending value 1 or 0
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_ReturnPendingFlag != NULL)
    {
        /**< Check the pending flag based on the interrupt number */ 
        if (Copy_IRQn < 32)
        {
            /**< Check the bit corresponding to the interrupt */ 
            if (NVIC_ISPR0 & (1U << Copy_IRQn))             //OR Use Funtion (((GETBIT)))
            {
                *Copy_ReturnPendingFlag = 1;                   /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0;                   /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else if (Copy_IRQn < 64)
        {
            /**< Check the bit corresponding to the interrupt */ 
            if (NVIC_ISPR1 & (1U << (Copy_IRQn - 32)))
            {
                *Copy_ReturnPendingFlag = 1;                   /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0;                   /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else if(Copy_IRQn < 96)
        {   
            /**< Check the bit corresponding to the interrupt */
            if(NVIC_ISPR2 & (1U << (Copy_IRQn - 64)))
            {
                *Copy_ReturnPendingFlag = 1;                   /**< Set to 1 if the flag is pending */ 
            }
            else
            {
                *Copy_ReturnPendingFlag = 0;                   /**< Set to 0 if the flag is not pending */ 
            }
            Local_FunctionStatus = E_OK;
        }
        else
        {
            Local_FunctionStatus = E_NOT_OK;
        }
    }

    return Local_FunctionStatus;
}





















Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn, u32 Copy_Priority)          //Assume there is no (((NESTING)))//SetPriority for one peripheral with 0 Groups
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_IRQn < 0 || Copy_IRQn >= NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */ 
    {
        return Local_FunctionStatus;
    }

    if (Copy_Priority <= NVIC_MAX_PRIORITY) /**< Ensure the priority value is within the valid range (0-255) */ 
    {
        /**< Calculate the register index (IPRx) and bit position within the register */ 
        u8 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */  

        /**< Set the priority in the appropriate IPRx register */ 
        NVIC_IPR_BASE_ADDRESS[RegisterIndex] = (Copy_Priority << 4);
        
        /**< Set the group and sub-group priority for interrupt handling in SCB_AIRCR register */
        SCB_SetPriorityGrouping(NVIC_0GROUP_16SUB);

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_vSetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority)//Set the priority of the Desired Priority Grouping
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    u8 NVIC_MAX_Group_Priority;
    u8 NVIC_MAX_Sub_Priority;

    #if (PRIORITY_GROUPING == NVIC_16GROUP_0SUB)
        NVIC_MAX_Group_Priority = 15;
        NVIC_MAX_Sub_Priority = NONE;
    #elif (PRIORITY_GROUPING == NVIC_8GROUP_2SUB)
        NVIC_MAX_Group_Priority = 7;
        NVIC_MAX_Sub_Priority = 1;
    #elif (PRIORITY_GROUPING == NVIC_4GROUP_4SUB)
        NVIC_MAX_Group_Priority = 3;
        NVIC_MAX_Sub_Priority = 3;
    #elif (PRIORITY_GROUPING == NVIC_2GROUP_8SUB)
        NVIC_MAX_Group_Priority = 1;
        NVIC_MAX_Sub_Priority = 7;
    #elif (PRIORITY_GROUPING == NVIC_0GROUP_16SUB)
        NVIC_MAX_Group_Priority = NVIC_INVALID_PRIORITY;
        NVIC_MAX_Sub_Priority = 15;
    #else
        #error "Invalid PRIORITY_GROUPING value. Please choose from _16GROUP_SUB0, _8GROUP_SUB2, _4GROUP_SUB4, _2GROUP_SUB8, or _0GROUP_SUB16."
    #endif

    if (Copy_GroupPriority > NVIC_MAX_Group_Priority || Copy_SubPriority > NVIC_MAX_Sub_Priority)
    {
        /**< Invalid priority value */
        return Local_FunctionStatus;
    }

    u8 Local_Priority = (Copy_SubPriority | (Copy_GroupPriority << (PRIORITY_GROUPING - NVIC_16GROUP_0SUB) / 0x100));

    if (Copy_IRQn < 0 || Copy_IRQn >= NUMBER_OF_INTERRUPTS)
    {
        /**< Check if IRQn is within valid range */
        return Local_FunctionStatus;
    }

    /**< Calculate the register index (IPRx) and bit position within the register */
    u8 RegisterIndex = Copy_IRQn / 4; /* Divide by 4 to get the register index */

    /**< Set the priority in the appropriate IPRx register */
    NVIC_IPR_BASE_ADDRESS[RegisterIndex] = (Local_Priority << 4);

    /**< Configure the priority grouping for the Nested Vectored Interrupt Controller (NVIC) */
    SCB_SetPriorityGrouping(PRIORITY_GROUPING);

    return Local_FunctionStatus;
}
