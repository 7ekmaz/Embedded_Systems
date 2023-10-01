#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LED.h"
#include "PushButton.h"

/**< APP */



u8 count=0;
u8 value=0 ;
u8 check(void);
u8 blinking(void);
int main(void)
{
	/*****************************************< Void Setup ****************************************/
	/**< Init Clock */
	MCAL_RCC_InitSysClock();
	
	/**< Init EXTI */
	EXTI_vInit();
	EXTI_InitForGPIO(GPIO_PIN3,GPIO_PORTB);
	EXTI_EnableLine(0);
	EXTI_SetTrigger(0, 1);

	
	/**< Init NVIC */
	MCAL_NVIC_EnableIRQ( 0);
	MCAL_NVIC_xSetPriority(0, 0);
	
	
	/**< Enable Peripheral */
  MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
	MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);
	
	/**< Inti LED */
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN0);  //RED LIGHT
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN1);  //YELLOW LIGHT          //Cars
	HAL_LED_Init(GPIO_PORTA,GPIO_PIN2);  //GREEN LIGHT
	
	
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN0);  //RED LIGHT
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN1);  //YELLOW LIGHT          //People
	HAL_LED_Init(GPIO_PORTB,GPIO_PIN2);  //GREEN LIGHT
	
	/**< Inti Button */
 //HAL_PushButton_Init(GPIO_PORTB,GPIO_PIN3,ACTIVE_HIGH);
	
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_INPUT_PULL_DOWN_MOD);
	

	
	
	
	
	
	
	
	
	
	/*****************************************< Void Loop ****************************************/
	for(;;)
	{
		
		if(count==0)
		{
			HAL_LED_On(GPIO_PORTA,GPIO_PIN0);     //red cars
		  HAL_LED_On(GPIO_PORTB,GPIO_PIN2);     //green people
			MCAL_STK_SetDelay_ms(5000);
			count=(count+1)%3;
		}
		
		
		count=blinking();
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN1); //yellow off car
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN1); //yellow off people
		
		
		if(count==1)
		{
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN0);     //red cars
		  HAL_LED_Off(GPIO_PORTB,GPIO_PIN2);     //green people
				count=(count+1)%3;
		}
		
		
		
		
		if(count==2)
		{
			
			u32 num=500;
	    u32 counter;
	    u8 once=0;
	    u8 flag=0;
			u8 clock;
	  for( counter=0;counter<num;counter++)
			{
			HAL_LED_On(GPIO_PORTA,GPIO_PIN2);     //green cars
		  HAL_LED_On(GPIO_PORTB,GPIO_PIN0);     //red people
				
				if(MCAL_GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3,&value)==1)
					{
						if(value==1&&once>150)
						{
							flag=0;
							
						}
					
					 else if(value==1&&once<=150)
						{
							once++;
							
						}
						else if(value==0&&once>0&&once<=150)
						{
							flag=1;
						}
						
					}
					
					if (flag==1)
					{
						blinking();
						count=0;
						break;
					}
					
					MCAL_STK_SetDelay_ms(10);
					
			}
				if (flag==1)
				{
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN1); //yellow off car
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN1); //yellow off people
			
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);     //green cars
		  HAL_LED_Off(GPIO_PORTB,GPIO_PIN0);     //red people
					count=0;
				}
				
			
     if (flag==0)
		 {
			blinking();
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN1); //yellow off car
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN1); //yellow off people
			
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN2);     //green cars
		  HAL_LED_Off(GPIO_PORTB,GPIO_PIN0);     //red people
			
			count=(count+1)%3;
		}
	}
		
		
	}
	
	
}



			

u8 blinking()
{
	u32 num=500;
	u32 counter;
	u8 once=0;
	u8 flag=0;
	for( counter=0;counter<num;counter++)
			{
				if(counter==0||counter*10==1000||counter*10==2000||counter*10==3000||counter*10==4000)
				{
				HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN1);      //Yellow Cars
				HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN1);      //Yellow People
				}
				if(MCAL_GPIO_GetPinValue(GPIO_PORTB, GPIO_PIN3,&value)==1)
					{
						if(value==1&&once>150)
						{
							flag=0;
						}
					
					  if(value==1&&once<=150)
						{
							flag=1;
							once++;
						}
					}
					
					MCAL_STK_SetDelay_ms(10);
			}
			if (once==0)return count;
			else {
				if(flag==1)return 0;
				else return count;
				
			}
}








