

#include "stm32f10x.h"
#include "Driver_GPIO.h"


int main (void) {
	MyGPIO_Struct_TypeDef LED;
	MyGPIO_Struct_TypeDef Bouton;
	//RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	// APB2ENR |= 0x00011100(soit 0x1C)
	// LED verte (LD2) = PA5 (pin 21) ou PB13 (pin 34), if HIGH, LED is on
	// User Button = I/O PC13 (pin 2)
	
	
	// Bouton poussoir externe sur PA1
	// LED externe sur PA0
	
	// Configure poussoir en floating input
	/*GPIOA->CRL = (GPIOA->CRL & ~(0x3 << 4)) | ((0x0 << 4)); // MODE1
	GPIOA->CRL = (GPIOA->CRL & ~(0x3 << 6)) | ((0x1 << 6)); // CNF1
		// Configure poussoir en input push pull
	GPIOA->CRL &= ~(3<<4);
	GPIOA->CRL |= (0<<4);
	GPIOA->CRL &= ~(3<<6);
	GPIOA->CRL |= (2<<6);
	
	
	// Configure LED en output push pull
	GPIOA->CRL = (GPIOA->CRL & ~(0x3 << 0)) | ((0x1 << 0)); // MODE0
	GPIOA->CRL = (GPIOA->CRL & ~(0x3 << 2)) | ((0x1 << 2)); // CNF0
	GPIOA->CRL &= ~(3<<0);
	GPIOA->CRL |= (1<<0);
	GPIOA->CRL &= ~(3<<2);
	GPIOA->CRL |= (0<<2);*/
	
	LED.GPIO = GPIOA;
	LED.GPIO_Conf = Out_Ppull;
	LED.GPIO_Pin = 0;

	MyGPIO_Init (&LED);
	
	
	Bouton.GPIO = GPIOA;
	Bouton.GPIO_Conf = In_PullUp;
	Bouton.GPIO_Pin = 1;

	MyGPIO_Init(&Bouton);
	
	
	//MyGPIO_Reset(GPIOA, 5);
	//MyGPIO_Toggle(GPIOA, 5);

	do {
		
		/*if ((GPIOA->IDR >> 1) & 0x1) {
			GPIOA->ODR |= 0x1;
		} else {
			GPIOA->ODR &= 0x0;
		}*/
		MyGPIO_Set(GPIOA, 6);
		MyGPIO_Set(GPIOA, 9);
		MyGPIO_Read(GPIOA, Bouton.GPIO_Pin);
		MyGPIO_Reset(GPIOA, 6);
		
		
		
	} while (1);
	
}
