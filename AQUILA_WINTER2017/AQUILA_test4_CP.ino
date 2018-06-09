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

int range1 = 45;
int range2 = 45;
int range3 = 45;
int range4 = 45;

int botao = 12;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;

int speedleft = 0;
int speedright = 0;

int start = 0;
int pisca = 0;

int time1 = 0;
int time2 = 0;

int memoria = 0;
int lastmemo = 0;

void seek() {
  dis1 = sharp1.distance();
  dis2 = sharp2.distance();
  dis3 = sharp3.distance();
  dis4 = sharp4.distance();
}

//AND

void backward() {
  analogWrite(AIA, 0);
  analogWrite(AIB, speedleft);
  analogWrite(BIA, 0);
  analogWrite(BIB, speedright);
}

void destroy() {
  analogWrite(AIA, speedright);
  analogWrite(AIB, 0);
  analogWrite(BIA, speedleft);
  analogWrite(BIB, 0);
}

void stopp() {
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
    delay(200);
    start = !start;
    pisca = !pisca;
    time1 = millis();
  }

  if (start == 0) {
    stopp();
    pisca = 0;
    memoria = 0;
    lastmemo = 0;
    digitalWrite(LED, LOW);
  }
  else if (start == 1) {
    digitalWrite(LED, HIGH);
    time2 = millis() - time1;
    while (time2 < 4800 && pisca == 1 ) {
      time2 = millis() - time1;
      stopp();
    }

    if (time2 < 4000) {
      range1 = 60;
      range2 = 60;
      range3 = 50;
      range4 = 50;
    }
    else {
      range1 = 45;
      range2 = 45;
      range3 = 45;
      range4 = 45;
    }

    pisca = 0;

    seek();

    if (dis3 <= range3 && dis4 <= range4) {
      if (dis2 < 20 && dis4 < 20) {
        speedleft = 255;
        speedright = 255;
      }
      else {
        speedleft = 180;
        speedright = 180;
      }
      destroy();
      memoria = 0;
    }
    else if (dis3 <= range3 && dis4 >= range4) {
      speedleft = 100;
      speedright = 20;
      destroy();
      memoria = 1;
    }
    else if (dis3 >= range3 && dis4 <= range4) {
      speedleft = 20;
      speedright = 100;
      destroy();
      memoria = -1;
    }
    else if (dis1 <= range1) {
      while (dis3 > range3 && dis4 > range4) {
        seek();
        speedleft = 0;
        speedright = 140;
        destroy();
        memoria = -2;
        if (digitalRead(botao) == LOW) {
          delay(200);
          start = !start;
          pisca = !pisca;
          time1 = millis();
          dis3 = range3;
        }
      }
    }
    else if (dis2 <= range2) {
      while (dis3 > range3 && dis4 > range4) {
        seek();
        speedleft = 140;
        speedright = 0;
        destroy();
        memoria = 2;
        if (digitalRead(botao) == LOW) {
          delay(200);
          start = !start;
          pisca = !pisca;
          time1 = millis();
          dis3 = range3;
        }
      }
    }

    //    else if (dis3 >= range3 && dis4 >= range4 && dis1 >= range1 && dis2 >= range2) {
    //      stopp();
    //    }


    //      else if (dis3 >= range3 && dis4 >= range4 && dis1 >= range1 && dis2 >= range2) {
    //        speedleft = 0;
    //        speedright = 100;
    //        destroy();
    //      }

    else if (dis3 >= range3 && dis4 >= range4 && dis1 >= range1 && dis2 >= range2) {

      //      if (memoria == 0) {
      //        speedleft = 100;
      //        speedright = 20;
      //        destroy();
      //      }

      if (memoria == 1) {
        speedleft = 100;
        speedright = 20;
        destroy();
      }
      if (memoria == -1) {
        speedleft = 20;
        speedright = 100;
        destroy();
      }
      if (memoria == 2) {
        speedleft = 140;
        speedright = 0;
        destroy();
      }
      if (memoria == -2) {
        speedleft = 0;
        speedright = 140;
        destroy();
      }
    }

  }
}



*/
