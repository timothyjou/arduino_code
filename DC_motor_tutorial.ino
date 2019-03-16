// DC Motor control
//enA,in1,in2 are the pins that control the DC motor on the L298 Hbridge
#define enA 9
#define in1 6
#define in2 7
#define button 4

boolean buttonState = LOW;
int rotDirection = 0;
int pressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(button, INPUT);
  // set Initial rotation direction
  digitalWrite(in1,LOW);
  digitalWrite(in2, HIGH);
  //use for debugging
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0);
  int pwmOutput = map(potValue, 0, 1023, 0, 255);
  analogWrite(enA, pwmOutput); // send PWM signal to L298N enable pin
  Serial.print(pwmOutput);
  Serial.print("\n");
  // read button
  if (digitalRead(button) == true) {
    Serial.print("button pressed\n");
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);
  // if button is pressed - change rotation direction
  if (pressed == true & rotDirection ==0) {
    Serial.print("change dir\n");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    rotDirection =1;
    delay(20);
  }
  // If button is pressed - chagne rotation direction
  if (pressed == false & rotDirection ==-1) {
    Serial.print("change dir\n");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    rotDirection = 0;
    delay(20); 
  }
}
