#include <Servo.h>



int servo1Pin = 1;
int servo2Pin = 2;
int servo3Pin = 3;
int servo4Pin = 4;
int servo5Pin = 5;

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;

void setup() {
  Serial.begin(9600);
  
  s1.attach(servo1Pin);
  s2.attach(servo2Pin);
  s3.attach(servo3Pin);
  s4.attach(servo4Pin);
  s5.attach(servo5Pin);
        
}

void writeToServo(int servo, int angle) {
  //first three use different pulse ranges
  if ( servo == 1 ) s1.writeMicroseconds(angle*2000.0/180.0 + 500);
  if ( servo == 2 ) s2.writeMicroseconds(angle*2000.0/180.0 + 500);
  if ( servo == 3 ) s3.writeMicroseconds(angle*2000.0/180.0 + 500);
  //these two are standard
  if ( servo == 4 ) s4.write(angle);
  if ( servo == 5 ) s5.write(angle);
}


void loop() {
  int whichServo = 0;
  int incomingByte = 0;

  if (Serial.available() > 1) {
    whichServo = Serial.read();
    incomingByte = Serial.read();

    Serial.print("Servo ");
    Serial.print(whichServo, DEC);    
    Serial.print(" received: ");
    Serial.print(incomingByte, DEC);
    Serial.print(" (");
    Serial.print((incomingByte*2000.0/180.0 + 500), DEC);
    Serial.println(" microseconds)");

    writeToServo(whichServo, incomingByte);    
  }
}
