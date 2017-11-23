#include <Servo.h>



int servo1Pin = 2;
int servo2Pin = 3;
int servo3Pin = 4;
int servo4Pin = 5;
int servo5Pin = 6;

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;

void setup() {
  Serial.begin(9600);
  
  s1.attach(servo1Pin);
  s2.attach(servo2Pin);
  s2.write(128); //turn off the continuous one.
  s3.attach(servo3Pin);
  s4.attach(servo4Pin);
  s5.attach(servo5Pin);
        
}

void writeToServo(int servo, int angle) {
  if ( servo == 1 ) s1.write(angle);
  if ( servo == 2 ) s2.write(angle);
  if ( servo == 3 ) s3.writeMicroseconds(angle*2000.0/180.0 + 500);
  if ( servo == 4 ) s4.write(angle);
  if ( servo == 5 ) s5.writeMicroseconds(angle*2000.0/180.0 + 500);
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
