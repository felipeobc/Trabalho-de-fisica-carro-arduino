#include <Stepper.h> 
 
const int stepsPerRevolution = 500; 
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper myStepper1(stepsPerRevolution, 8,10,9,11);
Stepper myStepper2(stepsPerRevolution, 2,4,3,5); 
  
void setup() 
{ 
 //Determina a velocidade inicial do motor 
 myStepper1.setSpeed(60);
 myStepper2.setSpeed(60);
} 
  
void loop(){
 myStepper1.step(-512);
 myStepper2.step(512);
 delay(1000);
  
  }

  

