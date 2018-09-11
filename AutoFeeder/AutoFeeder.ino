#include <virtuabotixRTC.h>
#include <Servo.h>

Servo feeder;
// SCLK -> 6, IO ->7,  CE ->8
virtuabotixRTC myRTC(6,7,8);
int currMin;

void setup() {
  feeder.attach(9);  //atatch servo to 9
  Serial.begin(9600);
  // set the time once and ONCE ONLY
  // format : (seconds, minuutes, hours, day of week, day of month, month, year
  // myRTC.setDS1302Time(0,15,21,6,24,3,2018);
  myRTC.updateTime();
  currMin = myRTC.minutes;
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  //writeTimeToSerial();
  Serial.print(currMin);
  Serial.print("\n");
  if (myRTC.minutes > currMin){
    int diff = myRTC.minutes - currMin;
    Serial.print(diff);
    Serial.print("\n");
    if (diff == 5) {
      useServo();
      
    }
  } else if (myRTC.minutes < currMin){
    // deal wiht case when 0 - 55 or 1 - 56, 2-57, 3-58 4-59
  }
  
}

// Helper Functions
void useServo(){
  feeder.write(0);
  delay(1000);
  feeder.write(180);
  delay(3000);
  feeder.write(0);
}
void writeTimeToSerial(){
  Serial.print("Current Date :");
  Serial.print(myRTC.month);
  Serial.print(" / ");
  Serial.print(myRTC.dayofmonth);
  Serial.print(" / ");
  Serial.print(myRTC.year);
  Serial.print("Time: ");
  Serial.print(myRTC.hours);
  Serial.print(" : ");
  Serial.print(myRTC.minutes);
  Serial.print(" : ");
  Serial.print(myRTC.seconds);
  Serial.print("\n");
}

