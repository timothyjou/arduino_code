const int A1A = 7;
const int A1B = 8;
const int B1A = 9;
const int B1B = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  pinMode(B1A, OUTPUT);
  pinMode(B1B, OUTPUT);
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, HIGH);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, HIGH);
  delay(5000);
  
  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
  digitalWrite(B1A, HIGH);
  digitalWrite(B1B, LOW);
  delay(5000);
}

