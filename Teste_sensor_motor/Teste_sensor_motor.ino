#include <SharpIR.h>
#define ir A2
#define model 20150
boolean done = false;

SharpIR sharp(ir, 25, 93, model);

int botao = A5;
int botao2 = 12;
unsigned int dis = 0;


const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
byte velocid = 255;

void setup() {
  pinMode(botao, INPUT);
    pinMode(botao2, INPUT);
  digitalWrite(botao, HIGH);
   digitalWrite(botao2, HIGH);
  pinMode (ir, INPUT);
  Serial.begin(9600);


  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

}

void loop() {
  //stopp();
  dis = sharp.distance();
  Serial.println(dis);
if (dis > 13 && dis <= 30) {
      velocid = 255;
      destroy();
    }
    else   {
      velocid = 0;
      rotate();
    }
}
void destroy()
{
  analogWrite(AIA, velocid);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocid);
  analogWrite(BIB, 0);
}

void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocid);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocid);
}
void rotate()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocid);
  analogWrite(BIA, velocid);
  analogWrite(BIB, 0);
}
void stopp()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}
/*sensorValue = analogRead(sensorPin);
  cmValue = 10650.08 * pow(sensorValue,-0.935) - 10;
  Serial.print("Valor lido = ");
  Serial.print(cmValue);
  Serial.println(" cm");
  delay(250);

  if(cmValue <= 10) {
    velocid = 200;
    forward();
  }
  else if(cmValue > 20){
    velocid = 255;
    backward();
  }
  else{
  stopp();
  }
  }
  void forward()
  {
  analogWrite(AIA, velocid);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocid);
  analogWrite(BIB, 0);
  }

  void backward()
  {
  analogWrite(AIA, 0);
  analogWrite(AIB, velocid);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocid);
  }

  void stopp()
  {
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
  }*/

