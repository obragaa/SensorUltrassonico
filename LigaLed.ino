//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino Uno
 
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  // amarelo
  pinMode(12, OUTPUT);

  // verde
  pinMode(7, OUTPUT);

  //vermelho
  pinMode(8, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(400);

  if(cmMsec <= 30){
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
  }
   else if(cmMsec >= 31 && cmMsec <= 100){
      digitalWrite(12, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
  }
   else if(cmMsec >= 101 && cmMsec <= 150){
      digitalWrite(12, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
  }
  else{
      digitalWrite(12, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
  }

}