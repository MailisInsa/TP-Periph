

#include "stm32f10x.h"
#include "MyTimer.h"

MyTimer_Struct_TypeDef MyTimer;
int compt;
int main (void) {
	RCC->APB1ENR |= (0x1);
	
	MyTimer.Timer = TIM2;

	//TIM2->CR1 |= TIM_CR1_CEN; // enable counter
	//TIM2->CR1 |= TIM_CR1_ARPE ; //buffers ARR
	//TIM2->ARR |= (10200);
	//TIM2->PSC |= (3500);
	
	MyTimer_Base_Init(&MyTimer);
	compt = 0;
	
	do {
		
		if (TIM2->CNT == 0x10) {
			compt = compt + 1;
		} 
				
	} while (1);
	
}
