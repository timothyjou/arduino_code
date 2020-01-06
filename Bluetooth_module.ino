#include <SoftwareSerial.h>
#include <Servo.h>

Servo oFeeder;
int iServoPin = 9;
// Initializing communication ports
SoftwareSerial mySerial(11, 10); // TX/RX pins
 
void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600);
  oFeeder.attach(iServoPin);  //atatch servo to 9
  oFeeder.write(0);          //reset servo
}
 
void loop()
{
    // Check if a message has been received
    String msg = getMessage();
    if(msg!=""){
      Serial.println(msg);
    }
    if (msg == "start"){
        useServo();
    }
    // Send a string when 'm' is sent through the Serial
    if(Serial.available()){
      if(Serial.read()=='m'){
        mySerial.println("HC-06 IS REPLYING :-)");
      }
    }
 
    delay(10);
}

String getMessage(){
  String msg = "";
  char a;
  
  while(mySerial.available()) {
      a = mySerial.read();
      msg+=String(a);
  }
  return msg;
}

void useServo(){
  oFeeder.write(50);
  delay(700);
  oFeeder.write(0);
}
