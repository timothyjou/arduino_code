#include <Servo.h>
Servo servo1;
const int servoPin = 7;
const int buttonPin = 8;
int buttonState =0; 

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servoPin);  
  // start servo @ 0 degree
  servo1.write(0);
  delay(1000);
  //set buttonpin as input
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  Serial.print(servo1.read());
  Serial.print("\n");
  if (buttonState == HIGH) {
    Serial.print("pressed");
    servo1.write(50);
    delay(700);
    servo1.write(0);
  }
  
}
