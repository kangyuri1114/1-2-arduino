#include <LiquidCrystal_I2C.h>

#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NEO_PIN 8
#define NUM_LEDS 12

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_NeoPixel LED = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT); 
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  LED.begin();
  LED.setBrightness(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int Soil_moisture = analogRead(A1); 
  lcd.setCursor(0,1);
  lcd.print("moisture : ");
  lcd.print(Soil_moisture);
  
  lcd.setCursor(0,0);
  lcd.print("Light : ");
  lcd.print(light);

  if(light>400){
    lcd.setCursor(0,1);
    //lcd.print("bright");
    digitalWrite(8,LOW);
  }
  if(light<=400){
    lcd.setCursor(0,1);
    //lcd.print("dark    ");
    digitalWrite(8,HIGH);
    LED.setBrightness(400-light);
  }

  LED.setPixelColor(0, LED.Color(0, 150, 0));
  LED.setPixelColor(1, LED.Color(0, 150, 0));
  LED.setPixelColor(2, LED.Color(0, 150, 0));
  LED.setPixelColor(3, LED.Color(0, 150, 0));
  LED.setPixelColor(4, LED.Color(0, 150, 0));
  LED.setPixelColor(5, LED.Color(0, 150, 0));
  LED.setPixelColor(6, LED.Color(0, 150, 0));
  LED.setPixelColor(7, LED.Color(0, 150, 0));
  LED.setPixelColor(8, LED.Color(0, 150, 0));
  LED.setPixelColor(9, LED.Color(0, 150, 0));
  LED.setPixelColor(10, LED.Color(0, 150, 0));
  LED.setPixelColor(11, LED.Color(0, 150, 0));
  
  LED.show();
  delay(3000);
  Serial.println(Soil_moisture);
  lcd.clear();
}
