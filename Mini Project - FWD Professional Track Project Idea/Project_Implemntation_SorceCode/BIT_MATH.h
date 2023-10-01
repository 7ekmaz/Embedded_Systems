/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT_NO)         REG|= (1<< (BIT_NO))
#define CLR_BIT(REG,BIT_NO)         REG&= ~(1<< (BIT_NO))
#define TOGGLE_BIT(REG,BIT_NO)      REG^= (1<< (BIT_NO))
#define GET_BIT(REG,BIT_NO)        ((REG & (1<< (BIT_NO)))>>BIT_NO)      


#endif