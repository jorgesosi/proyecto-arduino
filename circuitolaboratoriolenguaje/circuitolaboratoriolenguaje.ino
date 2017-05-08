//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// circuito laboratorio lenguaje
// 
// Made by Jorge Sosinowicz
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4821745-circuito-prueba

const int mov= 7;const int movled = 6;const int buz=5;const int luz =A0;const int rel= 4;const int luzled=1;int valormov=1;int valorluz=0;int valordist=0;const int pingPin = 11;unsigned int duration, inches;void setup() {  Serial.begin(9600);  pinMode(movled, OUTPUT);  pinMode (mov, INPUT);  pinMode(buz, OUTPUT);  pinMode (rel, OUTPUT);  pinMode(luz, INPUT);  }// the loop routine runs over and over again forever:void loop() {  int distant=0;  valormov=digitalRead(mov);  valorluz= analogRead(luz);  //valordist = digitalRead(eco);   //Serial.println(valormov);  //Serial.println(valorluz);pinMode(pingPin, OUTPUT); // Set pin to OUTPUTdigitalWrite(pingPin, LOW); // Ensure pin is lowdelayMicroseconds(2);digitalWrite(pingPin, HIGH); // Start rangingdelayMicroseconds(5); // with 5 microsecond burstdigitalWrite(pingPin, LOW); // End rangingpinMode(pingPin, INPUT); // Set pin to INPUTduration = pulseIn(pingPin, HIGH); // Read echo pulseinches = duration / 74 / 2; // Convert to inchesSerial.println(inches); // Display resultdelay(200); // Short delay//delay(500);   if (valormov == 0){    // Serial.println(valor);   //digitalWrite(buz, HIGH);    digitalWrite(movled, HIGH);  }  else{    //digitalWrite(buz,LOW);    digitalWrite(movled, LOW);  }  if (valorluz<=1016){ 		digitalWrite(rel,LOW); 	}  else{ 		digitalWrite(rel,HIGH);    }delay(200);  }     
