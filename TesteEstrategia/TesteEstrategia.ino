int botaoSelect = 2;
int botaoStart = 4;
int ledSign = 13;
int counter = 0;
int selectState = 0;
int startState = 0;
double teste;

void setup() {
  Serial.begin(9600);
  pinMode(botaoSelect, INPUT);
  pinMode(botaoStart, INPUT);
  pinMode(ledSign, OUTPUT);
  digitalWrite(botaoSelect, HIGH);
  digitalWrite(botaoStart, HIGH);
  digitalWrite(ledSign, LOW);
}
  
void loop() {
  selectState = digitalRead(botaoSelect);
  startState = digitalRead(botaoStart);
  if(selectState == LOW){
    counter = counter + 1;
    Serial.println(counter);
  }
  if(startState == LOW){
    Serial.print("Contagem: ");
    Serial.println(counter/50);
 //   while(counter != 0){
      
  //  }
  }
}
