#include <Servo.h>
#include <SoftwareSerial.h>

Servo base;
Servo lArm;
Servo rArm;
Servo claw;
SoftwareSerial mySerial(11, 10); // TX = 11 RX = 10 pins

int iBaseDegree = 90;   // max = 180  min = 0;     90 = middle
int iLArmDegree = 100;  // max = 150  min = 55;
int iRArmDegree = 70;   // max = 90  min = 50;
int iClawDegree = 160;  // max = 180  min = 135;   180 = open
void setup() {
  // put your setup code here, to run once:
  base.attach(6);
  lArm.attach(7);
  rArm.attach(8);
  claw.attach(9);
  // initial value
  base.write(iBaseDegree);
  lArm.write(iLArmDegree);
  rArm.write(iRArmDegree);
  claw.write(iClawDegree);
  
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  String msg = getMessage();
  if (msg!="") {
    Serial.println(msg);
  }
  if (msg == "left") {
    turnLeft();  
  }
  if (msg == "right") {
    turnRight();  
  }
  if (msg == "up") {
    moveLArmForward();
  }
  if (msg == "down") {
    moveLArmBackward();
  }
  if (msg == "square") {
    moveRArmForward();
  }
  if (msg == "triangle") {
    moveRArmBackward();
  }
  delay(10);
}

// helper 
String getMessage() {
  String msg = "";
  char a;
  
  while(mySerial.available()) {
      a = mySerial.read();
      msg+=String(a);
  }
  return msg;
}

void turnRight() {
  if (iBaseDegree - 5 > 0) {
    iBaseDegree = iBaseDegree - 5;
  }
  base.write(iBaseDegree);
}
void turnLeft() {
  if (iBaseDegree + 5 < 180) {
    iBaseDegree = iBaseDegree + 5;
  }
  base.write(iBaseDegree);
}
void moveLArmForward() {
  if (iLArmDegree + 5 < 150) {
    iLArmDegree = iLArmDegree + 5;
  }
  lArm.write(iLArmDegree);
}
void moveLArmBackward() {
  if (iLArmDegree - 5 > 55) {
    iLArmDegree = iLArmDegree - 5;
  }
  lArm.write(iLArmDegree);
}

void moveRArmForward() {
  if (iRArmDegree + 5 < 90) {
    iRArmDegree = iRArmDegree + 5;
  }
  rArm.write(iRArmDegree);
}
void moveRArmBackward() {
  if (iRArmDegree - 5 > 50) {
    iRArmDegree = iRArmDegree - 5;
  }
  rArm.write(iRArmDegree);
}

void printAllVal() {
  Serial.println("BASE degree:");
  Serial.println(iBaseDegree);
  Serial.println("L Arm degree:");
  Serial.println(iLArmDegree);
  Serial.println("R Arm degree:");
  Serial.println(iRArmDegree);
  Serial.println("CLAW degree:");
  Serial.println(iClawDegree);
}
