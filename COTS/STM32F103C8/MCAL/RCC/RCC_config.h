/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/***
 * @brief 
 * your options are                    ******** FOR(source of the CLOCK)******
 *                 -RCC_HSI
 *                 -RCC_HSE
 *                 -RCC_PLL
*/

#define RCC_SYSCLK   RCC_PLL




/***
 * @brief 
* your options are                   ****** FOR(source of the EXTERNAL CLK)******
 *                 -RCC_RC_CLK
 *                 -RCC_CRYSTAL_CLK
 *                 
*/
#if RCC_SYSCLK==RCC_HSE

#define RCC_CLK_BYPASS   RCC_CRYSTAL_CLK

#endif





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











