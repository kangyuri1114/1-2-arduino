//#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
//#define NEO_PIN 8
//#define NUM_LEDS 12

LiquidCrystal lcd(7,6,5,4,3,2);
//Adafruit_NeoPixel funnyNeo = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_RGBW+ NEO_KHZ800);
//int ledBright = 50; //초기 밝기 값

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT); 
  Serial.begin(9600);
  lcd.begin(16,2);
  //funnyNeo.setBrightness(ledBright);
  //funnyNeo.begin();
  //funnyNeo.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0); 
  lcd.setCursor(0,0);
  lcd.print("Light : ");
  lcd.print(light);

if(light>100){
  lcd.setCursor(0,1);
  lcd.print("bright");
  digitalWrite(8,LOW);
}
if(light<=100){
  lcd.setCursor(0,1);
  lcd.print("dark");
  digitalWrite(8,HIGH);
}


delay(500);

Serial.println(light);
}
