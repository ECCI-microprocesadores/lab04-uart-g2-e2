#include "adc.h"
#include <stdint.h>

void ADC_Init(void) {
    ADCON0 = 0x01;       // Canal AN0, ADC encendido
    ADCON1 = 0x0E;       // AN0 analógico, los demás digitales
    ADCON2 = 0xA9;       // Justificado a la derecha, Tacq = 4TAD, Fosc/8
}

uint16_t ADC_Read(void) {
    ADCON0bits.GO = 1;
    while (ADCON0bits.GO);
    return ((ADRESH <<8)|ADRESL);
}
