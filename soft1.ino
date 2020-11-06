#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo servoMotorHorizontal;
Servo servoMotorVertical;
Servo servoMotorLateral;


int inicial;
int fin;
int frecuencia;
int intervalo;
int derecha;
int izquierda;
int actualH;
int actualV;
int actualL;


void inicializar(int i, Servo s){
  s.write(i);
}


int mover(int a ,int i, int f, Servo s, int fr){
  int actual = a;
  while(actual < f ){
    s.write(actual);
    delay(fr);
    actual = actual + derecha;
  }
  delay(intervalo);

  while(actual > i){
    s.write(actual);
    delay(fr);
    actual = actual + izquierda;
  }
  delay(intervalo);
  return actual;
}

void moverPares(aH, aV, frec, inter){
  int actualHorizontal = aH;
  int actualVertical = aV;
  frecuencia = frec;
  intervalo = inter;
  
  while(actualHorizontal < 120 ){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia+30);
    actualHorizontal = actualHorizontal + 1;
  }
  delay(intervalo);
  
  while(actualHorizontal > 60 ){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia);
    actualHorizontal = actualHorizontal - 1;
    if(actualHorizontal <=120 and actualHorizontal >= 90){
      servoMotorVertical.write(actualVertical);
      delay(frecuencia);
      actualVertical= actualVertical - 1;
    }
    else if( actualHorizontal <90){
      servoMotorVertical.write(actualVertical);
      delay(frecuencia);
      actualVertical= actualVertical + 1;
    }
  }
  delay(intervalo);
  while(actualHorizontal < 90 ){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia+30);
    actualHorizontal = actualHorizontal + 1;
  }
  delay(intervalo);
}


 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  inicial = 60;
  fin = 120;
  frecuencia = 50;
  intervalo = 1000;
  derecha = +1;
  izquierda = -2;
  actualH = 90;
  actualV = 90;
  actualL = 90;
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotorHorizontal.attach(6);
  servoMotorVertical.attach(8);
  servoMotorLateral.attach(7);

  inicializar(actualH, servoMotorHorizontal);
  delay(500);
  inicializar(actualV, servoMotorVertical);
  delay(500);
  inicializar(actualL, servoMotorLateral);

  }
 
void loop() {
  /*actualH = mover(actualH, 60, 120, servoMotorHorizontal, frecuencia);
  actualV = mover(actualV, 80,90, servoMotorVertical, frecuencia);
  actualL = mover(actualL, 80, 90, servoMotorLateral, frecuencia);
  actualL = mover(actualL, 90, 100, servoMotorLateral, frecuencia);
  */
  //secuencia lado a lado
  moverPares(90,90,20,1000);
}
 




