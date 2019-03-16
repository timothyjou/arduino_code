// scheduler for auto feeding with button over ride
// Instruction to setup:
// for RTC moduel: VCC -> 5V  GND -> ground, CLK -> 6, DAT ->7,  RST ->8
// for Servo plug control pin --> 9
// for button input pin,     --> 10
#include <virtuabotixRTC.h>
#include <Servo.h>

Servo feeder;
// SCLK -> 6, DAT ->7,  RST ->8-
virtuabotixRTC myRTC(6,7,8);
int iButtonPin = 10;
int iServoPin = 9;

int iLastFedHour = 0;
int iButtonState = 0;

void setup() {
  feeder.attach(iServoPin);  //atatch servo to 9
  feeder.write(0);          //reset servo
  pinMode(iButtonPin, INPUT);  // attach button to 10 as input
  Serial.begin(9600);
  // set the time once and ONCE ONLY
  // format : (seconds, minuutes, hours, day of week, day of month, month, year
  //myRTC.setDS1302Time(0,35,14,6,29,12,2018);
}

void loop() {
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  writeTimeToSerial();
  iButtonState = digitalRead(iButtonPin);
  if ((myRTC.hours == 9 || myRTC.hours == 17 || myRTC.hours == 20) && myRTC.hours != iLastFedHour) {
    Serial.print("FEEDING");
    useServo(); 
    iLastFedHour = myRTC.hours;
  } else if (iButtonState == HIGH) {
    useServo();
  }
}

// Helper Functions
void useServo(){
  feeder.write(50);
  delay(700);
  feeder.write(0);
}
// print time every 1 second
void writeTimeToSerial() {
  delay(1000);
  Serial.print("Current Date :");
  Serial.print(myRTC.month);
  Serial.print(" / ");
  Serial.print(myRTC.dayofmonth);
  Serial.print(" / ");
  Serial.print(myRTC.year);
  Serial.print(" Time: ");
  Serial.print(myRTC.hours);
  Serial.print(" : ");
  Serial.print(myRTC.minutes);
  Serial.print(" : ");
  Serial.print(myRTC.seconds);
  Serial.print("\n");
}

