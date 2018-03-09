
#include <SoftwareSerial.h>
#include <Stepper.h> //Biblioteca que controla o Motor de Passos

const int stepsPerRevolution = 65;

SoftwareSerial mySerial(10, 11); // RX, TX
Stepper motor1(stepsPerRevolution, 6,8,7,9); // num_passos, é o numero de passos que seu motor executa em 1 volta, se nao souber pode chutar
Stepper motor2(stepsPerRevolution, 2,4,3,5); // o numero de passos serve para calcular a velocidade
 
void setup(){
//Inicia o Bluetoot
mySerial.begin(9600);
motor1.setSpeed(200); // seta velocidade em rpm
motor2.setSpeed(200);
}

//loop do Bleutooth
void loop(){
  
  char comando = mySerial.read();

  if(comando == 'S'){ //carrinho para tras
     for(int i=0; i<4075; i++){
     motor1.step(10); // passos, é o numero de passos que voce deseja que o motor execute
     motor2.step(-10);
     delay(20);
     }

   }else if(comando == 'D'){ //carrinho para Direita
     for(int i=0; i<4075; i++){
      motor1.step(-10); 
      motor2.step(-10);
      delay(20);
     }

   }else if(comando == 'W'){//carrinho para frente
    for(int i=0; i<205; i++){
      motor1.step(-15);   
      motor2.step(15);
      //delay(5);
    }
   }else if(comando == 'A'){ //carrinho para Esquerda
     for(int i=0; i<205; i++){
      motor1.step(10); 
      motor2.step(10);
      delay(20);
     }
   }
}

