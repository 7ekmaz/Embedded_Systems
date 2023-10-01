/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



/**< EXTI base address */
#define EXTI_BASE_ADDRESS    0x40010400U

/**< EXTI register structure */
typedef struct 
{
    volatile u32 IMR;   /**< Interrupt Mask Register */
    volatile u32 EMR;   /**< Event Mask Register */
    volatile u32 RTSR;  /**< Rising Trigger Selection Register */
    volatile u32 FTSR;  /**< Falling Trigger Selection Register */
    volatile u32 SWIER; /**< Software Interrupt Event Register */
    volatile u32 PR;    /**< Pending Register */
} EXTI_RegDef_t;

/**< Pointer to EXTI register structure */
#define EXTI   ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)

/**< Total number of EXTI lines available */
#define EXTI_LINES_COUNT        16

/**< EXTI line enabled */
#define EXTI_LINE_ENABLED       1

/**< EXTI line disabled */
#define EXTI_LINE_DISABLED      0

/**< EXTI Configuration Structure */
typedef struct 
{
    u8 GPIO_PortMap: 3;         /**< GPIO port to be used (EXTI_GPIO_PORTA, EXTI_GPIO_PORTB, etc.) */
    u8 TriggerType: 2;          /**< Trigger type (EXTI_TRIGGER_RISING, EXTI_TRIGGER_FALLING, EXTI_TRIGGER_BOTH, etc.) */
    u8 LineEnabled: 1;          /**< EXTI line enabled or disabled (1 or 0) */
    u8 : 2;                     /**< 2 bits of padding */
} EXTI_Configuration_t;


/**< EXTI line configuration settings */
extern EXTI_Configuration_t EXTI_Configurations[EXTI_LINES_COUNT];

#endif