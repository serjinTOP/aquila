
int botao = A5;
int botao2 = 12;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
byte speed = 255;


void setup() {
  pinMode(botao, INPUT);
  pinMode(botao2, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(botao, HIGH);
  digitalWrite(botao2, HIGH);
  digitalWrite(LED, LOW); 
  Serial.begin(9600);

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW) {
    Serial.println("apertou");
    digitalWrite(LED, HIGH);
    speed = 255;
    destroy();
  }
  else if (digitalRead(botao) == HIGH) {
    Serial.println("soltou");
    digitalWrite(LED, LOW);
    speed = 0;
    stopp();
  }
  if(digitalRead(botao2) == LOW){
    Serial.println("botao 2");
    digitalWrite(LED,HIGH);
    speed = 255;
    backward();
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
