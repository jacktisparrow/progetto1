#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"   
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "queue.h"                      // ARM.FreeRTOS::RTOS:Core
#include <stdio.h>
#include "led.h"
#include "clock.h"
#include "Arduino.h"


char stato=0; //variabile  globale 
                // ARM.FreeRTOS::RTOS:Core
//TaskHandle_t xGreen;
//QueueHandle_t xCoda;
void vTask_LED_rosso(void * pvParameters);
void vTask_LED_verde(void * pvParameters);
void vTask_Aumento_velocita(void * pvParameters);
void vTask_PA1(void * pvParameters);
void vTask_LCD(void * pvParameters);

void vHardware_config(void){


//	pinModeEx(PA0,INPUT,PULLDOWN);

//	LCD_Initialization();
}
int main(void){
		
	pinMode(PB2,OUTPUT);//inizializzazione led rosso 
	pinMode(PE8,OUTPUT); //inizializzazione led verde
	pinModeEx(PA1,INPUT,PULLDOWN);//inizializzazione pulsante sinistro in pull down 
	pllInit(0,10,0); //modiofica frequenza clock
	
	xTaskCreate(vTask_LED_rosso, /* Pointer to the function that implements the task.              */
		"Task 1 (Toggle LED rosso)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
	
	xTaskCreate(vTask_LED_verde, /* Pointer to the function that implements the task.              */
		"Task 1 (Toggle LED verde)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
	
	
	xTaskCreate(vTask_Aumento_velocita, /* Pointer to the function that implements the task.              */
		"Task 1 (Aumento_velocita)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
//	xTaskCreate(vTask_PA1, /* Pointer to the function that implements the task.              */
//		"Task 1 (Toggle LED verde)",    /* Text name for the task.  This is to facilitate debugging only. */
//		50,   /* Stack depth in words.                */
//		NULL,  /* We are not using the task parameter. */
//		1,     /* This task will run at priority 1.    */
//		NULL); /* We are not using the task handle.    */
////	xTaskCreate(vTask_LCD, /* Pointer to the function that implements the task.              */
////		"Task 1 (Toggle LED verde)",    /* Text name for the task.  This is to facilitate debugging only. */
////		50,   /* Stack depth in words.                */
////		NULL,  /* We are not using the task parameter. */
////		1,     /* This task will run at priority 1.    */
////		NULL); /* We are not using the task handle.    */
////	xCoda=xQueueCreate(4,sizeof(int));
	vTaskStartScheduler();
	
	
}
void vTask_LED_rosso(void * pvParameters){
	while(1){
	LedRedToggle();
		vTaskDelay(500);
	}
}
void vTask_LED_verde(void * pvParameters){
	while(1){
		LedGreenToggle();
		if(stato==0)
			vTaskDelay(500);
		else 
			vTaskDelay(50);
}


void vTask_Aumento_velocita(void * pvParameters){
while(1){
		while(!digitalRead(PA1)); //controllo stato ,pulsante non premuto 
		while(digitalRead(PA1)); //controllo stato ,pulsante premuto 
		stato=!stato; //inverto variabile globale 
}

//void vTask_PA1(void * pvParameters){
////	while(1){
//		//while(!digitalRead(PA1));
//		//while(digitalRead(PA1));
////		vTaskResume(xGreen);
////	}
//	
//}

//void vTask_LCD(void * pvParameters){
////  int val;
////	char dis[6]="";
////	while(1){
////	  xQueueReceive(xCoda,&val,portMAX_DELAY);
////		sprintf(dis,"%d",val);
////		//LCD_Clear();
////		//LCD_DisplayString((uint8_t *)dis);
////	
////	}
//}



