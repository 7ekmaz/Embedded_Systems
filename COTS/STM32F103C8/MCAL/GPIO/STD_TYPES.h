/*****************************************************/
/************Autho  Kareem Wael Elhamy****************/
/************Date:8/29/2023***************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
typedef unsigned char        u8;
typedef unsigned short int   u16;
typedef unsigned  int        u32;
typedef unsigned long int    u64;



typedef signed char          s8;
typedef signed short int     s16;
typedef signed long int      s32;
typedef signed long int      s64;


typedef float                f32;
typedef double               f64;
typedef long double          f128;



typedef u8                  Std_ReturnType;

#define E_OK                (Std_ReturnType)1
#define E_NOT_OK            (Std_ReturnType)0

#define NULL        (void *)(0x0)



#endif