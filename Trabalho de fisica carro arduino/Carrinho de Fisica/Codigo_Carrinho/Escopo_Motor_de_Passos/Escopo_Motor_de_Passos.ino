
include <Stepper.h>

Stepper motor1(num_passos, pino1, pino2, pino3,pino4); // num_passos, é o numero de passos que seu motor executa em 1 volta, se nao souber pode chutar
Stepper motor2(num_passos, pino1, pino2, pino3,pino4); // o numero de passos serve para calcular a velocidade


void setup()
{
   motor1.setSpeed(veloc); // seta velocidade em rpm
   motor2.setSpeed(veloc);
}

void loop()
{
     motor1.step(passos); // passos, é o numero de passos que voce deseja que o motor execute
     motor2.step(passos);
     
     delay(1000);
}
