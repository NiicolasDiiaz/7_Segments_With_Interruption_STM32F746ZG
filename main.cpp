#include <stdio.h>
#include "STM32F7xx.h"

int numeros[10]={126,48,109,121,51,91,95,112,127,115};
int c=0;
int i=0;
int tiempo=50000;
int pulsador=1; 

int main (void){
	
	RCC->AHB1ENR=0x4; //PTC
	
	GPIOC->MODER=0x1555;
	GPIOC->OTYPER=0;
	GPIOC->OSPEEDR=0x1555;
	GPIOC->PUPDR=0;
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock);
	
	while (true){
		
		if ((GPIOC-> IDR & 0x2000)==0x2000){
			for(int c=0;c<tiempo;c++);
			pulsador++;
		}
		GPIOC->ODR=numeros[i];
		
	}
}

extern "C" {
	void SysTick_Handler (void){	
		if(pulsador%2 == 0){
			i++;
			if(i==10){i=0;}
		}
	}
}