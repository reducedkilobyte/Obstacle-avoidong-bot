const int trigPIN=3;
const int echoPIN=4;
long duration;
int distance;

void setup() {
  pinMode(trigPIN,OUTPUT);
  pinMode(echoPIN,INPUT);
}

void loop() {
  digitalWrite(trigPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echoPIN,HIGH);
  distance=(duration*0.034)/2;
}
