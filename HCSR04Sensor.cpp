#include <Wire.h>

const int triggerPin = 7;
const int echoPin = 8;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  long duration;
  int distance;
  
  //Ngirim Sinyal
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);
  
  //Ambil waktu
  duration = pulseIn(echoPin, HIGH);
  //Ngitung jarak
  distance = duration * 0.034 / 2;
  
  Serial.println(duration);
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
