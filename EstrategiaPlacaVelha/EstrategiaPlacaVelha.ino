int botaoSelect = 12;
int botaoStart = A5;
int ledSign = 11;
int counter = 0;
int selectState = 0;
int startState = 0;
int currentState = 0;
int previousState = 0;
double teste;
int lastButtonState = 0;  
bool bPress = false;

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
  currentState = selectState;
  startState = digitalRead(botaoStart);
  countButton();
  if( bPress){
    bPress = false;
   }  
   if(startState == LOW){
    
   }
   if(startState == LOW){ //AQUI O ROBÔ DÁ O PLAY
      Serial.print("Contagem: ");
      Serial.println(counter); 
   }
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

