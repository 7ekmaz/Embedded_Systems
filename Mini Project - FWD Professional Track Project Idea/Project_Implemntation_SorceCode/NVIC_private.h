/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#include "STD_TYPES.h"
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



typedef u8      IRQn_Type;

/****************************************************THIS is The Struct Method*************************************************************/
//i want to access all without shift
typedef struct
{
    /*Interrupt Set Enable Register*/
    volatile u32 ISER[3];
    volatile u32 reserved_0[29];

    /*Interrupt Set Enable Register*/
    volatile u32 ICER[3];
    volatile u32 reserved_1[29];


    volatile u32 ISPR[3];
    volatile u32 reserved_2[29];


    volatile u32 ICPR[3];
    volatile u32 reserved_3[29];


    volatile u32 IABR[3];
    volatile u32 reserved_4[29];


    volatile u8 IPR[84];
    volatile u32 reserved_5[695];


    volatile u32 STIR;

}NVIC_Typedef;          
#define NVIC           (NVIC_Typedef*)NVIC_BASE_ADDRESS //address casted of type Struct
//NVIC->ISER[0] //to access the first bit for example 
/*WANTED TO BE COMPLETED............................................*/



/*****************************************************THIS is The #define Method**************************************************************/
#define NVIC_BASE_ADDRESS           0xE000E100


#define NVIC_ISER0     (*((volatile u32 *)0xE000E100)) /**< INTERRUPT SET-ENABLE REGISTERS 0 to 31 */
#define NVIC_ISER1     (*((volatile u32 *)0xE000E104)) /**< INTERRUPT SET-ENABLE REGISTERS 32 to 63 */
#define NVIC_ISER2     (*((volatile u32 *)0xE000E108)) /**< INTERRUPT SET-ENABLE REGISTERS 64 to 95 */


#define NVIC_ICER0     (*((volatile u32 *)0xE000E180)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 0 to 31 */
#define NVIC_ICER1     (*((volatile u32 *)0xE000E184)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 32 to 63 */
#define NVIC_ICER2     (*((volatile u32 *)0xE000E188)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 64 to 95 */


#define NVIC_ISPR0     (*((volatile u32 *)0xE000E200)) /**< INTERRUPT SET-PENDING REGISTERS 0 to 31 */
#define NVIC_ISPR1     (*((volatile u32 *)0xE000E204)) /**< INTERRUPT SET-PENDING REGISTERS 32 to 63 */
#define NVIC_ISPR2     (*((volatile u32 *)0xE000E208)) /**< INTERRUPT SET-PENDING REGISTERS 64 to 95 */


#define NVIC_ICPR0     (*((volatile u32 *)0xE000E280)) /**< INTERRUPT CLEAR-PENDING REGISTERS 0 to 31 */
#define NVIC_ICPR1     (*((volatile u32 *)0xE000E284)) /**< INTERRUPT CLEAR-PENDING REGISTERS 32 to 63 */
#define NVIC_ICPR2     (*((volatile u32 *)0xE000E288)) /**< INTERRUPT CLEAR-PENDING REGISTERS 64 to 95 */


#define NVIC_IABR0     (*((volatile u32 *)0xE000E300)) /**< INTERRUPT ACTIVE BIT REGISTERS 0 to 31 */
#define NVIC_IABR1     (*((volatile u32 *)0xE000E304)) /**< INTERRUPT ACTIVE BIT REGISTERS 32 to 63 */
#define NVIC_IABR2     (*((volatile u32 *)0xE000E308)) /**< INTERRUPT ACTIVE BIT REGISTERS 64 to 95 */


#define NVIC_IPR_BASE_ADDRESS    (((volatile u32 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */


                                            //we Choose u8 as a data type because of the (((STEP SIZE))))
                                            //[]-->*(Stepping)   //so we don't use * so we can use []






#define NVIC_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define NVIC_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define NVIC_4GROUP_4SUB    0#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


/**
 * @defgroup NVIC_Registers NVIC Registers
 * @brief NVIC (Nested Vectored Interrupt Controller) Registers.
 * @{
 */

/**
 * @brief NVIC ISER Registers.
 * @{
 */
#define NVIC_ISER0     (*((volatile u32 *)0xE000E100)) /**< INTERRUPT SET-ENABLE REGISTERS 0 to 31 */
#define NVIC_ISER1     (*((volatile u32 *)0xE000E104)) /**< INTERRUPT SET-ENABLE REGISTERS 32 to 63 */
#define NVIC_ISER2     (*((volatile u32 *)0xE000E108)) /**< INTERRUPT SET-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICER Registers.
 * @{
 */
#define NVIC_ICER0     (*((volatile u32 *)0xE000E180)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 0 to 31 */
#define NVIC_ICER1     (*((volatile u32 *)0xE000E184)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 32 to 63 */
#define NVIC_ICER2     (*((volatile u32 *)0xE000E188)) /**< INTERRUPT CLEAR-ENABLE REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ISPR Registers.
 * @{
 */
#define NVIC_ISPR0     (*((volatile u32 *)0xE000E200)) /**< INTERRUPT SET-PENDING REGISTERS 0 to 31 */
#define NVIC_ISPR1     (*((volatile u32 *)0xE000E204)) /**< INTERRUPT SET-PENDING REGISTERS 32 to 63 */
#define NVIC_ISPR2     (*((volatile u32 *)0xE000E208)) /**< INTERRUPT SET-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC ICPR Registers.
 * @{
 */
#define NVIC_ICPR0     (*((volatile u32 *)0xE000E280)) /**< INTERRUPT CLEAR-PENDING REGISTERS 0 to 31 */
#define NVIC_ICPR1     (*((volatile u32 *)0xE000E284)) /**< INTERRUPT CLEAR-PENDING REGISTERS 32 to 63 */
#define NVIC_ICPR2     (*((volatile u32 *)0xE000E288)) /**< INTERRUPT CLEAR-PENDING REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IABR Registers.
 * @{
 */
#define NVIC_IABR0     (*((volatile u32 *)0xE000E300)) /**< INTERRUPT ACTIVE BIT REGISTERS 0 to 31 */
#define NVIC_IABR1     (*((volatile u32 *)0xE000E304)) /**< INTERRUPT ACTIVE BIT REGISTERS 32 to 63 */
#define NVIC_IABR2     (*((volatile u32 *)0xE000E308)) /**< INTERRUPT ACTIVE BIT REGISTERS 64 to 95 */
/** @} */

/**
 * @brief NVIC IPR Base Address
 */                                                 
#define NVIC_IPR_BASE_ADDRESS    (((volatile u32 *)0xE000E400)) /**< INTERRUPT PRIORITY REGISTERS BASE ADDRESS */

/**
 * @brief Priority Grouping Values
 * @{
 */
#define NVIC_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define NVIC_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define NVIC_4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define NVIC_2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define NVIC_0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */
/** @} */


/**
 * @} (end of group NVIC_Registers)
 */

#endif /**< NVIC_PRIVATE_H_ */