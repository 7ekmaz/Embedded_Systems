/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*****************************************************REG NAMES*****************************************************/
#define RCC_BASE_ADDRESS                         (0x40021000)
#define RCC_CR                (*((volatile u32 *)(0x40021000+0X00))) //This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
#define RCC_CFGR              (*((volatile u32 *)(0x40021000+0X04))) //This register configures the system clock sources, prescalers, and peripherals clocks.
#define RCC_CIR               (*((volatile u32 *)(0x40021000+0X08))) //This register manages clock interrupts and flags.
#define RCC_APB2RSTR          (*((volatile u32 *)(0x40021000+0X0C))) //This register controls the reset state of peripherals connected to APB2 bus.
#define RCC_APB1RSTR          (*((volatile u32 *)(0x40021010+0X10))) //This register controls the reset state of peripherals connected to APB1 bus.
#define RCC_AHBENR            (*((volatile u32 *)(0x40021010+0X14))) //This register enables clock access for peripherals connected to AHB bus.
#define RCC_APB2ENR           (*((volatile u32 *)(0x40021010+0X18))) //This register enables clock access for peripherals connected to APB1 bus.
#define RCC_APB1ENR           (*((volatile u32 *)(0x40021010+0X1C))) //This register enables clock access for peripherals connected to APB2 bus.
#define RCC_BDCR              (*((volatile u32 *)(0x40021010+0X20))) //This register provides control over backup domain and RTC (Real-Time Clock).
#define RCC_CSR               (*((volatile u32 *)(0x40021010+0X24))) //This register provides various control and status flags.





/****************************************PINS(NEEDED) at (((CR))) REGISTER*******************************************/
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





/****************************************PINS (NEEDED) at (((CFGR))) REGISTER*******************************************/
#define RCC_CFGR_PLLSRC       16 /**< PLL Entry Clock Source */
#define RCC_CFGR_PLLXTPRE     17 /**< HSE Divider For PLL Entry*/




/****************************CLOCKs FOR PLL *********************/
#define   RCC_PLL_CLKSRC_HSE                0
#define   RCC_PLL_CLKSRC_HSI                1
#define   RCC_PLL_CLKSRC_HSE_DIVIDED        0
#define   RCC_PLL_CLKSRC_HSE_NOT_DIVIDED    1







/****************************CLOCKs*****************************/
#define RCC_HSI            0
#define RCC_HSE            1
#define RCC_PLL            2








/***********************CLK SRC For HSE*************************/
#define RCC_RC_CLK        1
#define RCC_CRYSTAL_CLK   0



#endif 