[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19508497&assignment_repo_type=AssignmentRepo)
# Lab04: Comunicación UART en PIC18F45K22

## Integrantes

[Maicol Linares](https://github.com/Maiik14)

[Ana Maria Zambrano](https://github.com/anazambranolozano)

[Sergio Florido](https://github.com/sergioflorido)

## Documentación

Este proyecto consiste en la implementación de una comunicación serial básica mediante el protocolo UART utilizando el PIC18F45K22. Con la finalidad de enviar información desde el PIC hacia el computador a través de un convertidor USB-TTL, mostrando mensajes por un programa de terminal.

También implementamos una simulación de comunicación UART utilizando el I2C, como una alternativa para casos donde los pines de UART requieran una comunicación entre múltiples dispositivos esclavos con un maestro único. Aunque UART e I2C son protocolos diferentes, este ejercicio nos permitió adaptar el comportamiento de UART al canal I2C de forma controlada, transmitiendo caracteres simulando una transmisión serial.

`Descripción del Funcionamiento`

Configuramos el oscilador interno del PIC a 16 MHz.

Habilitamos la comunicación UART a 9600 bps.

Se envío un mensaje de prueba (“Hola, UART funcionando!”).

En paralelo, implementamos un segundo canal de comunicación usando I2C simulando la funcionalidad de UART, enviando los mismos caracteres hacia un dispositivo esclavo que actúa como receptor

![DIAGRAMA UART](/imagenes/DIAGRAMA%20UART.png)

![SIMULACION UART](/imagenes/SIMULACION%20UART.png)

![UARTo](/imagenes/UARTO.png)

![UART](/imagenes/UART.jpg)

El microcontrolador envío los datos con una línea de código donde se extrajo solamente el número del voltaje. Luego de cada 100 milisegundos se ejecutó una función que revisó si llegó un dato nuevo y, si es así, lo pone en la gráfica, que muestra cómo va cambiando el voltaje con respecto al tiempo.

 `main.c – Programa principal`[main.c](/code/Main.c)

Configuramos el reloj interno del PIC a 16 MHz y llamamos a la función UART_Init() para preparar la comunicación serial. Luego, en un bucle infinito, el microcontrolador envió cada segundo el mensaje “Hola, UART funcionando!” al puerto serial.

También incluimos una llamada a UART_I2C_Send() para enviar el mismo mensaje a través del  I2C, utilizando la dirección de un esclavo previamente configurado. Esto permitió observar el mismo mensaje desde un segundo canal simulado, útil para monitoreo.


`uart.c y uart.h – Comunicación UART`
[uart.c](/code/uart.c) 
[uart.h](/code/uart.h)

Se configuró el pin de transmisión (TX) como salida y el de recepción (RX) como entrada. Se ajustó la velocidad de comunicación (9600 baudios) y se activaron tanto la transmisión como la recepción.

Las funciones incluidas permitieron enviar caracteres, cadenas de texto, números enteros y voltajes en decimales.

`adc.c y adc.h – Conversión Analógica-Digital` 
[adc.c](/code/adc.c)
[adc.h](/code/adc.h)


Se configuró el canal AN0 como entrada analógica y se activó el módulo ADC para obtener una medición. Al llamar a ADC_Read(), el sistema inició una lectura y esperó hasta que el resultado estuviese listo, devolviendo un número de 10 bits (de 0 a 1023), que representó la magnitud de la señal medida.



## Implementación

La implementación consistió en conectar el microcontrolador PIC18F45K22 con un adaptador USB-TTL para enviar mensajes desde el PIC. Se usaron los pines RC6 y RC7 para transmitir y recibir datos, y se alimentó el sistema con 5V. Una vez cargado el programa, el PIC comenzó a enviar cada segundo el mensaje “Hola, UART funcionando!”, el cual se pudo ver correctamente en el monitor serial.

Adicionalmente, el mismo mensaje lo enviamos por I2C a un dispositivo esclavo simulado, permitiendo comparar ambos canales.

[Video de Uart.mp4](/Video%20de%20Uart.mp4)


