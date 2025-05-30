[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19508497&assignment_repo_type=AssignmentRepo)
# Lab04: Comunicación UART en PIC18F45K22

## Integrantes

[Maicol Linares](https://github.com/Maiik14)

[Ana Maria Zambrano](https://github.com/anazambranolozano)

[Sergio Florido](https://github.com/sergioflorido)

## Documentación

Este proyecto consiste en la implementación de una comunicación serial básica mediante el protocolo UART (Universal Asynchronous Receiver Transmitter) usando el microcontrolador PIC18F45K22. La finalidad es enviar información desde el PIC hacia una computadora a través de un convertidor USB-TTL, mostrando mensajes por un programa de terminal.

`Descripción del Funcionamiento`

-Se configura el oscilador interno del PIC a 16 MHz.

-Se habilita la comunicación UART a 9600 bps.

-Se transmite un mensaje de prueba (“Hola, UART funcionando!”) cada segundo.

-El mensaje puede observarse en un programa terminal conectado a la PC.

 `main.c – Programa principal`[main.c](/code/Main.c)

Aquí se inicia todo. Se configura el reloj interno del PIC a 16 MHz y se llama a la función UART_Init() para preparar la comunicación serial. Luego, en un bucle infinito, el microcontrolador envía cada segundo el mensaje “Hola, UART funcionando!” al puerto serial. Esto sirve como prueba de que la UART está funcionando correctamente. 

`uart.c y uart.h – Comunicación UART`
[uart.c](/code/uart.c) 
[uart.h](/code/uart.h)

Este módulo permite que el microcontrolador se comunique con el computador u otro dispositivo a través del puerto serial (UART). Primero, se configura el pin de transmisión (TX) como salida y el de recepción (RX) como entrada. Se ajusta la velocidad de comunicación (9600 baudios) y se activan tanto la transmisión como la recepción. Además, se habilitan las interrupciones para que el microcontrolador pueda reaccionar cuando llega un dato. Las funciones incluidas permiten enviar caracteres individuales, cadenas de texto completas, números enteros (como texto) y voltajes en formato decimal, facilitando una comunicación clara y ordenada con el usuario o un programa de monitoreo en el PC.

`adc.c y adc.h – Conversión Analógica-Digital` 
[adc.c](/code/adc.c)
[adc.h](/code/adc.h)


Este módulo convierte señales analógicas, como las de sensores, en valores numéricos que el microcontrolador puede entender. Se configura el canal AN0 como entrada analógica y se activa el módulo ADC con parámetros adecuados para obtener una medición precisa. Al llamar a ADC_Read(), el sistema inicia una lectura y espera hasta que el resultado esté listo, devolviendo un número de 10 bits (de 0 a 1023), que representa la magnitud de la señal medida.

## Implementación

La implementación consistió en conectar el microcontrolador PIC18F45K22 con un adaptador USB-TTL para enviar mensajes desde el PIC hacia la computadora. Se usaron los pines RC6 y RC7 para transmitir y recibir datos, y se alimentó el sistema con 5V. Una vez cargado el programa, el PIC comenzó a enviar cada segundo el mensaje “Hola, UART funcionando!”, el cual se pudo ver correctamente en el monitor serial del computador. Esto confirmó que la comunicación estaba funcionando bien y de forma estable.

[Video de Uart.mp4](/Video%20de%20Uart.mp4)
