#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT); 
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0); 
ㅣlcd.setCursor(0,0);
  lcd.print("Light : ");
  lcd.print(light);

if(light>400){
  lcd.setCursor(0,1);
  lcd.print("bright");
  digitalWrite(8,LOW);
}
if(light<=400){
  lcd.setCursor(0,1);
  lcd.print("dark");
  digitalWrite(8,HIGH);
}


delay(500);
}
