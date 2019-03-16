#include <Servo.h>
Servo base;
Servo lArm;
Servo rArm;
Servo claw;

int pp0 = 0;
int pp1 = 1;
int pp2 = 2;
int pp3 = 3;

int p0Val;
int p1Val;
int p2Val;
int p3Val;
void setup() {
  // put your setup code here, to run once:
  base.attach(7);
  lArm.attach(8);
  rArm.attach(9);
  claw.attach(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  p0Val = analogRead(pp0);
  p0Val = map(p0Val,0,1023,0,180);
  base.write(p0Val);

  p1Val = analogRead(pp1);
  p1Val = map(p1Val,0,1023,0,180);
  lArm.write(p1Val);

  p2Val = analogRead(pp2);
  p2Val = map(p2Val,0,1023,0,180);
  rArm.write(p2Val);

  p3Val = analogRead(pp3);
  p3Val = map(p3Val,0,1023,0,180);
  claw.write(p3Val);
  Serial.println(p3Val);
  
  delay(15);
}
