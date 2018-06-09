#include <SharpIR.h>
#define ir A2
#define model 20150
boolean done=false;

SharpIR sharp(ir, 25, 93, model);

int botao = A5;
unsigned int dis = 0;


const int AIA = 9;              
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
byte speed = 255;

void setup() {

  
  pinMode(botao, INPUT);
  digitalWrite(botao, HIGH);
  pinMode (ir, INPUT);  
  Serial.begin(9600);
 
  
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

}

void loop() {
  
  dis=sharp.distance();
  Serial.println(dis);
     
    if(dis <= 13){
      speed = 50;
      backward();
    }
    else if(dis >13 && dis <= 30){
      speed = 50;
      destroy();
    }
    else if(dis > 30){
      speed = 0;
      stopp();
    }
  }
void destroy()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
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
    speed = 200;
    forward();
}
else if(cmValue > 20){
    speed = 255;
    backward();  
}
else{
  stopp();
}
}
void forward()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

void backward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}

void stopp()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}*/

