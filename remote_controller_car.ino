#define servo = 13;
#define rx = 2;
#define tx = 3;
#include <SoftwareSerial.h>
// bibliotecas e variáveis globais
#include <Servo.h>
Servo esqdir;
Servo atk;
Servo def;
SoftwareSerial bluetooth(2, 3); // RX, TX
// variáveis
int joystick, pos, motor;
int button, cont = 0, b;
void setup()
{
    esqdir.attach(13);
    atk.attach(12);
    // inicializações
    def.attach(11);
    bluetooth.begin(9600);
    Serial.begin(9600);
}
void loop()
{
    if (bluetooth.available())
    {
        // variável “button” recebe a informação da porta 7 (botão).
        button = digitalRead(7);
        // variável que recebe uma leitura bluetooth
        joystick = bluetooth.read();
        // outra variável que recebe a mesma leitura
        motor = bluetooth.read();
        if (joystick == 'E')
        {
            // se variável bluetooth receber esta letra
            for (pos = 55; pos <= 110; pos += 1)
            {
                // o servo se movimenta para estas coordenadas
                esqdir.write(pos);
                delay(20);
            }
            digitalWrite(6, HIGH);
        }
        if (joystick == 'e')
        {
            for (pos = 110; pos >= 55; pos -= 1)
            {
                // o servo volta à posição inicial
                esqdir.write(pos);
                delay(20);
            }
            digitalWrite(6, LOW);
        }
        if (joystick == 'D')
        {
            // se variável bluetooth receber esta letra
            for (pos = 55; pos >= 0; pos -= 1)
            {
                // o servo se movimenta para estas coordenadas
                esqdir.write(pos);
                delay(20);
            }
            digitalWrite(6, HIGH);
        }
        if (joystick == 'd')
        {
            for (pos = 0; pos <= 55; pos += 1)
            {
                // o servo volta à posição inicial
                esqdir.write(pos);
                delay(20);
            }
            digitalWrite(6, HIGH);
        }
        if (motor == 'F')
        {
            // se variável bluetooth receber esta letra
            digitalWrite(6, HIGH);
            // liga-se o motor
        }
        if (motor == 'f')
            digitalWrite(6, LOW);
        if (joystick == 'A')
        {
            // se variável bluetooth receber esta letra
            for (pos = 0; pos <= 90; pos += 1)
            {
                // o servo se movimenta para estas coordenadas
                atk.write(pos);
            }
            for (pos = 90; pos >= 0; pos -= 1)
            {
                // o servo volta à posição inicial
                atk.write(pos);
                delay(15);
            }
        }
        if (joystick == 'B')
        {
            // se variável bluetooth receber esta letra
            for (pos = 0; pos <= 90; pos += 1)
            {
                // o servo se movimenta para estas coordenadas
                def.write(pos);
            }
            for (pos = 90; pos >= 0; pos -= 1)
            {
                // o servo volta à posição inicial
                def.write(pos);
                delay(15);
            }
        }
        // verifica se o botão foi pressionado.
        if (button == HIGH)
        {
            if (b == 0)
            {
                // caso tenha sido pressionado a variável “cont”(contador)
                adiciona um.cont++;
            }
            b = 1;
        }
        if (button == LOW)
        {
            b = 0;
        }
        // caso o contador esteja em zero o LED estará verde.
        if (cont == 0)
        {
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
        }
        // caso o contador esteja em um o LED estará azul.
        if (cont == 1)
        {
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
        }
        // caso o contador esteja em dois o LED estará vermelho.
        if (cont == 2)
        {
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
        }
        // caso o contador esteja em três o LED irá desligar.
        if (cont == 3)
        { // LED desliga
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
        }
        // caso o contador passe de 3 ele reseta.
        if (cont > 3)
        {
            cont = 0;
        }
    }
}
