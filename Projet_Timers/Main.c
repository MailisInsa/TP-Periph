

#include "stm32f10x.h"
#include "MyTimer.h"

MyTimer_Struct_TypeDef MyTimer;

int main (void) {
	
		
	MyTimer.Timer = TIM2;

	//TIM2->CR1 |= TIM_CR1_CEN; // enable counter
	//TIM2->CR1 |= TIM_CR1_ARPE ; //buffers ARR
	//TIM2->ARR |= (10200);
	//TIM2->PSC |= (3500);
	
	MyTimer_Base_Init(&MyTimer);

	
	//Gestion des interruptions
	//TIM2->DIER |= TIM_DIER_UIE; //enable le lancement des interruptions par le timer 2
	
	MyTimer_ActiveIT(MyTimer.Timer, 2);
	
	do {
	
	} while (1);
	
}


/*

void MyTimer_Base_Init( MyTimer_Struct_TypeDef * Timer ) {
	Timer->Timer->ARR |= (18000-1);
	Timer->Timer->PSC |= (2000-1);
	
	
	if (Timer->Timer == TIM2){  //Enables clock for TIM2
		RCC->APB1ENR |= (RCC_APB1ENR_TIM2EN);	
	} else if (Timer->Timer == TIM3) {  //Enables clock for TIM3
		RCC->APB1ENR |= (RCC_APB1ENR_TIM3EN);	
	} else if (Timer->Timer == TIM4) {  //Enables clock for TIM4
		RCC->APB1ENR |= (RCC_APB1ENR_TIM4EN);
	} else if (Timer->Timer == TIM1) {  //Enables clock for TIM1
		RCC->APB2ENR |= (RCC_APB2ENR_TIM1EN);
	}
	
	
	MyTimer_Base_Start(Timer->Timer);  //starts counter
	
	
}


void TIM2_IRQHandler(void) {
	TIM2->SR &= ~(TIM_SR_UIF);// descend le flag d'interruption
}
void TIM3_IRQHandler(void) {
	TIM3->SR &= ~(TIM_SR_UIF);
}
void TIM4_IRQHandler(void) {
	TIM4->SR &= ~(TIM_SR_UIF);
}




void MyTimer_ActiveIT ( TIM_TypeDef * Timer , char Prio ){
	//NVIC_EnableIRQ(IRQ number); 									fonction pour enable les interrupts au niveau du gestionnaire
	//NVIC_SetPriority(IRQ number,priority level);	fonction pour definir le niveau de priorité de l'interruption
	
	Timer->DIER |= TIM_DIER_UIE; //enable le lancement des interruptions par le timer
	
	if (Timer == TIM2){
		
		NVIC_EnableIRQ(TIM2_IRQn); //28 = position global interrupt TIM2
		NVIC_SetPriority(TIM2_IRQn,Prio);
		
	} else if (Timer == TIM3) {
		
		NVIC_EnableIRQ(TIM3_IRQn); //29 = position global interrupt TIM3
		NVIC_SetPriority(TIM3_IRQn,Prio);
		
	} else if (Timer == TIM4) {

		NVIC_EnableIRQ(TIM4_IRQn); //30 = position global interrupt TIM4
		NVIC_SetPriority(TIM4_IRQn,Prio);
		
	}
	
}	
	
*/
