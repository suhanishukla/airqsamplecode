#include <ESP32Servo.h>

Servo myServo; 
#define servopin A0

//stroke percentage 0 is fully retracted, 100 fully extended
int findStrokePercent(int strokePercent) {
  return map(strokePercent,0,100,0,180);
}

void setup() {
  myServo.attach(servopin, 1000, 2000);
}

void loop() { 
  //keeps moving servo from 1 to 100 percent and back 
  for (int i=0; i<=65; i+=5) {
    myServo.write(findStrokePercent(i));
    delay(750); 
  }
  for (int i=65; i>=0; i-=5) {
    myServo.write(findStrokePercent(i));
    delay(750); 
  }
  //myServo.write(findStrokePercent(60)  ); 
}