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


const int pulsador = 4; // Entrada digital para el pulsador
const int tiempoAntirrebote = 10; // tiempo en ms para evitar el rebote
  
int cuenta = 1;
int estadoBoton;
int estadoBotonAnterior;

void inicializar(int i, Servo s){
  s.write(i);
}


int mover(int a ,int i, int f, Servo s, int fr){
  int actual = a;
  while(actual < f and cuenta==1){
    s.write(actual);
    delay(fr);
    actual = actual + derecha;
  }
  delay(intervalo);

  while(actual > i and cuenta==1){
    s.write(actual);
    delay(fr);
    actual = actual + izquierda;
  }
  delay(intervalo);
  return actual;
}

void moverPares(int ah,int av,int frec, int inter){
  
  int actualHorizontal = ah;
  int actualVertical = av;
  frecuencia = frec;
  intervalo = inter;
  
  while(actualHorizontal < 120 and cuenta==2){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia);
    actualHorizontal = actualHorizontal + 1;
  }
  delay(intervalo);
  
  while(actualHorizontal > 60 and cuenta==2){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia);
    actualHorizontal = actualHorizontal - 1;
    if(actualHorizontal <=120 and actualHorizontal >= 90){
      servoMotorVertical.write(actualVertical);
      delay(frecuencia);
      actualVertical= actualVertical - 1;
    }
    else if( actualHorizontal <90 and cuenta==2){
      servoMotorVertical.write(actualVertical);
      delay(frecuencia);
      actualVertical= actualVertical + 1;
    }
  }
  delay(intervalo);
  while(actualHorizontal < 90 ){
    servoMotorHorizontal.write(actualHorizontal);
    delay(frecuencia);
    actualHorizontal = actualHorizontal + 1;
  }
  delay(intervalo);
}

boolean antirrebote(int pin)
  {
    int contador = 0;
    boolean estado;
    boolean estadoAnterior;
    
    do
    {
      estado = digitalRead(pin);
      if(estado != estadoAnterior)
      {
        contador = 0;
        estadoAnterior = estado;
      }
      else
      {
        contador = contador+ 1;
      }
      delay(1);
    } while(contador < tiempoAntirrebote);
    
    return estado;
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
  pinMode(pulsador, INPUT); // PIN digital del pulsador como entrada
 
  inicializar(actualH, servoMotorHorizontal);
  delay(500);
  inicializar(actualV, servoMotorVertical);
  delay(500);
  inicializar(actualL, servoMotorLateral);

  }
 
void loop() {
  
  estadoBoton = digitalRead(pulsador);
    
    if(estadoBoton != estadoBotonAnterior)
    {
      if(antirrebote(pulsador))
      {
        if(cuenta == 3){
          cuenta = 1;
        }
        else{
          cuenta++;
        }
      }
    }  
    
     if(cuenta == 1){
           actualH = mover(actualH, 60, 120, servoMotorHorizontal, frecuencia);
           actualV = mover(actualV, 80,90, servoMotorVertical, frecuencia);
           actualL = mover(actualL, 80, 90, servoMotorLateral, frecuencia);
           actualL = mover(actualL, 90, 100, servoMotorLateral, frecuencia);
          Serial.print("secuencia 1");
        }
    if(cuenta == 2){
           Serial.print("secuencia 2"); 
          moverPares(90,90,20,200);
        } 

    
    delay(10);
    estadoBotonAnterior = estadoBoton;
  
}
 




