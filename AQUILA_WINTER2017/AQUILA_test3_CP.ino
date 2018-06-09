
/* Código para teste da resposta dos motores em função da leitura dos sensores.
   ROTINA: ler as distâncias de cada sensor;
           Ir frente se obter leitura em ambos sensores centrais;
           Girar direita se obter leitura no sensor da lateral direita;
           Girar esquerda se obter leitura no sensor da lateral esquerda.
   Giro em função de delay estabelecido (200ms).
*/
/*

#include <SharpIR.h>

#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3

#define model 20150

boolean done = false;

SharpIR sharp1(ir1, 25, 93, model);   //ESQUERDA
SharpIR sharp2(ir2, 25, 93, model);   //DIREITA
SharpIR sharp3(ir3, 25, 93, model);   //FRENTE DIREITA
SharpIR sharp4(ir4, 25, 93, model);   //FRENTE ESQUERDA

int botao = 12;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
int velocidade = 0;
int start = 0;


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
void left()
{
  analogWrite(AIA, velocidade);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidade);
}
void right()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidade);
  analogWrite(BIA, velocidade);
  analogWrite(BIB, 0);
}
void stopp()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
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

  int dis1 = sharp1.distance();
  int dis2 = sharp2.distance();
  int dis3 = sharp3.distance();
  int dis4 = sharp4.distance();

  stopp();

}

void loop() {

  if (digitalRead(botao) == LOW) {
    stopp();
    Serial.println("apertou");
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
    delay(1000);
    start = !start;
  }

  if (start == 0) {
    digitalWrite(LED, LOW);
  }

  if (start == 1) {

    digitalWrite(LED, HIGH);
    int dis1 = sharp1.distance();
    int dis2 = sharp2.distance();
    int dis3 = sharp3.distance();
    int dis4 = sharp4.distance();

    if (dis3 >= 40 || dis4 >= 40) {
      if (dis1 <= 30) {
        velocidade = 100;
        left();
        delay(200);
      }
      if (dis2 <= 30) {
        velocidade = 100;
        right();
        delay(200);
      }
    }
    if (dis3 <= 40 && dis4 <= 40) {
      velocidade = 70;
      forward();
    }
    if (dis3 >= 40 && dis4 >= 40 && dis1 >= 30 && dis2 >= 30) {
      stopp();
    }
  }
}

*/

