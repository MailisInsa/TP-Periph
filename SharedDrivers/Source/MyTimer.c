#include "stm32f10x.h"
#include "MyTimer.h"

void MyTimer_Base_Init( MyTimer_Struct_TypeDef * Timer ) {
	TIM2->CR1 |= TIM_CR1_CEN;
	MyTimer_Base_Start(Timer->Timer);
	Timer->ARR |= (10000);
	Timer->PSC |= (3500);
}


