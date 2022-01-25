/** ****************************************************************************************
* @file <led.h>
* @brief <Dichiarazione delle librerie utilizzate per i led>
* 
* @author <Alessandro Restelli 5L>
* @date <28/9/2021> 
* @version 1.0 <28/9/2021> <Prima versione del file led.h>
* @version 1.1 <> <>
*/

/*File con dichiarazione del prototipo
  delle funzioni utilizzate */

//Prototipi delle funzioni
void LedInit(void); 						//Inizializzazione entrambi led
void LedOn(void);								//Accensione entrambi led	
void LedBlink(int led, int nLamp, int ms);			//Funzione Blink con passaggio di parametri: led e n° lampeggi

//Funzioni SysTick
void SystickInit(void);
void DelaySystick1Ms(int ms);

//Funzioni led Rosso
void LedRedInit(void);						//Inizializzazione
void LedRedOn(void);						//Accensione
void LedRedOff(void);						//Spegnimento 
void LedRedToggle(void);					//Inversione stato
void LedRedBlink(int nLamp, int ms);					//Lampeggio
int LedRedCheck(void);
void LedRedTask(int Ton, int t);

//Funzioni led Verde
void LedGreenInit(void);					//Inizializzazione
void LedGreenOn(void);						//Accensione
void LedGreenOff(void);						//Spegnimento 
void LedGreenToggle(void);					//Inversione stato
void LedGreenBlink(int nLamp, int ms);					//Lampeggio
void LedGreenTask (int Ton, int t);
int LedGreenCheck(void);
void LedRedTask(int Ton, int t);



