/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_BASE_ADDRESS                        (0x40021000)
#define RCC_CR                (*((volatile u32 *)(0x40021000+0X00)))
#define RCC_CFGR              (*((volatile u32 *)(0x40021000+0X04)))
#define RCC_CIR               (*((volatile u32 *)(0x40021000+0X08)))
#define RCC_APB2RSTR          (*((volatile u32 *)(0x40021000+0X0C)))
#define RCC_APB1RSTR          (*((volatile u32 *)(0x40021010+0X10)))
#define RCC_AHBENR            (*((volatile u32 *)(0x40021010+0X14)))
#define RCC_APB2ENR           (*((volatile u32 *)(0x40021010+0X18)))
#define RCC_APB1ENR           (*((volatile u32 *)(0x40021010+0X1C)))
#define RCC_BDCR              (*((volatile u32 *)(0x40021010+0X20)))
#define RCC_CSR               (*((volatile u32 *)(0x40021010+0X24)))




#define RCC_CR_HSION        0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY       1   /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL       8   /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON        16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY       17  /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP       18  /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE       19  /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON        24  /**< Clock Security System Enable */
#define RCC_CR_PLLON        24  /**< PLL Enable */
#define RCC_CR_PLLRDY       25  /**< PLL Ready */


#define RCC_HSI            0
#define RCC_HSE            1
#define RCC_PLL            2









#define RCC_RC_CLK        1
#define RCC_CRYSTAL_CLK   0



#endif 