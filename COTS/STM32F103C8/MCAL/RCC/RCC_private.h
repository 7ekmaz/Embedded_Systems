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
#define RCC_CFGR_HPRE          4 /**< AHB Prescaler for Clock*/
#define RCC_CFGR_PPRE1         8 /**< APB1 Prescaler for Clock*/
#define RCC_CFGR_PPRE2        11 /**< APB2 Prescaler for Clock*/




/****************************CLOCKs FOR PLL *********************/
#define   RCC_PLL_CLKSRC_HSE                0
#define   RCC_PLL_CLKSRC_HSI                1
#define   RCC_PLL_CLKSRC_HSE_DIVIDED        2
#define   RCC_PLL_CLKSRC_HSE_NOT_DIVIDED    1







/****************************CLOCKs*****************************/
#define RCC_HSI            0
#define RCC_HSE            1
#define RCC_PLL            2



/***********************VALUES of CLOCKs************************/                       
#define RCC_HSI_CLK_VAl             8          
#define RCC_HSE_CLK_VAL4            4         //  4----16      HZ
#define RCC_HSE_CLK_VAL5            5
#define RCC_HSE_CLK_VAL6            6            
#define RCC_HSE_CLK_VAL7            7           
#define RCC_HSE_CLK_VAL8            8        
#define RCC_HSE_CLK_VAL9            9        
#define RCC_HSE_CLK_VAL10           10        
#define RCC_HSE_CLK_VAL11           11        
#define RCC_HSE_CLK_VAL12           12           
#define RCC_HSE_CLK_VAL13           13        
#define RCC_HSE_CLK_VAL14           14           
#define RCC_HSE_CLK_VAL15           15           
#define RCC_HSE_CLK_VAL16           16               



/***********************CLK SRC For HSE*************************/
#define RCC_RC_CLK        1
#define RCC_CRYSTAL_CLK   0



/**********************CLK Multiplier For PLL*******************/

#define  PLL_CLK_X2               0b0000            
#define  PLL_CLK_X3               0b0001 
#define  PLL_CLK_X4               0b0010 
#define  PLL_CLK_X5               0b0011 
#define  PLL_CLK_X6               0b0100 
#define  PLL_CLK_X7               0b0101 
#define  PLL_CLK_X8               0b0110 
#define  PLL_CLK_X9               0b0111 
#define  PLL_CLK_X10              0b1000  
#define  PLL_CLK_X11              0b1001 
#define  PLL_CLK_X12              0b1010 
#define  PLL_CLK_X13              0b1011 
#define  PLL_CLK_X14              0b1100 
#define  PLL_CLK_X15              0b1101 
#define  PLL_CLK_X16              0b1110 









/************************CLK PreScaler for AHB************************/

#define RCC_CLK_AHB_DivBy1    0b0000
#define RCC_CLK_AHB_DivBy2    0b1000
#define RCC_CLK_AHB_DivBy4    0b1001
#define RCC_CLK_AHB_DivBy8    0b1010
#define RCC_CLK_AHB_DivBy16   0b1011
#define RCC_CLK_AHB_DivBy64   0b1100
#define RCC_CLK_AHB_DivBy128  0b1101
#define RCC_CLK_AHB_DivBy256  0b1110
#define RCC_CLK_AHB_DivBy512  0b1111










/************************CLK PreScaler for APB1 or APB2************************/

#define RCC_CLK_APB_DivBy1    0b000
#define RCC_CLK_APB_DivBy2    0b100
#define RCC_CLK_APB_DivBy4    0b101
#define RCC_CLK_APB_DivBy8    0b110
#define RCC_CLK_APB_DivBy16   0b111





































































#endif 