#include <QTRSensors.h>


#define rightMaxSpeed  100                   // Máxima velocidade do motor direito
#define leftMaxSpeed   100  // Máxima velocidade do motor esquerdo
#define rightBaseSpeed  30                  // Velocidade Base do motor direito; Velocidade quando o robô está na linha
#define leftBaseSpeed   30                  // Velocidade Base do motor esquerdo; Velocidade quando o robô está na linha
#define NUM_SENSORS    6                     // Número de sensores usados
#define NUM_SAMPLES_PER_SENSOR  4            // O valor retornado é uma média de 4 leituras
#define EMITTER_PIN    QTR_EMITTERS_ON       // Controle dos emissores dos sensores
    
// Motor da esquerda
#define leftMotorPWM 9
#define leftMotor 6

// Motor da direita
#define rightMotorPWM 5
#define rightMotor 3


// Botão
#define ButtonPin 13


QTRSensorsAnalog qtra((unsigned char []) {1, 2, 3, 4, 5, 6} ,NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN); // Inicialização dos sensores
 
unsigned int sensorValues[NUM_SENSORS];

// Declaração de variáveis gerais utilizadas no código

int ldrPin1 = 0;
int ldrval1 = 0;
int boolval1= 0;

int ldrPin2 = 7;
int ldrval2 = 0;
int boolval2= 0;

int currentState = 0;
int previousState = 0;



float Kp = 0.0;
float Ki = 0.0;        
float Kd = 0.0;

float P = 0.0;
float I = 0.0;
float D = 0.0;

int position;
char readMode;
char whiteLine;



int buttonCounter;

int countDir;

bool buttonState = 0;


double lastError = 0;
long lastProcess = 0;


void setup()
{

  pinMode(rightMotor, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  
  int i;
  
for (i = 0; i < 250; i++) // Calibragem dos sensores
{
   qtra.calibrate();
}

  Serial.begin (9600);
  
  delay (10);

}

void loop()
{
      unsigned long currentMillis = millis(); // Contagem de tempo desde o início do programa


buttonCounter = 0;

digitalRead(ButtonPin); // Leitura do estado do botão

if (digitalRead (ButtonPin) == HIGH) // Condição para iniciar ou não a volta
{
  buttonState = 1;
  buttonCounter = buttonCounter + 1;
  int countDir = 0;
}
else {
  buttonState = 0;
}


switch (buttonCounter){ // Quando o botão for apertado seu valor será 1 e o case abaixo será executado

case 1:
  while (countDir < 5){ // Quantidade de vezes que o sensor direito passa por uma linha branca
    

// Regulagem das constantes do PID
  Kp = 5.0   ;  //0.05 fm 
  Ki = 0.1;  //0.0007 fm
  Kd = 20.0   ;  // 0.03 fm
 

position = qtra.readLine(sensorValues, readMode = QTR_EMITTERS_ON, whiteLine = 1); //  Leitura da posição do robô na pista; Biblioteca QTR

 float error =  2500.0 - position;
 float deltaTime = (millis() - lastProcess)/100.0;
 lastProcess = millis();
Serial.print("error= "); 
Serial.print(error );
Serial.print ('\t');
Serial.print("deltaTime= ");
Serial.print( deltaTime );
 //P
 P = error * Kp;
 
 //I
 I = ((error + lastError) * Ki)/deltaTime;
 //D
 D = ((error - lastError) * Kd)/deltaTime;

  lastError = error ;
  double motorSpeed = P + I + D ;
  /*
  Serial.print ('\t');
 Serial.print("P ");
Serial.print( P );
Serial.print ('\t');
Serial.print("I ");
Serial.print(I );
Serial.print ('\t');
Serial.print("D");
Serial.print(D);
Serial.print ('\t');
*/
Serial.print("motorSpeed ");
Serial.print( motorSpeed );

  double rightMotorSpeed = rightBaseSpeed + motorSpeed;
  double leftMotorSpeed = leftBaseSpeed - motorSpeed;
  
 Serial.print('\t');
 Serial.print("ESQM");
  Serial.print(leftMotorSpeed);
  Serial.print('\t');
  Serial.print("DIRM");
  Serial.print(rightMotorSpeed);
  
 analogWrite(rightMotor, 0);
 analogWrite(leftMotor, 0);


  
  if (rightMotorSpeed > rightMaxSpeed ) rightMotorSpeed = rightMaxSpeed; // Evita que o motor ultrapasse a velocidade máxima
  if (leftMotorSpeed > leftMaxSpeed ) leftMotorSpeed = leftMaxSpeed;     // Evita que o motor ultrapasse a velocidade máxima
  
  

  if (rightMotorSpeed < 0) 
  {
    analogWrite(rightMotorPWM, 0);
    rightMotorSpeed = - rightMotorSpeed;
      if (rightMotorSpeed > 10) 
       {
        rightMotorSpeed = 10;
        analogWrite(rightMotor, rightMotorSpeed);
       }  
  }
  
  if (leftMotorSpeed < 0) 
  {
    analogWrite(leftMotorPWM, 0);
    leftMotorSpeed = - leftMotorSpeed;
      if (leftMotorSpeed > 10) 
       {
        leftMotorSpeed = 10;
        analogWrite(leftMotor, leftMotorSpeed);
       }
  }
  
  analogWrite(rightMotorPWM, rightMotorSpeed);
  analogWrite(leftMotorPWM, leftMotorSpeed);
  
Serial.print('\t');
Serial.print("ESQ");
Serial.print(leftMotorSpeed);
Serial.print('\t');
Serial.print("DIR");
Serial.println (rightMotorSpeed);

  ldrval1 = analogRead(ldrPin1);
    if (ldrval1 >= 400 ) //QUANTO MAIS BRANCO, MENOR O VALOR (200 MIN)
      {   
       boolval1 = HIGH;
      }
    else 
      {
        if (ldrval1 <= 300)
          {
           boolval1 = LOW; 
          }
      }
    if (boolval1 == LOW) 
      {
       currentState = 0;
      }
    else 
    {
     currentState = 1;
    }
    if(currentState != previousState)
    {
      if(currentState == 0) //  && boolval2 == LOW condicional para ignorar cruzamentos
        { 
         countDir = countDir + 1;
        }
    } 
  
  }

  previousState = currentState;
  
  if (countDir >= 5) // Após o robô terminar a volta, diminui a sua velocidade e o faz parar na Área de partida e chegada
  {

    digitalWrite(leftMotor,  LOW);
    digitalWrite(rightMotor, LOW) ;  
    analogWrite(rightMotorPWM, 100);
    analogWrite(leftMotorPWM, 105);     

    delay(200);
    
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);   
    analogWrite(rightMotorPWM, 100);
    analogWrite(leftMotorPWM, 105);

    delay(100);

    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    analogWrite(rightMotorPWM, 0);
    analogWrite(leftMotorPWM, 0);
  
  }

buttonCounter = buttonCounter++;
  break; // Encerra o código
}

  }

