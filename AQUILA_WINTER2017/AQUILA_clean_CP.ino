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

int dis1 = 0;
int dis2 = 0;
int dis3 = 0;
int dis4 = 0;

int range1 = 40;
int range2 = 40;
int range3 = 60;
int range4 = 60;

int botao = A5;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;

int speedleft = 0;
int speedright = 0;

int start = 0;

int time1 = 0;
int time2 = 0;


void search() {
  dis1 = sharp1.distance();
  dis2 = sharp2.distance();
  dis3 = sharp3.distance();
  dis4 = sharp4.distance();
}

//AND

void destroy() {
  analogWrite(AIA, 0);
  analogWrite(AIB, speedleft);
  analogWrite(BIA, 0);
  analogWrite(BIB, speedright);
}

void backward() {
  analogWrite(AIA, speedleft);
  analogWrite(AIB, 0);
  analogWrite(BIA, speedright);
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

//  stopp();

}

void loop() {

  if (digitalRead(botao) == LOW) {
    delay(200);
    if (start == 0) {
      start = 1;
    }
    else if (start == 1) {
      start = 0;
    }
    time1 = millis();
  }

  if (start == 0) {
    speedleft = 0;
    speedright = 0;
    destroy();
    digitalWrite(LED, LOW);
  }
  else if (start == 1) {
    digitalWrite(LED, HIGH);
    speedleft = 150;
    speedright = 150;
    backward();
  }
}
*/


