#include <Stepper.h>

const int step_360 = 200;// 360 number of steps per/rev                               
// initialize the stepper library on pins 2-5 n 8-11 
Stepper myStepper1(step_360,2,3,4,5);
Stepper myStepper2(step_360,8,9,10,11);       

void setup() 
{
 // set the speed at 60 rpm:
 myStepper1.setSpeed(60);//left
 myStepper2.setSpeed(60);//right
 // initialize the serial port:
 Serial.begin(9600);
}
void loop() 
{
 // step one revolution  in one direction:
 Serial.println("clockwise");
 for (int i = 0; i < step_360; i++)
 {
  myStepper1.step(1);
  myStepper2.step((-1));
 }
 delay(500);    
}


