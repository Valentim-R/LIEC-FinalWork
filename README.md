# Português
# Controle de carrinho via Bluetooth

Este código permite controlar um carrinho de controle remoto com o celular via bluetooth controlando tambem um pistão feito usando um servo motor para dar "socos" e lutar contra um igual a si ja que o mesmo tem um sistema de vidas e um indicador LED RGB. O código está escrito em C++ e foi desenvolvido para ser utilizado com a placa Arduino.

## Pré-requisitos

Antes de utilizar esse código, certifique-se de ter o seguinte:

- Placa Arduino
- Módulo Bluetooth
- Servo motor

## Configuração

Certifique-se de conectar corretamente os componentes ao Arduino. Você precisará conectar o servo motor aos pinos correspondentes definidos no código. Além disso, conecte o módulo Bluetooth aos pinos RX e TX do Arduino.

## Bibliotecas

Este código utiliza as seguintes bibliotecas:

- `Servo.h`: Biblioteca para controlar o servo motor.
- `SoftwareSerial.h`: Biblioteca para comunicação serial com o módulo Bluetooth.

Certifique-se de instalar essas bibliotecas antes de compilar o código.

## Instruções

1. Carregue o código para o Arduino utilizando a IDE do Arduino.
2. Certifique-se de ter um dispositivo Bluetooth conectado ao módulo Bluetooth.
3. Abra um terminal serial na velocidade de 9600 bps.
4. Envie comandos a partir do dispositivo Bluetooth para controlar o servo motor.

## Comandos

Os seguintes comandos são utilizados para controlar o servo motor:

- `E`: Move o servo motor para a posição esquerda.
- `e`: Move o servo motor para a posição inicial após ser movido para a esquerda.
- `D`: Move o servo motor para a posição direita.
- `d`: Move o servo motor para a posição inicial após ser movido para a direita.
- `F`: Liga o motor.
- `f`: Desliga o motor.
- `A`: Move o servo motor de ataque.
- `B`: Move o servo motor de defesa.

Além disso, existe um botão conectado ao pino 7 que permite incrementar um contador. O LED conectado aos pinos 8, 9 e 10 indica o valor do contador da seguinte forma:

- Contador 0: LED verde aceso.
- Contador 1: LED azul aceso.
- Contador 2: LED vermelho aceso.
- Contador 3: LED desligado.

Caso o contador ultrapasse o valor 3, ele será reiniciado para 0.

## Contribuição

Sinta-se à vontade para contribuir com melhorias e correções para esse código.


# English
# Bluetooth Controlled Car

This code allows you to control a remote-controlled car using your cellphone via Bluetooth. It also controls a punching mechanism using a servo motor to fight against another similar car, as they both have a life system and an RGB LED indicator. The code is written in C++ and was developed to be used with an Arduino board.

## Prerequisites

Before using this code, make sure you have the following:

- Arduino board
- Bluetooth module
- Servo motor

## Setup

Make sure to properly connect the components to the Arduino. You'll need to connect the servo motor to the specified pins as defined in the code. Additionally, connect the Bluetooth module to the RX and TX pins of the Arduino.

## Libraries

This code uses the following libraries:

- `Servo.h`: Library for controlling the servo motor.
- `SoftwareSerial.h`: Library for serial communication with the Bluetooth module.

Make sure to install these libraries before compiling the code.

## Instructions

1. Upload the code to the Arduino using the Arduino IDE.
2. Make sure you have a Bluetooth device connected to the Bluetooth module.
3. Open a serial terminal at a baud rate of 9600.
4. Send commands from the Bluetooth device to control the servo motor.

## Commands

The following commands are used to control the servo motor:

- `E`: Moves the servo motor to the left position.
- `e`: Moves the servo motor to the initial position after being moved to the left.
- `D`: Moves the servo motor to the right position.
- `d`: Moves the servo motor to the initial position after being moved to the right.
- `F`: Turns on the motor.
- `f`: Turns off the motor.
- `A`: Moves the attack servo motor.
- `B`: Moves the defense servo motor.

Additionally, there is a button connected to pin 7 that allows incrementing a counter. The LED connected to pins 8, 9, and 10 indicates the value of the counter as follows:

- Counter 0: Green LED on.
- Counter 1: Blue LED on.
- Counter 2: Red LED on.
- Counter 3: LED off.

If the counter exceeds 3, it will be reset to 0.

## Contribution

Feel free to contribute with improvements and fixes to this code.
