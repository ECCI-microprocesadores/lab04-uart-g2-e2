#ifndef ADC_H
#define ADC_H

#include <xc.h>
#include <stdint.h>

void ADC_Init(void);
uint16_t ADC_Read(void);

#endif