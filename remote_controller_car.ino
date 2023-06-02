#include <SoftwareSerial.h>
#include <Servo.h>
#define rx = 2
#define tx = 3
Servo esqdir;
SoftwareSerial bluetooth(2, 3);  // RX, TX
int joystick, pos, dc = 100;
#define AIB 7  // Direção motor A
#define AIA 9  // PWM A


void setup() {
  pinMode(AIB, OUTPUT);
  pinMode(AIA, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  esqdir.attach(13);
  bluetooth.begin(9600);
  Serial.begin(9600);
  for (pos = 200; pos >= 60; pos -= 1) {
    // o servo volta à posição inicial
    esqdir.write(pos);
    delay(2);
  }
  for (pos = 0; pos <= 60; pos += 1) {
    // o servo volta à posição inicial
    esqdir.write(pos);
    delay(2);
  }
}

void loop() {
  if (bluetooth.available()) {
    joystick = bluetooth.read();
    if (joystick == 'D') {
      //se variável bluetooth receber esta letra
      for (pos = 60; pos <= 85; pos += 1) {
        // o servo se movimenta para estas coordenadas
        esqdir.write(pos);
        delay(2);
      }
      dc = dc * 2.55;  // Duty Cycle %
      analogWrite(AIA, 255 - dc);
      digitalWrite(AIB, HIGH);
    }

    if (joystick == 'd') {
      digitalWrite(6, LOW);
      for (pos = 110; pos >= 60; pos -= 1) {
        // o servo volta à posição inicial
        esqdir.write(pos);
        delay(2);
      }
      analogWrite(AIA, 0);
      digitalWrite(AIB, LOW);
    }

    if (joystick == 'E') {
      //se variável bluetooth receber esta letra
      for (pos = 60; pos >= 25; pos -= 1) {
        // o servo se movimenta para estas coordenadas
        esqdir.write(pos);
        delay(2);
      }
      dc = dc * 2.55;  // Duty Cycle %
      analogWrite(AIA, 255 - dc);
      digitalWrite(AIB, HIGH);
    }
    if (joystick == 'e') {
      for (pos = 0; pos <= 60; pos += 1) {
        // o servo volta à posição inicial
        esqdir.write(pos);
        delay(2);
      }
      analogWrite(AIA, 0);
      digitalWrite(AIB, LOW);
    }
    if (joystick == 'F') {
      dc = dc * 2.55;  // Duty Cycle %
      analogWrite(AIA, 255 - dc);
      digitalWrite(AIB, HIGH);
    }
    if (joystick == 'f') {
      analogWrite(AIA, 0);
      digitalWrite(AIB, LOW);

    }

    if (joystick == 'H') {
      dc = dc * 2.55;  // Duty Cycle %
      analogWrite(AIA, 255);
      digitalWrite(AIB, LOW);

    }
    if (joystick == 'h') {
      analogWrite(AIA, 0);
      digitalWrite(AIB, LOW);

    }
  }
}

