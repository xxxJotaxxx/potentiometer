#include <Arduino.h>

//Lectura básica del valor del potenciómetro
/*-------------------------------------------------------------------------------
    //Creamos una variable de tipo entero
    int lectura = 0;

    void setup() {
      //Iniciamos la comunicación serial
      Serial.begin(9600);
    }

    void loop() {
      //Tomamos la lectura analógica del pin al cual conectamos
      //la señal de nuestro pot y la guadamos en una variable
      lectura = analogRead(0);

      //Imprimimos por monitor serie el valor 
      Serial.println(lectura);

      delay(100);
    }
-------------------------------------------------------------------------------*/

//Cambiamos la intensidad de un led con el potenciometro
//Creamos una variable de tipo entero
int lectura = 0;
//the pins that can be used for PWM are fixed in Arduino.
//PWM output is only available with pins that have a “~” mark next to the number (that is, 3, 5, 6, 9, 10, and 11). Note that the other pins do not support PWM output.
int pinLed = 3; //tego que conectar el led a un pin PWM que permite analogWrite
int brilloMap = 0;

void setup()
{
  //Iniciamos la comunicación serial
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  //Tomamos la lectura analógica del pin al cual conectamos
  //la señal de nuestro pot y la guadamos en una variable
  lectura = analogRead(0);
  //Serial.println(lectura);

  //como el valor leido del potenciometro esta entre 0 y 1024 y analogWrite acepta entre 0 y 255
  brilloMap = map(lectura, 0, 1023, 0, 255);
  Serial.println(brilloMap);
  analogWrite(pinLed, brilloMap);

  delay(10);
}

//analogWrite(pin, value)
//  pin: the Arduino pin to write to. Allowed data types: int.
//  value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int.