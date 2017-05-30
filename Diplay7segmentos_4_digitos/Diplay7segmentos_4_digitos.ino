/* **
*arduino  display  segmento/digito                __f___
*  2        12          Izq                      |      |
*  3        9           Cent izq               e |      |a
*  4        6           der                      | __g_ |
*  5        8           cent der                 |      |
*  6        3            punto                 d |      |b
*  7        11          a                        |_____ |
*  8        7           b                          c       ° punto
*  9        4           c
*|10        2           d
*  11       1           e
*  12       10          f
*  13       5           g
*
* las conexiones 2,3,4,5 llevan resistencias 220 Ohms
*
*/

int pausa=1000; // Variable que define el intervalo
                // de tiempo entre cada digito
 
void setup()
{
  pinMode(2, OUTPUT); // Asignacion de digitos de salida
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);// punto decimal
  pinMode(7, OUTPUT);  // Asignación de las salidas digitales
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
 
void display (int a, int b, int c, int d, int e, int f, int g)
// Funcion del display
{
  digitalWrite (7,a);   //Se reciben 7 variables y se asignan
  digitalWrite (8,b);   //a cada una de las salidas
  digitalWrite (9,c);
  digitalWrite (10,d);
  digitalWrite (11,e);
  digitalWrite (12,f);
  digitalWrite (13,g);
}
 
void loop() //Funcion principal
// Dependiendo de cada dígito, se envía a la función display
// los estados (0 y 1) a cada uno de los segmentos
{
  digitalWrite (2,1);   // extrema izquierda
  digitalWrite (3,1); // centro izquierda
  digitalWrite (4,1);// extrema derecha
  digitalWrite (5,1); // centro derecha
  display (0,0,0,0,0,0,1); //escribe 0
  delay(pausa);
  display (1,0,0,1,1,1,1); //escribe 1
  delay(pausa);
  display (0,0,1,0,0,1,0); //escribe 2
  delay(pausa);
  display (0,0,0,0,1,1,0); //escribe 3
  delay(pausa);
  display (1,0,0,1,1,0,0); //escribe 4
  delay(pausa);
  display (0,1,0,0,1,0,0); //escribe 5
  delay(pausa);
  display (0,1,0,0,0,0,0); //escribe 6
  delay(pausa);
  display (0,0,0,1,1,1,1); //escribe 7
  delay(pausa);
  display (0,0,0,0,0,0,0); //escribe 8
  delay(pausa);
  display (0,0,0,1,1,0,0); //escribe 9
  delay(pausa);
}

