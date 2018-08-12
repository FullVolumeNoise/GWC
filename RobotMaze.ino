int whisker1 = 7;
int whisker2 = 5;
int piezo = 13;
int turns = 0;
#include <Servo.h>
#include <ArduinoRobot.h>
Servo servoLeft;
Servo servoRight;

void setup() {
  // put your setup code here, to run once:
  pinMode(piezo, OUTPUT);
  pinMode(whisker1, INPUT);
  pinMode(whisker2, INPUT);
  Serial.begin(9600);
  servoLeft.attach(13);
  servoRight.attach(12);
  tone(piezo,600,500);
  Robot.begin();
  Robot.beginSpeaker();//Initialize the sound module
  char aTinyMelody[] = "8eF-FFga4b.a.g.F.8beee-d2e.1-";// This is what we will play
  Robot.playMelody(aTinyMelody);// Play the melody 
}
void loop() {
  // put your main code here, to run repeatedly:
  //tone(piezo, 600, 500);
  noTone(piezo);
  if(digitalRead(whisker1)==0 || digitalRead(whisker2)==0){
    Serial.println("whisker pressed");
    servoLeft.writeMicroseconds(1700);
    servoRight.writeMicroseconds(1300);
    delay (800);
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1300);
    delay (650);
    turns ++; 1;
  }else{
    Serial.println("whisker not pressed");
    servoLeft.writeMicroseconds(1300);
    servoRight.writeMicroseconds(1700);
  }
  if(digitalRead(whisker1)==0 || digitalRead(whisker2)==0) {
    tone(piezo,600,500);
  }
}


