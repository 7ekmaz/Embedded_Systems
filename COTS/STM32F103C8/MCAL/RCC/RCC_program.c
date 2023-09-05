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


/********************************************************INITIALIZATION OF THE SYSTEM CLOCK****************************************************/
Std_ReturnType Mcal_Rcc_InitSysClock(void)
{

    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK==RCC_HSE
        
        #if RCC_CLK_BYPASS==RCC_RC_CLK
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS==RCC_CRYSTAL_CLK
            CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
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
        
        /******Before we Enable the Pll CLK we must Configure it******/
        switch (RCC_CLK_PLL_SRC)
        {

        case RCC_PLL_CLKSRC_HSE :
            SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
            switch (RCC_PLL_CLKSRC_HSE_STATE )
            {
            case  RCC_PLL_CLKSRC_HSE_DIVIDED:
                SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE); 
                Local_FunctionStatus=E_OK;
                break;
            
            case RCC_PLL_CLKSRC_HSE_NOT_DIVIDED:
                CLR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE); 
                Local_FunctionStatus=E_OK;
            break;
            default:
            Local_FunctionStatus=E_NOT_OK;
                break;
            }
        break;


        case  RCC_PLL_CLKSRC_HSI:
            CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
        break;
        
        default: Local_FunctionStatus=E_NOT_OK;
            break;
        }

        /*Enable the PLL*/
        SET_BIT(RCC_CR, RCC_CR_PLLON );

        /*wait until the clock be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY))

        RCC_CFGR=0x00000002 ;


        Local_FunctionStatus=E_OK;
    #else 
        #error"WRONG CHOICE !!!!!!"

    #endif

    return Local_FunctionStatus;
}






/****************************************************SET MULTIPLIER OF THE PLL CLOCK************************************************/

Std_ReturnType Mcal_Rcc_SetPLLClock_MUL(u8 Copy_Clk_Multi)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK; 
    switch (Copy_Clk_Multi)
    {
    case 2:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0000 << (18));
        Local_FunctionStatus=E_OK;
        break;
    case 3:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0001 << (18));
        Local_FunctionStatus=E_OK;
        break;
    case 4:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0010 << (18));
        Local_FunctionStatus=E_OK;
        break;
    case 5:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0011 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 6:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0100 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 7:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0101 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 8:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0110 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 9:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b0111 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 10:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1000 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 11:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1001 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 12:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1010 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 13:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1011 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 14:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1100 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 15:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1101 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    case 16:
        RCC_CFGR  &= ~((0b1111) << (18)); 
        RCC_CFGR  |= (0b1110 << (18));
        Local_FunctionStatus=E_OK;
        break;            
    
    
    default:
    Local_FunctionStatus=E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}


/****************************************TO ENABLE PERIPHERAL FUNCTION****************************************************************************/

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



/*******************************************************TO DESABLE PERIPHERAL FUNCTION*********************************************************/
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









