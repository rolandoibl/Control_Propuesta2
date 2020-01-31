#include <stdio.h>

const int btn_S=53,btn_CS=51,btn_AV=47,btn_CN=43,btn_N=44,btn_NO=35,btn_SI=39;
const int leftLed=50,rightLed=46,btnRetorno=33;

int estadoBoton[8];
String preguntas[5] = {"Cual es tu nombre","Te maltratan en tu trabajo","Te sientes comodo en tu espacio de trabajo","La convivencia es sana","Estas feliz con tu trabajo"};
int numeroPregunta=0;

void setup() {
  Serial.begin(115200);
  pinMode(btn_S,INPUT);
  pinMode(btn_CS,INPUT);
  pinMode(btn_AV,INPUT);
  pinMode(btn_CN,INPUT);
  pinMode(btn_N,INPUT);
  pinMode(btn_SI,INPUT);
  pinMode(btn_NO,INPUT);
  pinMode(leftLed,OUTPUT);
  pinMode(rightLed,OUTPUT);
  pinMode(btnRetorno,INPUT);
}

void loop() {
  estadoBoton[0] = digitalRead(btn_S);
  estadoBoton[1] = digitalRead(btn_CS);
  estadoBoton[2] = digitalRead(btn_AV);
  estadoBoton[3] = digitalRead(btn_CN);
  estadoBoton[4] = digitalRead(btn_N);
  estadoBoton[5] = digitalRead(btn_SI);
  estadoBoton[6] = digitalRead(btn_NO);
  estadoBoton[7] = digitalRead(btnRetorno);
  
  if (estadoBoton[0] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[1] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[2] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[3] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[4] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[5] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[6] == LOW) numeroPregunta = siguientePregunta(numeroPregunta);
  if (estadoBoton[7] == LOW) numeroPregunta = regresarPregunta(numeroPregunta);
  
  preguntar();
  delay(500);
}

int siguientePregunta(int valor){
  int suma = 0;
  suma = valor + 1;
  return suma;
}

int regresarPregunta(int valor){
  int resta = 0;
  resta = valor -1;
  return resta;
}

void preguntar(){
  switch(numeroPregunta){
    case 0: 
      Serial.println(preguntas[0]);
      digitalWrite(leftLed,HIGH);
      digitalWrite(rightLed,LOW);
      break;
    case 1:
      Serial.println(preguntas[1]);
      digitalWrite(leftLed,LOW);
      digitalWrite(rightLed,HIGH);
      break;
    case 2:
      Serial.println(preguntas[2]);
      digitalWrite(leftLed,LOW);
      digitalWrite(rightLed,HIGH);
      break;
    case 3:
      Serial.println(preguntas[3]);
      digitalWrite(leftLed,HIGH);
      digitalWrite(rightLed,LOW);
      break;
    case 4:
      Serial.println(preguntas[4]);
      digitalWrite(leftLed,HIGH);
      digitalWrite(rightLed,LOW);
      break;
    default:
      Serial.println("Terminado");
      break;
  }
  
}




