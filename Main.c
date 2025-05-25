#include <xc.h>
#include "uart.h"
#include "adc.h"
#include <stdio.h> // Para sprintf

#pragma config FOSC = INTIO67   // Oscilador interno
#pragma config WDTEN = OFF      // Watchdog Timer apagado
#pragma config LVP = OFF        // Low Voltage Programming off

#define VREF 5.0 // Voltaje de referencia del ADC (ajusta según tu circuito)
#define ADC_RESOLUTION 1024.0 // Resolución del ADC (10 bits)

void main(void) {
    OSCCON = 0b01110000;    // Oscilador interno a 16MHz
    UART_Init();            // Inicializa UART
    ADC_Init();             // Inicializa ADC

    while(1) {
        uint16_t adcValue = ADC_Read();
        float voltage = (adcValue * VREF) / ADC_RESOLUTION;
        char voltageString[20]; // Buffer para almacenar el string del voltaje

        sprintf(voltageString, "Voltaje: %.2f V\r\n", voltage);
        UART_WriteString(voltageString);
        __delay_ms(1000);
    }
}