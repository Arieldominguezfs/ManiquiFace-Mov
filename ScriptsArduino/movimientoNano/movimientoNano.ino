#include <Servo.h>
 
int val = 0; //Variable de entrada del Serial
 
Servo servoH; //Creamos un objeto Servo de nombre... servo
Servo servoV;
Servo servoActual;
char eje = "";
void setup()
{
   Serial.begin(9600); //Iniciamos el serial
   servoH.attach(6); //Conectamos el servo al pin digital 3
   servoV.attach(8); //Conectamos el servo al pin digital 3

}
 
void loop()
{
   
   if(Serial.available() > 0) //Detecta si hay alguna entrada por serial
   {
      eje = (char) Serial.read();
      if( eje == 'y'){
        servoActual = servoH;
      }
      else if (eje == 'x'){
        servoActual = servoV;
      }
      
      val = Serial.parseInt();
      if(val != 0)
      {
         servoActual.write(val); //Mueve el servo a la posición entrada (excepto si es 0)
      }
   }
   delay(20);
}
  
