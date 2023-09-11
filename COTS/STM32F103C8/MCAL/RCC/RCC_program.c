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

Std_ReturnType Mcal_Rcc_SetPLLClock_MUL(void)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK; 
    if (RCC_CLK_PLL_SRC==RCC_PLL_CLKSRC_HSE)
    {
        if (RCC_PLL_CLKSRC_HSE_STATE==RCC_PLL_CLKSRC_HSE_DIVIDED&&RCC_CLK_BYPASS==RCC_CRYSTAL_CLK)
        {
            if((RCC_CLK_VALUE*((u8)(RCC_PLL_CLK_MULTI)+2 )/(f32)RCC_PLL_CLKSRC_HSE_DIVIDED)<=72)             //we divide by float so the final value be float
                {
                RCC_CFGR  &= ~((0b1111) << (18)); 
                RCC_CFGR  |= (RCC_PLL_CLK_MULTI << (18));
                }
            else
                {
                error("System Clock Has Exceeded The Maximum, Please Try Again with another Factor");
                Local_FunctionStatus=E_NOT_OK;
                }
        }
    
    
        else if (RCC_PLL_CLKSRC_HSE_STATE==RCC_PLL_CLKSRC_HSE_NOT_DIVIDED&&RCC_CLK_BYPASS==RCC_CRYSTAL_CLK)
        {
            if((RCC_CLK_VALUE*((u8)(RCC_PLL_CLK_MULTI)+2 )/(f32)RCC_PLL_CLKSRC_HSE_NOT_DIVIDED)<=72)
                {
                RCC_CFGR  &= ~((0b1111) << (18)); 
                RCC_CFGR  |= (RCC_PLL_CLK_MULTI << (18));
                }
            else
                {
                error("System Clock Has Exceeded The Maximum, Please Try Again with another Factor");
                Local_FunctionStatus=E_NOT_OK;
                }
        }

        else                                        ////HSE RC SOURCE 
        {
            if((RCC_CLK_VALUE*((u8)(RCC_PLL_CLK_MULTI)+2 ))<=72)
                {
                RCC_CFGR  &= ~((0b1111) << (18)); 
                RCC_CFGR  |= (RCC_PLL_CLK_MULTI << (18));
                }
            else
                {
                error("System Clock Has Exceeded The Maximum, Please Try Again with another Factor");
                Local_FunctionStatus=E_NOT_OK;
                }
        }
    }
        
    else if(RCC_CLK_PLL_SRC==RCC_PLL_CLKSRC_HSI) 
    {
        if((RCC_CLK_VALUE*((u8)(RCC_PLL_CLK_MULTI)+2 )/(f32)2)<=72)
        {
            RCC_CFGR  &= ~((0b1111) << (18)); 
            RCC_CFGR  |= (RCC_PLL_CLK_MULTI << (18));
        }
        else
        {
            error("System Clock Has Exceeded The Maximum, Please Try Again with another Factor");
            Local_FunctionStatus=E_NOT_OK;
        }
    }
    else{
    return Local_FunctionStatus;
    }
}

















/*******************************************SET The PreScaler of the Clock And CHeck************************************************/
Std_ReturnType Mcal_Rcc_SetPreScaler_And_Check(u8 Copy_BusId )
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK; 
    switch (Copy_BusId)
    {
        
    case RCC_AHB:
        RCC_CFGR &=~(RCC_CLK_AHB_PRESCALER<<RCC_CFGR_HPRE );
        RCC_CFGR |=(RCC_CLK_AHB_PRESCALER<<RCC_CFGR_HPRE );
        Local_FunctionStatus=E_OK; 
        break;
    
    case RCC_APB1:
        u8 Local_Clk_Value=1;
        for(u8 i=0; i<((u8)(RCC_CLK_APB_PRESCALER)-3);i++) //to get the value of the APB Prescaler  
        {
            Local_Clk_Value=Local_Clk_Value*2;     
        }
        if(72/((f32)((u8)(RCC_CLK_AHB_PRESCALER)-2)*Local_Clk_Value)   <=36)               //the MAX of APB1 Bus is 36                     //WE NEED TO REPLACE 72 WITH CLOCK SYSTEM!!!!!!!!!*****//Need to Continue
        {
        RCC_CFGR &=~(RCC_CLK_APB_PRESCALER<<RCC_CFGR_PPRE1 );
        RCC_CFGR |=(RCC_CLK_APB_PRESCALER<<RCC_CFGR_PPRE1 );
        Local_FunctionStatus=E_OK; 
        }
        else
        {
            error("System Clock Has Exceeded The Maximum, Please Try Again with another Scale");
            return Local_FunctionStatus;
        }
        break;
        
    case RCC_APB2:
        RCC_CFGR &=~(RCC_CLK_APB_PRESCALER<<RCC_CFGR_PPRE2 );
        RCC_CFGR |=(RCC_CLK_APB_PRESCALER<<RCC_CFGR_PPRE2 );
        Local_FunctionStatus=E_OK; 
        break;
            
    
    default:
        Local_FunctionStatus=E_NOT_OK; 
        break;
    }
}






















/****************************************TO ENABLE PERIPHERAL FUNCTION****************************************************************************/

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
    
     //We Must use the Prescaler Function first to check if the Clock Exceeded the Bus Value
    Std_ReturnType Mcal_Rcc_SetPreScaler_And_Check(u8 Copy_BusId );     

    
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















/*******************************************************TO DISABLE PERIPHERAL FUNCTION*********************************************************/
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









