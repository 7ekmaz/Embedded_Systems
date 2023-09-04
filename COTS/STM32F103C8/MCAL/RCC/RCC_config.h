/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/***
 * @brief 
 * your options are
 *                 -RCC_HSI
 *                 -RCC_HSE
 *                 -RCC_PLL
*/

#define RCC_SYSCLK   RCC_HSE




/***
 * @brief 
 * your options are
 *                 -RCC_RC_CLK
 *                 -RCC_CRYSTAL_CLK
 *                 
*/
#if RCC_SYSCLK==RCC_HSE

#define RCC_CLK_BYPASS   RCC_CRYSTAL_CLK

#endif

#endif 





