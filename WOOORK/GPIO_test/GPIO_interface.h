/***********************************************************/
/******************Autho  Kareem Wael Elhamy****************/
/******************Date:8/29/2023***************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include "STD_TYPES.h"


#define GPIO_OUTPUT                     0
#define GPIO_INPUT                      1

#define GPIO_HIGH                       1
#define GPIO_LOW                        0


#define   GPIO_PORTA      0
#define   GPIO_PORTB      1
#define   GPIO_PORTC      2


#define GPIO_PIN0           0
#define GPIO_PIN1           1
#define GPIO_PIN2           2
#define GPIO_PIN3           3
#define GPIO_PIN4           4
#define GPIO_PIN5           5
#define GPIO_PIN6           6
#define GPIO_PIN7           7
#define GPIO_PIN8           8
#define GPIO_PIN9           9
#define GPIO_PIN10          10
#define GPIO_PIN11          11
#define GPIO_PIN12          12
#define GPIO_PIN13          13
#define GPIO_PIN14          14
#define GPIO_PIN15          15




#define GPIO_INPUT_ANALOG_MOD                         0b0000     
#define GPIO_INPUT_FLOATING_MODE                      0b0100     
#define GPIO_INPUT_PUSH_PULL_MODE                     0b1000   

#define GPIO_OUTPUT_PUSH_PULL_10MHZ                   0b0001    
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ                  0b0101    
#define GPIO_OUTPUT_AF_PUSH_PULL_10MHZ                0b1001    
#define GPIO_OUTPUT_AF_OPEN_DRAIN_10MHZ               0b1101    

#define GPIO_OUTPUT_PUSH_PULL_2MHZ                    0b0010    
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ                   0b0110    
#define GPIO_OUTPUT_AF_PUSH_PULL_2MHZ                 0b1010    
#define GPIO_OUTPUT_AF_OPEN_DRAIN_2MHZ                0b1110    

#define GPIO_OUTPUT_PUSH_PULL_50MHZ                   0b0011    
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ                  0b0111    
#define GPIO_OUTPUT_AF_PUSH_PULL_50MHZ                0b1011    
#define GPIO_OUTPUT_AF_OPEN_DRAIN_50MHZ               0b1111    


Std_ReturnType Mcal_Gpio_SetPinMode (u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinMode );

Std_ReturnType Mcal_Gpio_SetPinValue (u8 Copy_PortId,u8 Copy_PinId,u8 Copy_PinValue );

Std_ReturnType Mcal_Gpio_GetPinValue (u8 Copy_PortId,u8 Copy_PinId,u8 *Copy_PinReturnValue );



#endif