/*****LIB*****/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*****MCAL*****/
#include "RCC_interface.h"
#include "GPIO_interface.h"



/*****MAIN*****/
int main(void)
{
	/**<init for SYSCLK*/
	Mcal_Rcc_InitSysClock();
	
	
	/**<Enable for Wanted peripheral*/
	Mcal_Rcc_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	
	
	
	/**<Set PIN0 ,PIN1,PIN2 in port A (mode)*/
	Mcal_Gpio_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_PUSH_PULL_2MHZ); //error because of Binary Try to write it as Hexa 
	
	Mcal_Gpio_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_INPUT_PUSH_PULL_MODE);
	
	Mcal_Gpio_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_INPUT_PUSH_PULL_MODE);

	for(;;);
}