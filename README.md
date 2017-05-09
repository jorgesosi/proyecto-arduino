# proyecto-arduino
Instituto Superior Capacitas.
----
**Carrera**: Técnico Superior en Desarrollo de Sistemas.

**Materia**: Laboratorio de Lenguaje (3do año)

**Año** :  2017
* Alumno: Jorge G. Sosinowicz.
* Docente: Lucas Passalacqua

Proyecto
-----
Ingredientes
-----
```
1 x Arduino Uno R3
1 x Light bulb Incandescent light bulb 12V / 3W 
1 x PIEZO 22mm DIAMETER
1 x led
1 x PIR Sensor  Passive infrared motion sensor
1 x Power Supply (simulador de corriente)
1 x Relay SPDT  5V SPDT
1 x Ambient Light Sensor [Phototransistor]
1 x Ultrasonic Distance Sensor
1 x LCD display 16x2
1 x Potentiometer 10k
1 x resistor 220 ohm
2 x resistor 1 kohm
```
Vista de componetes
-----

![imagen](https://github.com/jorgesosi/proyecto-arduino/blob/master/img/componentes.png)

Vista de esquema
-----

![imagen](https://github.com/jorgesosi/proyecto-arduino/blob/master/img/esquema.png)

Codigo fuente
-----
```
#include <LiquidCrystal.h>
const int mov= 7;
const int movled = 6;
const int buz=5;
const int luz =A0;
const int rel= 4;
const int luzled=1;
int valormov=1;
int valorluz=0;
int valordist=0;
LiquidCrystal lcd(8, 9, 10,11, 12, 13);
const int pingPin = 2;
unsigned int duration, inches;
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Objeto a: ");
  Serial.begin(9600);
  pinMode(movled, OUTPUT);
  pinMode (mov, INPUT);
  pinMode(buz, OUTPUT);
  pinMode (rel, OUTPUT);
  pinMode(luz, INPUT);
  
}
void loop() {
	int distant=0;
 	valormov=digitalRead(mov);
  	valorluz= analogRead(luz);
	pinMode(pingPin, OUTPUT); // Set pin to OUTPUT
	digitalWrite(pingPin, LOW); // Ensure pin is low
	delayMicroseconds(2);
    digitalWrite(pingPin, HIGH); // Start ranging
    delayMicroseconds(5); // with 5 microsecond burst
    digitalWrite(pingPin, LOW); // End ranging
    pinMode(pingPin, INPUT); // Set pin to INPUT
    duration = pulseIn(pingPin, HIGH); // Read echo pulse
    inches = duration / 29 / 2; // Convert to inches
    Serial.println(inches); // Display result
  	lcd.setCursor(0, 1);
	lcd.print(inches);
 	lcd.print(" cm");
	delay(200); // Short delay
	//delay(500); 
  	if (valormov == 0){
    // Serial.println(valor);
   	digitalWrite(buz, HIGH);
    	digitalWrite(movled, HIGH);
  	}
  	else{
    	digitalWrite(buz,LOW);
    	digitalWrite(movled, LOW);
  	}
  	if (valorluz<=1016){
 		digitalWrite(rel,LOW); 
	}
  	else{
 		digitalWrite(rel,HIGH);
    }
	delay(200);
}
```
Enlace al proyecto en 
[circuit.io](https://circuits.io/circuits/4821745-circuito-laboratorio-lenguaje)


