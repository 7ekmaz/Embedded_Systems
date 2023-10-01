










/*****************************< LIB *****************************/
#include <stdbool.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*****************************< HAL *****************************/
#include "PushButton.h"
/*****************************< Function Implementations *****************************/
/**
 * @defgroup Public_Functions LED Driver
 * @{
 */

Std_ReturnType HAL_PushButton_Init(PushButton_Port_t Copy_ButtonPortId, PushButton_Pin_t Copy_ButtonPinId, PushButton_State_t Copy_ActiveLevel)
{
    if (Copy_ActiveLevel != ACTIVE_HIGH && Copy_ActiveLevel != ACTIVE_LOW) 
    {
        return E_NOT_OK; /**< Invalid pull-up/down configuration */
    }
    else
    {
        /**< Initialize Push Button to be input with pull-up or pull-down */
        #if(Copy_ActiveLevel == ACTIVE_LOW)
            Copy_ActiveLevel = GPIO_INPUT_PULL_UP_MOD;
            if(MCAL_GPIO_SetPinMode(Copy_ButtonPortId, Copy_ButtonPinId, Copy_ActiveLevel) == E_NOT_OK)
            {
                return E_NOT_OK; /**< GPIO initialization failed */
            }

            MCAL_GPIO_SetPinValue(Copy_ButtonPortId, Copy_ButtonPinId, GPIO_HIGH);

            return E_OK;

        #elif(Copy_ActiveLevel == ACTIVE_HIGH)
            Copy_ActiveLevel = GPIO_INPUT_PULL_DOWN;
            if(MCAL_GPIO_SetPinMode(Copy_ButtonPortId, Copy_ButtonPinId, Copy_ActiveLevel) == E_NOT_OK)
            {
                return E_NOT_OK; /**< GPIO initialization failed */
            }

            MCAL_GPIO_SetPinValue(Copy_ButtonPortId, Copy_ButtonPinId, GPIO_LOW);

            return E_OK;

        #else
            #error "Unexpected condition in HAL_PushButton_Init"            
        #endif
    }
}



/**
 * @} (End of Public_Functions) 
 */