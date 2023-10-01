/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
///************Date:8/29/2023***************************/
//
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
//
//
//
//
//
//
//
//
//
//
///***
// * @brief 
// * your options are                               ******** FOR(source of the CLOCK)******
// *                 -RCC_HSI
// *                 -RCC_HSE
// *                 -RCC_PLL
//*/
//
//#define RCC_SYSCLK   RCC_PLL
//
//
//
//
//
//
//
//
//
//
///***
// * @brief 
//* your options are                                 ****** FOR(source of the EXTERNAL CLK)******
// *                 -RCC_RC_CLK
// *                 -RCC_CRYSTAL_CLK
// *                 
//*/
//
//#define RCC_CLK_BYPASS   RCC_CRYSTAL_CLK
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
///***
// * @brief 
//* your options are                                 ****** FOR(ValueS of HSE Or HSI clock)for HSE,HSI or PLL Based on HSE,HSI******
// *                 -RCC_HSI_CLK_VAl8                  
// *                 -RCC_HSE_CLK__RC_VAl25                  
// *                 -RCC_HSE_CLK_VAL4         
// *                 -RCC_HSE_CLK_VAL5         
// *                 -RCC_HSE_CLK_VAL6        
// *                 -RCC_HSE_CLK_VAL7         
// *                 -RCC_HSE_CLK_VAL8         
// *                 -RCC_HSE_CLK_VAL9         
// *                 -RCC_HSE_CLK_VAL10         
// *                 -RCC_HSE_CLK_VAL11         
// *                 -RCC_HSE_CLK_VAL12         
// *                 -RCC_HSE_CLK_VAL13         
// *                 -RCC_HSE_CLK_VAL14         
// *                 -RCC_HSE_CLK_VAL15         
// *                 -RCC_HSE_CLK_VAL16                      
//*/
//#define RCC_CLK_VALUE   RCC_HSE_CLK_VAL4 
//
//
//
//
//
//
//
//
//
///***
// * @brief 
// * your options are                    *******FOR(Source of the PLL CLK)********
// *                 -RCC_PLL_CLKSRC_HSE
// *                 -RCC_PLL_CLKSRC_HSI 
// *                 
//*/
//#if RCC_SYSCLK==RCC_PLL
//
//#define RCC_CLK_PLL_SRC         RCC_PLL_CLKSRC_HSE   
//#endif
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#if RCC_CLK_PLL_SRC==RCC_PLL_CLKSRC_HSE
///***
// * @brief 
// * your options are                 ********FOR(Source of the PLL CLK HSE DIVIDED BY 2)********
// *                 -RCC_PLL_CLKSRC_HSE_DIVIDED
// *                 -RCC_PLL_CLKSRC_HSE_NOT_DIVIDED
// *                 
//*/
//
//#define RCC_PLL_CLKSRC_HSE_STATE       RCC_PLL_CLKSRC_HSE_DIVIDED
//#endif
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
///***
// * @brief 
// * your options are                    ******** FOR(PLL CLOCK MULTIPLIER)******
// *                 -PLL_CLK_X2
// *                 -PLL_CLK_X3
// *                 -PLL_CLK_X4
// *                 -PLL_CLK_X5
// *                 -PLL_CLK_X6
// *                 -PLL_CLK_X7
// *                 -PLL_CLK_X8
// *                 -PLL_CLK_X9
// *                 -PLL_CLK_X10
// *                 -PLL_CLK_X11
// *                 -PLL_CLK_X12
// *                 -PLL_CLK_X13
// *                 -PLL_CLK_X14
// *                 -PLL_CLK_X15
// *                 -PLL_CLK_X16
//*/
//
//#define     RCC_PLL_CLK_MULTI      PLL_CLK_X5 
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
///***
// * @brief 
// * your options are                 ********FOR(Values of PreScaler of AHB)********
// *                 -RCC_CLK_AHB_DivBy1            
// *                 -RCC_CLK_AHB_DivBy2            
// *                 -RCC_CLK_AHB_DivBy4                
// *                 -RCC_CLK_AHB_DivBy8               
// *                 -RCC_CLK_AHB_DivBy16                             
// *                 -RCC_CLK_AHB_DivBy64             
// *                 -RCC_CLK_AHB_DivBy128                         
// *                 -RCC_CLK_AHB_DivBy256             
// *                 -RCC_CLK_AHB_DivBy512        
// *                 
//*/
//
//
//#define RCC_CLK_AHB_PRESCALER              RCC_CLK_AHB_DivBy8          
//
//
//
//
//
//
//
///***
// * @brief 
// * your options are                 ********FOR(Values of PreScaler for APB1 or APB2)********
// *                 -RCC_CLK_APB_DivBy1            
// *                 -RCC_CLK_APB_DivBy2            
// *                 -RCC_CLK_APB_DivBy4                
// *                 -RCC_CLK_APB_DivBy8               
// *                 -RCC_CLK_APB_DivBy16                             
// *                 -RCC_CLK_APB_DivBy64             
// *                 -RCC_CLK_APB_DivBy128                         
// *                 -RCC_CLK_APB_DivBy256             
// *                 -RCC_CLK_APB_DivBy512        
// *                 
//*/
//#define RCC_CLK_APB_PRESCALER              RCC_CLK_APB_DivBy8     
//
//
//
//
//
//



















/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK            RCC_HSI


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_
                                
#endif /**< RCC_SYSCLK */

#if RCC_SYSCLK == RCC_PLL


#endif /**< RCC_SYSCLK */

/** @} */ // end of RCC_System_Clock_Config



#endif
