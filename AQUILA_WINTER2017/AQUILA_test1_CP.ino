
/* Código para teste dos motores do robô ÁQUILA.
   ROTINA: Frente, Trás, giro Esquerda, giro Direita.
   Cada ação com duração de 1s com intervalos parado de 1s entre ações.
*/
/*


int botao = 12;
int LED = 11;

const int AIA = 9;
const int AIB = 10;
const int BIA = 5;
const int BIB = 3;
int velocidade = 0;

void backward()
{
  analogWrite(AIA, velocidade);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocidade);
  analogWrite(BIB, 0);
}

void forward()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidade);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidade);
}
void left()
{
  analogWrite(AIA, velocidade);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidade);
}
void right()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidade);
  analogWrite(BIA, velocidade);
  analogWrite(BIB, 0);
}

void setup() {
  pinMode(botao, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(botao, HIGH);
  digitalWrite(LED, LOW);

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  delay(4000);
}

void loop() {

  digitalWrite(LED, HIGH);
  velocidade = 255;
  forward();
  delay(1000);

  digitalWrite(LED, LOW);
  velocidade = 0;
  forward();
  delay(1000);
  

  digitalWrite(LED, HIGH);
  velocidade = 50;
  backward();
  delay(1000);

  digitalWrite(LED, LOW);

  
  velocidade = 0;
  backward();
  delay(1000);

  digitalWrite(LED, HIGH);
  velocidade = 100;
  left();
  delay(1000);

  digitalWrite(LED, LOW);
  velocidade = 0;
  left();
  delay(1000);

  digitalWrite(LED, HIGH);
  velocidade = 100;
  right();
  delay(1000);

  digitalWrite(LED, LOW);
  velocidade = 0;
  right();
  delay(1000);
  
}

*/

