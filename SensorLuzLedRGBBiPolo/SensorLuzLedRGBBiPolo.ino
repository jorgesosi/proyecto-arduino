/*
*sensor pin A2 resistencia 1K Ohms
*cable hacia  A2 entre resistencia y sensor 
*led RGB pin D9 Resistencia 220
*Autor Jorge Sosinowicz
** */

const int PinLedVerde=9;
//const int PinLedRojo=10;
//const int PinLedAzul=11;
//const int PinEntradaLDR_Rojo=A0;
//const int PinEntradaLDR_Azul=A2;
const int PinEntradaLDR_Verde=A1;
//int ValorSensorRojo=0;
int ValorSensorVerde=0;
//int ValorSensorAzul=0;
//int ValorRojo=0;
int ValorVerde=0;
//int ValorAzul=0;
void setup() {
  Serial.begin(9600);
  pinMode(PinLedVerde,OUTPUT);
  //pinMode(PinLedRojo,OUTPUT);
  //pinMode(PinLedAzul,OUTPUT);
 }
void loop() {
//	ValorSensorRojo= analogRead(PinEntradaLDR_Rojo);
//  	delay(100);
//  ValorSensorAzul= analogRead(PinEntradaLDR_Azul);
//  	delay(100);
  ValorSensorVerde= analogRead(PinEntradaLDR_Verde);
  	delay(100); // wait for a second
  //Serial.print("Rojo: ");
  //Serial.print(ValorSensorRojo);
  //Serial.print(" Verde: ");
   //Serial.print(ValorSensorVerde); 
	//Serial.print(" Azul: ");
  //Serial.print(ValorSensorAzul);
  //Serial.print("\n");
  //ValorRojo=ValorSensorRojo/4;
  //ValorAzul=ValorSensorAzul/4;
  ValorVerde=ValorSensorVerde;
    //Serial.print("Rojo: ");
  //Serial.print(ValorRojo);
  Serial.print(" Verde: ");
  Serial.print(ValorVerde); 
  //Serial.print(" Azul: ");
  //Serial.print(ValorAzul);
  Serial.print("\n");
  //analogWrite(PinLedRojo,ValorRojo);
  //analogWrite(PinLedAzul,ValorAzul);
  analogWrite(PinLedVerde,ValorVerde);
}
