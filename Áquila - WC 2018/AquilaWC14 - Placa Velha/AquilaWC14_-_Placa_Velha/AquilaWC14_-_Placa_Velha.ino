#include <SharpIR.h>

#define ir1 A4
#define ir2 A7
#define ir3 A5
#define ir4 A6

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

int botao = A5;
int botaoSelect = 12;
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
int counter = 0;
int selectState = 0;
int startState = 0;
int currentState = 0;
int previousState = 0;
double teste;
int lastButtonState = 0;  
bool bPress = false;

//----------------------------------------------------------Rotinas

void seek() {
  dis1 = sharp1.distance();
  dis2 = sharp2.distance();
  dis3 = sharp3.distance();
  dis4 = sharp4.distance();
}

//AND

void mainCode(int counter){
  Serial.print("Chamou mainCode");
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
    digitalWrite(LED, LOW);
  }
  else if (start == 1) {
    digitalWrite(LED, HIGH);
    time2 = millis() - time1;
    while (time2 < 4800 && pisca == 1 ) {
      time2 = millis() - time1;
      stopp();
    }

    if (time2 < 100) {
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

    if (dis3 <= range3 && dis4 <= range4 && dis3 > 0 && dis4 > 0) {
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
    else if (dis3 <= range3 && dis4 >= range4 && dis3 > 0) {
      speedleft = 100;
      speedright = 20;
      destroy();
      memoria = 1;
    }
    else if (dis3 >= range3 && dis4 <= range4 && dis4 > 0) {
      speedleft = 20;
      speedright = 100;
      destroy();
      memoria = -1;
    }
    else if (dis1 <= range1 && dis1 > 0) {
      while (dis3 > range3 && dis4 > range4) {
        seek();
        speedleft = 0;
        speedright = 160;
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
    else if (dis2 <= range2 && dis2 > 0) {
      while (dis3 > range3 && dis4 > range4) {
        seek();
        speedleft = 160;
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
    else if(dis1 >= range1 && dis2 >= range2 && dis3 >= range3 && dis4 >= range4){
      speedleft = 120;
      speedright = 120;
      if(counter == 1){
        findIt();
        Serial.println("caiu no findIt - counter 1");
      }
      else if(counter == 2){
        findItTheOtherWay();
        Serial.println("caiu no other way - counter 2");
      }
    }
    else if (dis3 >= range3 || dis3 < 0) {
        if (dis4 >= range4 || dis4 < 0) {
          if (dis1 >= range1 || dis1 < 0) {
            if (dis2 >= range2 || dis2 < 0) {

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
      }
    }
}

void destroy() {
  analogWrite(AIA, speedleft);
  analogWrite(AIB, 0);
  analogWrite(BIA, speedright);
  analogWrite(BIB, 0);
}

void backward() {
  analogWrite(AIA, 0);
  analogWrite(AIB, speedleft);
  analogWrite(BIA, 0);
  analogWrite(BIB, speedright);
}

void findIt() {
  analogWrite(AIA, 0);
  analogWrite(AIB, speedleft);
  analogWrite(BIA, speedright);
  analogWrite(BIB, 0);
}

void findItTheOtherWay() {
  analogWrite(AIA, speedleft);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, speedright);
}

void stopp() {
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}
void countButton(){
  selectState = digitalRead(botaoSelect);
  if (selectState != lastButtonState) {    
    if (selectState == LOW) {
      bPress = true;
      counter++;   
    }
    delay(50);
 }
  lastButtonState = selectState;
}

//-----------------------------------------------------------Setup
void setup() {
  
  Serial.begin(9600);
  pinMode(botaoSelect, INPUT);
  pinMode(botao, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(botaoSelect, HIGH);
  digitalWrite(botao, HIGH);
  digitalWrite(LED, LOW);

  
  pinMode (ir1, INPUT);
  pinMode (ir2, INPUT);
  pinMode (ir3, INPUT);
  pinMode (ir4, INPUT);

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

//-----------------------------------------------------------Loop
void loop() {
  selectState = digitalRead(botaoSelect);
  currentState = selectState;
  startState = digitalRead(botao);
  countButton();
  if( bPress){
    bPress = false;
   }  
   if(startState == LOW){
    
   }
   if(startState == LOW){ //AQUI O ROBÔ DÁ O PLAY
    if(counter == 1){ //DONE
      Serial.print("Estratégia: ");
      Serial.println(counter); 
      //GIRA EM SEU PRÓPRIO EIXO PARA UM LADO
      mainCode(counter);
    }
    if(counter == 2){ //DONE
      Serial.print("Estratégia: ");
      Serial.println(counter); 
      //GIRA EM SEU PRÓPRIO EIXO PARA OUTRO LADO 
      mainCode(counter);
    }
    if(counter == 3){ 
      //Primeira tentativa: Executar a estratégia até enxergar algo com qualquer um dos sensores
      //Assim que notar algo, chamará o código padrão e executará sua função corretamente. (Será???)
      Serial.print("Estratégia: ");
      Serial.println(counter); 
      //ANDA PARA TRÁS E VIRA PARA A DIREITA
      mainCode(counter);
    }
    if(counter == 4){
      //Primeira tentativa: Executar a estratégia até enxergar algo com qualquer um dos sensores (Pro outro lado)
      //Assim que notar algo, chamará o código padrão e executará sua função corretamente. (Será???)
      Serial.print("Estratégia: ");
      Serial.println(counter); 
      //ANDA PARA TRÁS E VIRA PARA A ESQUERDA
      mainCode(counter);
    }
    if(counter == 5){ //THE HARDEST ONE. STILL DON'T KNOW HOW TO DO IT xD
      Serial.print("Estratégia: ");
      Serial.println(counter); 
      //ESPERA A UMA DISTÂNCIA MAIOR E SÓ MONITORA O OPONENTE. QUANDO ESTIVER MAIS PERTO, ATACA - Ver como será feito
      mainCode(counter);
    }
   }
}

