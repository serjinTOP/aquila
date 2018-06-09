
/* Código para teste dos sensores do robô ÁQUILA.
 * ROTINA: ler as distâncias de cada sensor e imprimir na SERIAL.
 */

 

/*
#include <SharpIR.h>

#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3

#define model 20150

boolean done = false;

SharpIR sharp1(ir1, 25, 93, model);
SharpIR sharp2(ir2, 25, 93, model);
SharpIR sharp3(ir3, 25, 93, model);
SharpIR sharp4(ir4, 25, 93, model);

int botao = 12;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
int velocidade = 0;

void backward()
{
  analogWrite(AIA, velocidade);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocidade);
  analogWrite(BIB, 0);
}

void forward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidade);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidade);
}

void setup() {
  Serial.begin(9600);
  pinMode (ir1, INPUT);
  pinMode (ir2, INPUT);
  pinMode (ir3, INPUT);
  pinMode (ir4, INPUT);

  pinMode(botao, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(botao, HIGH);
  digitalWrite(LED, LOW);

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  int velocidade = 0;
  forward();
}

void loop() {

  delay(20);    // it gives you time to open the serial monitor after you upload the sketch
  int dis1 = sharp1.distance(); // this returns the distance to the object you're measuring
  int dis2 = sharp2.distance();
  int dis3 = sharp3.distance();
  int dis4 = sharp4.distance();

  Serial.print("Sensores: ");  // returns it to the serial monitor
  Serial.print(dis1);
  Serial.print(" -- ");
  Serial.print(dis2);
  Serial.print(" -- ");
  Serial.print(dis3);
  Serial.print(" -- ");
  Serial.print(dis4);
  Serial.println(" -- ");

}

*/

