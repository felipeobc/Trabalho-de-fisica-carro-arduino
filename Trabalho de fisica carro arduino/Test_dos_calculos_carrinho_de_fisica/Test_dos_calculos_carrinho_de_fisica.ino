#include <SoftwareSerial.h>
#include <Stepper.h> //Biblioteca que controla o Motor de Passos

void reta();
const int stepsPerRevolution = 360;

SoftwareSerial mySerial(10, 11); // RX, TX
Stepper motor1(stepsPerRevolution, 6,8,7,9); // num_passos, é o numero de passos que seu motor executa em 1 volta, se nao souber pode chutar
Stepper motor2(stepsPerRevolution, 2,4,3,5); // o numero de passos serve para calcular a velocidade
 
void setup(){
//Inicia o Bluetoot
Serial.begin(9600);
mySerial.begin(9600);
motor1.setSpeed(60); // seta velocidade em rpm
motor2.setSpeed(60);

}

//loop do Bleutooth
void loop(){

  
  
  char comando = mySerial.read();
   Serial.println(comando);
   delay(500);
  if(comando == 'S'){ //carrinho para tras
     for(int i=0; i<2000; i++){
     motor1.step(1); // passos, é o numero de passos que voce deseja que o motor execute
     motor2.step(-1);
     //delay(10);
     }

   }else if(comando == 'D'){ //carrinho para Direita
     for(int i=0; i<250; i++){
      motor1.step(-1); 
      motor2.step(-1);
     //\\delay(10);
     }

   }else if(comando == 'W'){//carrinho para frente
    for(int i=0; i<2000; i++){
      motor1.step(-1);   
      motor2.step(1);
      //delay(10);
    }
   }else if(comando == 'A'){ //carrinho para Esquerda
     for(int i=0; i<250; i++){
      motor1.step(1); 
      motor2.step(1);
      //delay(10);
     }
   
   }else if ( comando == 'R'){
    int Voltas = mySerial.read();
   
    for(int i=0; i<Voltas; i++){
      motor1.step(-1);
      motor2.step(1);
      //delay(10);
   }
}
else if ( comando == 'C'){
  circulo();
}
}

void reta (int Voltas){
   
   for(int i=0; i<Voltas; i++){
      motor1.step(-1);
      motor1.step(1);
      //delay(5);
      
    }
  }

  void circulo(){
  int V;
 // V=((10+10)/10 )*60;
  motor1.setSpeed(60); // seta velocidade em rpm
  motor2.setSpeed(60);
  
  for(int i=0; i<32768; i++){
    motor1.step(-1);
    motor2.step(2);
  }
  }

  void eixo(){
    
  }




