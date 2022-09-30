#include "stm32f10x.h"
#include "MyTimer.h"

void MyTimer_Base_Init( MyTimer_Struct_TypeDef * Timer ) {
	MyTimer_Base_Start(Timer);
	//TIM2->CR1 |= TIM_CR1_ARPE ; //buffers ARR
	Timer->ARR |= (10000);
	Timer->PSC |= (3500);
}


