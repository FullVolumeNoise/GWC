//Arduino
#include <Servo.h>                           // Include servo library
#include <ArduinoRobot.h> 

Servo servoRight;
Servo servoLeft;

void moveKitty() {
  // Your Code Here
}

void stopKitty() {
  // Your Code Here
}

void setup() {
  // put your setup code here, to run once:
  Robot.begin();
  Serial.print("we are");
  Serial.println("We are");
}

void loop() {
  // put your main code here, to run repeatedly:
   // If the robot is blocked, turn until free
  while (getDistance() < 40) { // If an obstacle is less than 20cm away
    setFace(false); //shows an unhappy face
    Robot.motorsStop(); // stop the motors
    delay(1000); // wait for a moment
    Robot.turn(90); // turn to the right and try again
    setFace(true); // happy face
  }
  // if there are no objects in the way, keep moving
  Robot.motorsWrite(255, 255);
  delay(100);
}
