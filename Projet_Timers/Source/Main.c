

#include "stm32f10x.h"



int main (void) {
	RCC->APB1ENR |= (0x1);
	

	TIM2->CR1 |= 1; // enable counter
	TIM2->CR1 |= (1<<7); //enable ARR
	TIM2->ARR |= (10200);
	TIM2->PSC |= (3500);
	do {
		
		if ((GPIOA->IDR >> 1) & 0x1) {
			GPIOA->ODR |= 0x1;
		} else {
			GPIOA->ODR &= 0x0;
		}
		
		
		
	} while (1);
	
}
