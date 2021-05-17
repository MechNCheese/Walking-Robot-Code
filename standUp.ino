#include "Adafruit_Crickit.h"
#include "seesaw_servo.h"
#include "seesaw_motor.h"

Adafruit_Crickit crickit;

//servos
#define NUM_SERVOS 4
seesaw_Servo servo[]={ seesaw_Servo(&crickit),
                       seesaw_Servo(&crickit),
                       seesaw_Servo(&crickit),
                       seesaw_Servo(&crickit)};
int servoPins[]={CRICKIT_SERVO1, CRICKIT_SERVO2, CRICKIT_SERVO3, CRICKIT_SERVO4};
int pos=0, pos0=78, pos1=92, pos2=12, pos3=151;

//DC motors
seesaw_Motor motor_a(&crickit);
seesaw_Motor motor_b(&crickit);

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);

  //checking crickit
  if(!crickit.begin()){
    Serial.println("ERROR");
    while(1);
  }
  else Serial.println("Crickit Started");

  //attach the servos to their pins
  for(int i=0; i<NUM_SERVOS; i++){
    servo[i].attach(servoPins[i], 750, 2250);
  }
  //attach motor a
  motor_a.attach(CRICKIT_MOTOR_A1, CRICKIT_MOTOR_A2);
  //attach motor b
  motor_b.attach(CRICKIT_MOTOR_B1, CRICKIT_MOTOR_B2);

//---------------------------------------------------------------------------------------

  //Initial servo position
  servo[0].write(pos0);
  servo[1].write(pos1);
  servo[2].write(pos2);
  servo[3].write(pos3);
}

void loop() {
  
  //servo[0]=rightUpperThigh - right:0 left:180 center:78
  //servo[1]=leftUpperThigh - right:0 left:180 center:92
  //servo[2]=rightLowerThigh - forward:0 backward:180 angle:12
  //servo[3]=leftLowerThigh - forward:180 backward:0 angle:151

  motor_a.throttle(.5);
  motor_b.throttle(-.5);
  delay(500);

  motor_a.throttle(0);
  motor_b.throttle(0);
  delay(1000);

  motor_a.throttle(-.5);
  motor_b.throttle(.5);
  delay(500);

  motor_a.throttle(0);
  motor_b.throttle(0);
  delay(1000);

//   if (Serial.available()) {  // Returns true if there is serial input.
//    char ch = Serial.read();
//    if (ch == 'e') {
//      if (pos < 180) {
//        pos += 1;
//      }
//    } else {
//      if (pos > 0) {
//        pos -= 1;
//      }
//    }
//    servo[0].write(pos);
//    Serial.println(pos);
//    delay(50);
//  }

  /*servo[0].write(pos0);
  servo[1].write(pos1);
  servo[2].write(pos2);
  servo[3].write(pos3);

  Serial.println(pos0);
  Serial.println(pos1);
  Serial.println(pos2);
  Serial.println(pos3);*/
   

}
