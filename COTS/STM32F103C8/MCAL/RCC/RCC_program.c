/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/



/************************<<LIB************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"




/************************<<MCAL************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



Std_ReturnType Mcal_Rcc_InitSysClock(void)
{

    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK==RCC_HSE
        
        #if RCC_CLK_BYPASS==RCC_RC_CLK
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS==RCC_CRYSTAL_CLK
            CLR_BIT(RCC_CR,18);
        #else 
            #error"WRONG CHOICE !!!!!!"
        #endif

        /*Enable the HSE*/
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /*wait until the clock be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSERDY))

        /**Select the External clock to be the SYSTEM CLOCK*/
        RCC_CFGR=0x00000001;


Local_FunctionStatus=E_OK;
    #elif RCC_SYSCLK==RCC_HSI

        /*Enable the HSI*/
        SET_BIT(RCC_CR, RCC_CR_HSION );
        while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY))


        /*Select  the INTERNAL clock to be SYSTEM CLOCK*/
        RCC_CFGR=0x00000000;    

Local_FunctionStatus=E_OK;

    #elif RCC_SYSCLK==RCC_PLL
        SET_BIT(RCC_CR, RCC_CR_PLLON );
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY))

        RCC_CFGR=0x00000010l 


Local_FunctionStatus=E_OK;
    #else 
        #error"WRONG CHOICE !!!!!!"

    #endif

    return Local_FunctionStatus;
}






Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;

    switch(Copy_BusId){
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;    

}




Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;

    switch(Copy_BusId){
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;    
}









