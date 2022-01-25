#include "stm32l4xx.h"                  // Device header
#include "led.h"
#include <stdint.h>
#include <stdio.h>
#include "arduino.h"

int PA1check(){
if((GPIOA->IDR & GPIO_IDR_ID1)==0)
		return 0 ;
	else 
		return 1 ;
	}

int PA5check(){	
	if((GPIOA->IDR & GPIO_IDR_ID5)==0)
		return 0 ;
	else 
		return 1 ;
	
	}

	void pulsecentraleinit(void){ 	//inizializzo pulsante centrale 	
RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 	
GPIOA->MODER &= ~GPIO_MODER_MODE0_0; 	
GPIOA->MODER &= ~GPIO_MODER_MODE0_1; 	
GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD0_0; 
GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_1;	
}
 void pulsesinistroInit(void){ 	//inizializzo pulsante sinistro 	
 RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
 GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
 GPIOA->MODER &= ~GPIO_MODER_MODE1_1;
 GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD1_0;
 GPIOA->PUPDR |= GPIO_PUPDR_PUPD1_1;
 } 
 void pulsedestroInit(void){ 	//inizializzo pulsante destro 	
 RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
 GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
 GPIOA->MODER &= ~GPIO_MODER_MODE2_1;
 GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD2_0;
 GPIOA->PUPDR |= GPIO_PUPDR_PUPD2_1;
 } 
 void pulsesopraInit(void){ 	//inizializzo pulsante superiore 	
 RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 
 GPIOA->MODER &= ~GPIO_MODER_MODE3_0; 
 GPIOA->MODER &= ~GPIO_MODER_MODE3_1; 
 GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD3_0; 
 GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_1; 
 } 
 void SwDownInit(void){ 	 //inizializzo pulsante inferiore 	
 RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 	
 GPIOA->MODER &= ~GPIO_MODER_MODE5_0; 	
 GPIOA->MODER &= ~GPIO_MODER_MODE5_1; 	
 GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5_0; 	
 GPIOA->PUPDR |= GPIO_PUPDR_PUPD5_1; 
 }
		
 
// 	uint32_t pulseIn(char *pin , char stato){
////		if(stato="HIGH")
////			stato=1;
////		else
////			stato=0;
//		uint32_t t0, tF , durata ;
//		t0=millis();
//		tF=t0;
//		do{
//				tF=millis();
//			durata=tF-t0;																																																											
//		}
//		while(PA5check()!=1 && durata<5000);
//			if(durata>5000)
//				return 0;
//			else
//				t0=millis();
//			while(PA5check()==1);
//			tF=millis();
//			return (tF-t0);
//}
		
	