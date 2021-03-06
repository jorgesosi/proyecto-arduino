//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// circuito laboratorio lenguaje
// 
// Made by Jorge Sosinowicz
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4821745-circuito-laboratorio-lenguaje

#include <LiquidCrystal.h>const int mov= 7;const int movled = 6;const int buz=5;const int luz =A0;const int rel= 4;const int luzled=1;int valormov=1;int valorluz=0;int valordist=0;LiquidCrystal lcd(8, 9, 10,11, 12, 13);const int pingPin = 2;unsigned int duration, inches;void setup() {  lcd.begin(16, 2);  lcd.setCursor(0, 0);  lcd.print("Objeto a: ");  Serial.begin(9600);  pinMode(movled, OUTPUT);  pinMode (mov, INPUT);  pinMode(buz, OUTPUT);  pinMode (rel, OUTPUT);  pinMode(luz, INPUT);  }void loop() {	int distant=0; 	valormov=digitalRead(mov);  	valorluz= analogRead(luz);	pinMode(pingPin, OUTPUT); // Set pin to OUTPUT	digitalWrite(pingPin, LOW); // Ensure pin is low	delayMicroseconds(2);    digitalWrite(pingPin, HIGH); // Start ranging    delayMicroseconds(5); // with 5 microsecond burst    digitalWrite(pingPin, LOW); // End ranging    pinMode(pingPin, INPUT); // Set pin to INPUT    duration = pulseIn(pingPin, HIGH); // Read echo pulse    inches = duration / 29 / 2; // Convert to inches    Serial.println(inches); // Display result  	lcd.setCursor(0, 1);	lcd.print(inches); 	lcd.print(" cm");	delay(200); // Short delay	//delay(500);   	if (valormov == 0){    // Serial.println(valor);   //digitalWrite(buz, HIGH);    	digitalWrite(movled, HIGH);  	}  	else{    	//digitalWrite(buz,LOW);    	digitalWrite(movled, LOW);  	}  	if (valorluz<=1016){ 		digitalWrite(rel,LOW); 	}  	else{ 		digitalWrite(rel,HIGH);    }	delay(200);}     
