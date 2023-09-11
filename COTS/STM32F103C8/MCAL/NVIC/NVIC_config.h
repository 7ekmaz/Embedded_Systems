/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/



#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_


#define NUMBER_OF_INTERRUPTS            67            // Number of interrupts used in STM32f10xx devices


#define NVIC_MAX_PRIORITY               15            // For Maximum Number of Groups of Interrupts


/***
 * @brief 
 * your options are                           //FOR Number of Groups and Subgroups..............
 *                 -NVIC_16GROUP_0SUB
 *                 -NVIC_8GROUP_2SUB
 *                 -NVIC_4GROUP_4SUB
 *                 -NVIC_2GROUP_8SUB
 *                 -NVIC_0GROUP_16SUB
*/
#define PRIORITY_GROUPING   NVIC_4GROUP_4SUB



#endif