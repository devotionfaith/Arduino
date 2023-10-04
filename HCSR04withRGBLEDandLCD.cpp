#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(32,16,2);
const int triggerPin = 7;
const int echoPin = 8;
const int redPin = 4;
const int bluePin = 3;
const int greenPin = 2;
const int threshold = 300;
bool lcdStatus = false;
int lcdContent = 0;

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  long duration;
  float distance;
 
  
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
  
  if(distance < 10){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    lcdContent = 0;
  }else if(distance > 10 && distance <=threshold){
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    lcdContent=1;
  }else{
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    lcdContent=2;
  }
  
  if (Serial.available() > 0) {
    String command = Serial.readString();
    if (command == "on") {
      lcdStatus = true;
    } else if (command == "off") {
      lcdStatus = false;
    }
  }
    if (lcdStatus) {
      lcd.init();
  	  lcd.backlight();
       if(lcdContent==0){
		   lcd.clear();
		   lcd.setCursor(0,0);
		   lcd.print("Object Detected");
		   lcd.setCursor(0,1);
		   lcd.print("Jarak : ");
		   lcd.setCursor(6, 1);
		   lcd.print(distance);
 		   lcd.print(" cm");
 		 }else if(lcdContent==1){
  		  lcd.clear();
 		  lcd.setCursor(0,0);
  		  lcd.print("Object Detected");
   		  lcd.setCursor(6, 1);
 		  lcd.print("Jarak > 10 cm");
         
  		}else if(lcdContent==2){
    	  lcd.clear();
   	 	  lcd.setCursor(0,0);
   		  lcd.print("Object Undetected");
       }else{
         lcd.clear();
       }
      } else {
        lcd.clear();
        lcd.noBacklight();
      }
  delay(1000);
}
