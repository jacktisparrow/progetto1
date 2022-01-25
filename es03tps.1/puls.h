#include "clock.h"
#include <string.h>
#include "stm32l4xx.h"                  // Device header
#include "Led.h"


int PA5check();
int PA1check();
void pulsecentraleinit(void);
void pulsesinistroInit(void);
void pulsedestroInit(void);
void pulsesopraInit(void);
void SwDownInit(void);
uint32_t pulseIn(char *pin , char stato);