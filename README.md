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

 `main.c – Programa principal`

Aquí se inicia todo. Se configura el reloj interno del PIC a 16 MHz y se llama a la función UART_Init() para preparar la comunicación serial. Luego, en un bucle infinito, el microcontrolador envía cada segundo el mensaje “Hola, UART funcionando!” al puerto serial. Esto sirve como prueba de que la UART está funcionando correctamente. Puedes ver este mensaje en una terminal serial en tu PC (como PuTTY o el monitor serial de MPLAB X).
## Implmentación


