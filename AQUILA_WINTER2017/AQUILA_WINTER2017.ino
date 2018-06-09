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

unsigned int dis1 = 0;
unsigned int dis2 = 0;
unsigned int dis3 = 0;
unsigned int dis4 = 0;

int range1 = 45;
int range2 = 45;
int range3 = 45;
int range4 = 45;

int botao = A5;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;

int speedright = 0;
int speedleft = 0;

int start = 0;
int pisca = 0;
int showest = 0;

int time1 = 0;
int time2 = 0;
int time3 = 0;

int memoria = 0;
int estrategia = 0;

unsigned int recebido = 0;

//----------------------------------------------------------Rotinas

void seek() {
  dis1 = sharp1.distance();
  dis2 = sharp2.distance();
  dis3 = sharp3.distance();
  dis4 = sharp4.distance();
}

//AND

void destroy() {
  analogWrite(AIA, speedleft);
  analogWrite(AIB, 0);
  analogWrite(BIA, speedright);
  analogWrite(BIB, 0);
}

void go() {
  int aa = 0;
  int ab = 0;
  int ba = 0;
  int bb = 0;

  if (speedleft >= 0) {
    aa = speedleft;
    ab = 0;
  }
  else {
    aa = 0;
    ab = -speedleft;
  }

  if (speedright >= 0) {
    ba = speedright;
    bb = 0;
  }
  else {
    ba = 0;
    bb = -speedright;
  }
  analogWrite(AIA, ab);
  analogWrite(AIB, aa);
  analogWrite(BIA, bb);
  analogWrite(BIB, ba);
}



void backward() {
  analogWrite(AIA, 0);
  analogWrite(AIB, speedright);
  analogWrite(BIA, 0);
  analogWrite(BIB, speedleft);
}

void stopp() {
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}

void indicar(int est) {
  if (showest == 0) {
    showest = 1;
    delay(300);
    if (est == 1) {
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }
    else if (est == 2) {
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }
    else if (est == 3) {
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      delay(100);
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
    }
  }
}

//------------------------------------------------------------------------------------Estratégias

//-----------------------------------------------------------------------Estratégia01

void estrategia01() {

  range1 = 45;
  range2 = 45;
  range3 = 45;
  range4 = 45;


  seek();

  if (dis3 <= range3 && dis4 <= range4) {   // FRENTE FRENTE
    if (dis3 < 20 && dis4 < 20) {
      speedright = 0;
      speedleft = 0;
    }
    else {
      speedright = 0;
      speedleft = 0;
    }
    go();
    memoria = 0;
  }
  else if (dis3 <= range3 && dis4 >= range4) {   // FRENTE DIREITA
    speedright = 100;
    speedleft = -100;
    go();
    memoria = 1;
  }
  else if (dis3 >= range3 && dis4 <= range4) {   // FRENTE ESQUERDA
    speedright = -100;
    speedleft = 100;
    go();
    memoria = -1;
  }
  else if (dis1 <= range1) {                    //   ESQUERDA
    while (dis3 > range3 && dis4 > range4) {
      seek();
      speedright = -100;
      speedleft = 100;
      go();
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
  else if (dis2 <= range2) {                    //   DIREITA
    while (dis3 > range3 && dis4 > range4) {
      seek();
      speedright = 100;
      speedleft = -100;
      go();
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

  else if (dis3 >= range3 && dis4 >= range4 && dis1 >= range1 && dis2 >= range2) {
    if (memoria == 1) {
      speedright = 100;
      speedleft = -100;
      go();
    }
    if (memoria == -1) {
      speedright = -100;
      speedleft = 100;
      go();
    }
    if (memoria == 2) {
      speedright = 200;
      speedleft = -200;
      go();
    }
    if (memoria == -2) {
      speedright = -200;
      speedleft = 200;
      go();
    }
  }
}

//-----------------------------------------------------------------------Estratégia02

void estrategia02() {

  speedright = 100;
  speedleft = -100;
  go();
  delay(1000);

  speedright = -100;
  speedleft = 100;
  go();
  delay(1000);

}

//-----------------------------------------------------------------------Estratégia03

void estrategia03() {

}


//-----------------------------------------------------------------------Setup
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

  dis1 = sharp1.distance();
  dis2 = sharp2.distance();
  dis3 = sharp3.distance();
  dis4 = sharp4.distance();

  stopp();
  digitalWrite(LED, LOW);
  estrategia = 1;

}

//----------------------------------------------------------------------Loop
void loop() {

  if (digitalRead(botao) == LOW) {
    delay(500);
    start = !start;
    pisca = !pisca;
    time1 = millis();
    recebido = 0;
  }

  if (start == 0) {
    digitalWrite(LED, LOW);
    time3 = millis() - time1;
    time3 = time3 / 1000;
    stopp();
    pisca = 0;
    memoria = 0;
    int est = 0;
*/
    /*
        if (recebido == controle01) {
          estrategia = 1;
          showest = 0;
        }
        else if (recebido == controle02) {
          estrategia = 2;
          showest = 0;
        }
        else if (recebido == controle03) {
          estrategia = 3;
          showest = 0;
        }

        //  Serial.print(recebido);
        //  Serial.println(estrategia);

        recebido = 0;
        indicar(estrategia);
    */
/*
  }

  else if (start == 1) {
    digitalWrite(LED, HIGH);
    time2 = millis() - time1;
    while (time2 < 500 && pisca == 1 ) {
      time2 = millis() - time1;
      stopp();
    }
    pisca = 0;

    if (estrategia == 1) {
      estrategia01();
    }
    if (estrategia == 2) {
      estrategia02();
    }
    if (estrategia == 3) {
      estrategia03();
    }
  }
}

*/
