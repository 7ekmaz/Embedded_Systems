/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_










/***
 * @brief 
 * your options are                               ******** FOR(source of the CLOCK)******
 *                 -RCC_HSI
 *                 -RCC_HSE
 *                 -RCC_PLL
*/

#define RCC_SYSCLK   RCC_PLL










/***
 * @brief 
* your options are                                 ****** FOR(source of the EXTERNAL CLK)******
 *                 -RCC_RC_CLK
 *                 -RCC_CRYSTAL_CLK
 *                 
*/

#define RCC_CLK_BYPASS   RCC_CRYSTAL_CLK















/***
 * @brief 
* your options are                                 ****** FOR(ValueS of HSE Or HSI clock)for HSE,HSI or PLL Based on HSE,HSI******
 *                 -RCC_HSI_CLK_VAl8                  
 *                 -RCC_HSE_CLK__RC_VAl25                  
 *                 -RCC_HSE_CLK_VAL4         
 *                 -RCC_HSE_CLK_VAL5         
 *                 -RCC_HSE_CLK_VAL6        
 *                 -RCC_HSE_CLK_VAL7         
 *                 -RCC_HSE_CLK_VAL8         
 *                 -RCC_HSE_CLK_VAL9         
 *                 -RCC_HSE_CLK_VAL10         
 *                 -RCC_HSE_CLK_VAL11         
 *                 -RCC_HSE_CLK_VAL12         
 *                 -RCC_HSE_CLK_VAL13         
 *                 -RCC_HSE_CLK_VAL14         
 *                 -RCC_HSE_CLK_VAL15         
 *                 -RCC_HSE_CLK_VAL16                      
*/
#define RCC_CLK_VALUE   RCC_HSE_CLK_VAL4 









/***
 * @brief 
 * your options are                    *******FOR(Source of the PLL CLK)********
 *                 -RCC_PLL_CLKSRC_HSE
 *                 -RCC_PLL_CLKSRC_HSI 
 *                 
*/
#if RCC_SYSCLK==RCC_PLL

#define RCC_CLK_PLL_SRC         RCC_PLL_CLKSRC_HSE   
#endif















#if RCC_CLK_PLL_SRC==RCC_PLL_CLKSRC_HSE
/***
 * @brief 
 * your options are                 ********FOR(Source of the PLL CLK HSE DIVIDED BY 2)********
 *                 -RCC_PLL_CLKSRC_HSE_DIVIDED
 *                 -RCC_PLL_CLKSRC_HSE_NOT_DIVIDED
 *                 
*/

#define RCC_PLL_CLKSRC_HSE_STATE       RCC_PLL_CLKSRC_HSE_DIVIDED
#endif
















/***
 * @brief 
 * your options are                    ******** FOR(PLL CLOCK MULTIPLIER)******
 *                 -PLL_CLK_X2
 *                 -PLL_CLK_X3
 *                 -PLL_CLK_X4
 *                 -PLL_CLK_X5
 *                 -PLL_CLK_X6
 *                 -PLL_CLK_X7
 *                 -PLL_CLK_X8
 *                 -PLL_CLK_X9
 *                 -PLL_CLK_X10
 *                 -PLL_CLK_X11
 *                 -PLL_CLK_X12
 *                 -PLL_CLK_X13
 *                 -PLL_CLK_X14
 *                 -PLL_CLK_X15
 *                 -PLL_CLK_X16
*/

#define     RCC_PLL_CLK_MULTI      PLL_CLK_X5 
















/***
 * @brief 
 * your options are                 ********FOR(Values of PreScaler of AHB)********
 *                 -RCC_CLK_AHB_DivBy1            
 *                 -RCC_CLK_AHB_DivBy2            
 *                 -RCC_CLK_AHB_DivBy4                
 *                 -RCC_CLK_AHB_DivBy8               
 *                 -RCC_CLK_AHB_DivBy16                             
 *                 -RCC_CLK_AHB_DivBy64             
 *                 -RCC_CLK_AHB_DivBy128                         
 *                 -RCC_CLK_AHB_DivBy256             
 *                 -RCC_CLK_AHB_DivBy512        
 *                 
*/


#define RCC_CLK_AHB_PRESCALER              RCC_CLK_AHB_DivBy8          







/***
 * @brief 
 * your options are                 ********FOR(Values of PreScaler for APB1 or APB2)********
 *                 -RCC_CLK_APB_DivBy1            
 *                 -RCC_CLK_APB_DivBy2            
 *                 -RCC_CLK_APB_DivBy4                
 *                 -RCC_CLK_APB_DivBy8               
 *                 -RCC_CLK_APB_DivBy16                             
 *                 -RCC_CLK_APB_DivBy64             
 *                 -RCC_CLK_APB_DivBy128                         
 *                 -RCC_CLK_APB_DivBy256             
 *                 -RCC_CLK_APB_DivBy512        
 *                 
*/
#define RCC_CLK_APB_PRESCALER              RCC_CLK_APB_DivBy8     






#endif




