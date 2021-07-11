#include<Servo.h>
Servo SM;
int mtrr1=9;
int mtrr2=10;
int mtrl1=5;
int mtrl2=6;

int trigpin=3;
int echo=4;

void setup() {
pinMode(mtrr1, OUTPUT);
pinMode(mtrr2,OUTPUT);
pinMode(mtrl1, OUTPUT);
pinMode(mtrl2,OUTPUT);
pinMode(trigpin, OUTPUT);
pinMode(echo, INPUT);
  SM.attach(11);
  SM.write(90);
  delay(3000);


}
int distance;
void loop() {
  findDistance() ;

  if (distance > 20) 
  {
    forward();
  } 
  else 
  {
    delay(60);
    findDistance();
    if (distance > 20)
    {
      forward();
    } 
    else 
    {
      Stop();
      delay(500);
      backward();
      delay(1500);
      Stop();
      SM.write(40);
      delay(500);
      findDistance();
      if (distance>20)
      {
        SM.write(90);
        delay(1000);
        rightward();
        delay(1000);
        Stop();
      }
      else
      {
        SM.write(130);
        delay(1000);
        findDistance();
        if (distance>20)
        {
          SM.write(90);
          delay(1000);
          leftward();
          delay(1000);
          Stop();
        }
        else
        {
          SM.write(90);
          delay(1000);
          rightward();
          delay(1500);
          Stop();
          
        }
      }
    }
  }
}
void forward() 
{
  digitalWrite(mtrr1,LOW);
   digitalWrite(mtrr2,HIGH);
   digitalWrite(mtrl1,LOW);
   digitalWrite(mtrl2,HIGH);
}
void backward()
{
  digitalWrite(mtrr1,HIGH);
   digitalWrite(mtrr2,LOW);
   digitalWrite(mtrl1,HIGH);
   digitalWrite(mtrl2,LOW);
}
void leftward() 
{
  digitalWrite(mtrr1,LOW);
   digitalWrite(mtrr2,HIGH);
   digitalWrite(mtrl1,HIGH);
   digitalWrite(mtrl2,LOW);
}
void rightward() 
{
  digitalWrite(mtrr1,HIGH);
   digitalWrite(mtrr2,LOW);
   digitalWrite(mtrl1,LOW);
   digitalWrite(mtrl2,HIGH);
}
void Stop() 
{
  digitalWrite(mtrr1,LOW);
   digitalWrite(mtrr2,LOW);
   digitalWrite(mtrl1,LOW);
   digitalWrite(mtrl2,LOW);
}

void findDistance() 
{
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(60);

}
