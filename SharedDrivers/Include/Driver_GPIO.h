#ifndef MYGPIO_H
#define MYGPIO_H

#include "stm32f10x.h"

typedef struct{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; // numero de 0 a 15
	char GPIO_Conf ; // voir ci dessous
} MyGPIO_Struct_TypeDef ;


#define In_Floating 	0 
#define In_PullDown 	1 
#define In_PullUp 		2 
#define In_Analog 		3 
#define Out_Ppull 		4 
#define Out_OD 				5 
#define AltOut_Ppull 	6 
#define AltOut_OD 		7 

void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr) ;
int MyGPIO_Read (GPIO_TypeDef * GPIO, char GPIO_Pin) ; //renvoie 0 ou autre chose different de 0
void MyGPIO_Set (GPIO_TypeDef * GPIO, char GPIO_Pin) ;
void MyGPIO_Reset (GPIO_TypeDef * GPIO, char GPIO_Pin) ;
void MyGPIO_Toggle (GPIO_TypeDef * GPIO, char GPIO_Pin) ;

#endif
