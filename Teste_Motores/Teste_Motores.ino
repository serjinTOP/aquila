
  
/*int botao = A5;
int LED = 11;*/

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
byte speed = 255;


void setup() {

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
}
int buttonCounter;
void loop() {
    speed = 100;
   // forward();

//digitalRead(13); // Leitura do estado do botão

//if (digitalRead (13) == HIGH) // Condição para iniciar ou não a volta
//{
//bool buttonState = 1;
// buttonCounter = buttonCounter + 1;
//  int countDir = 0;
//}
//switch (buttonCounter){ // Quando o botão for apertado seu valor será 1 e o case abaixo será executado

//case 1:
    
  analogWrite(AIA, 0);
  analogWrite(AIB, 255);
  analogWrite(BIA, 255);
  analogWrite(BIB, 0);

  delay(2000);
  
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  delay(2000);
  
  analogWrite(AIA, 255);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 255);

  delay(2000);
  
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  delay(2000);
  }
