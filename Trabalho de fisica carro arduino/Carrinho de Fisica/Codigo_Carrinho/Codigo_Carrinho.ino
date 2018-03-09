#include <SoftwareSerial.h> //Biblioteca que controla o Bluetooth
#include <Stepper.h> //Biblioteca que controla o Motor de Passos

const int stepsPerRevolution = 500;

SoftwareSerial mySerial(10, 11); // RX, TX
String command = "";
Stepper motor1(stepsPerRevolution, 1, 2, 3, 4); // num_passos, é o numero de passos que seu motor executa em 1 volta, se nao souber pode chutar
Stepper motor2(stepsPerRevolution, 5, 6 ,7, 8); // o numero de passos serve para calcular a velocidade
 
void setup(){
//Inicia o Bluetooth
Serial.begin(115200);
Serial.println("Type AT commands!");
mySerial.begin(9600);

//Inicia os motores 
motor1.setSpeed(60); // seta velocidade em rpm
motor2.setSpeed(60);
}

/*void setup(){
//Inicia os motores 
motor1.setSpeed(60); // seta velocidade em rpm
motor2.setSpeed(60);
}*/

//loop do Bleutooth
void loop(){
 
if (mySerial.available()) {
while(mySerial.available()) {
command += (char)mySerial.read();
  }
Serial.println(command);
command = "";
  }
 if (Serial.available()){
delay(10);
mySerial.write(Serial.read());
  }
 
 char comando = mySerial.read();

  if( command == 'W'){ //carrinho para frente
     
     motor1.step(1); // passos, é o numero de passos que voce deseja que o motor execute
     motor2.step(-1);
     delay(500);

   }else if(comando == 'S'){ //carrinho para Tras
      motor1.step(-1); 
      motor2.step(-1);
      delay(500);

   }else if(comando == 'D'){//carrinho para Direita
      motor1.step(-1); 
      motor2.step(1);
      delay(500);
   }else if(comando == 'A'){ //carrinho para Esquerda
      motor1.step(1); 
      motor2.step(1);
      delay(500);
   }
}

/*//loop dos motores (Labirinto)
void loop(){

  char comando = mySerial.read();

  if( command == 'W'){ //carrinho para frente
     
     motor1.step(1); // passos, é o numero de passos que voce deseja que o motor execute
     motor2.step(-1);
     delay(500);

   }else if(comando == 'S'){ //carrinho para Tras
      motor1.step(-1); 
      motor2.step(-1);
      delay(500);

   }else if(comando == 'D'){//carrinho para Direita
      motor1.step(-1); 
      motor2.step(1);
      delay(500);
   }else if(comando == 'A'){ //carrinho para Esquerda
      motor1.step(1); 
      motor2.step(1);
      delay(500);
   }
}*/

