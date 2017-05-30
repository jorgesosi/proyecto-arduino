/*
*sensor pin A0 resistencia 1K Ohms
* 
*3 X led  pin D2,3,4 3XResistencia 220
*
** */
const int pinSensor = A0;
const float TempRef = 25.0;

// the setup routine runs once when you press reset:
void setup() {
  // inicializa el puerto serie para ver datos en la ide
  Serial.begin(9600);
  // initialize the digital pin as an output.
  for(int numeroPin=2; numeroPin< 5; numeroPin++){
   pinMode(numeroPin, OUTPUT); 
    digitalWrite(numeroPin, LOW);
  }
  
}

// the loop routine runs over and over again forever:
void loop() {
  int valorSensor= analogRead(pinSensor);
  Serial.print("el valor del sensor es: ");
  Serial.print (valorSensor);
  float tension = (valorSensor)*(5.0/1024.0);
  Serial.print(",Voltios: ");
  Serial.print(tension);
  float temperatura=(tension *100)- 2.5;
  Serial.print(",Grados: ");
  Serial.println(temperatura);
  	if (temperatura <TempRef ){
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    }else if(temperatura >= TempRef+2 && temperatura <TempRef+4){
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
    }else if(temperatura >= TempRef+4 && temperatura < TempRef+6){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
    }else if(temperatura >= TempRef+6){
      digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
    }
  	delay(1000);
  }
