#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#define NEO_PIN 8
#define NUM_LEDS 12

int A1A = 6;
int A2A = 7;

int rval = 0;
int gval = 0;
int bval = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_NeoPixel LED = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT); 
  //Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  LED.begin();
  LED.setBrightness(100);
  pinMode(A1A,OUTPUT);
  pinMode(A2A, OUTPUT);

  LED.setPixelColor(0, LED.Color(255, 0, 0));
  LED.setPixelColor(1, LED.Color(255, 0, 0));
  LED.setPixelColor(2, LED.Color(0, 0, 255));
  LED.setPixelColor(3, LED.Color(255, 0, 0));
  LED.setPixelColor(4, LED.Color(255, 0, 0));
  LED.setPixelColor(5, LED.Color(0, 0, 255));
  LED.setPixelColor(6, LED.Color(255, 0, 0));
  LED.setPixelColor(7, LED.Color(255, 0, 0));
  LED.setPixelColor(8, LED.Color(0, 0, 255));
  LED.setPixelColor(9, LED.Color(255, 0, 0));
  LED.setPixelColor(10, LED.Color(255, 0, 0));
  LED.setPixelColor(11, LED.Color(0, 0, 255));

}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int Soil_moisture = analogRead(A1); 
  lcd.setCursor(0,1);
  lcd.print("Moisture : ");
  lcd.print(Soil_moisture);
  
  lcd.setCursor(0,0);
  //lcd.print("Light : ");
  //lcd.print(light);

  
  if(light>400 && Soil_moisture>800){
    LED.setBrightness(0);
    digitalWrite(A1A, HIGH);
    LED.show();
    delay(40000);
    digitalWrite(A1A, LOW);
    digitalWrite(A2A, LOW);
  }

  if(light>400 && Soil_moisture<=800){
    LED.setBrightness(0);
    digitalWrite(A1A, LOW);
    digitalWrite(A2A, LOW);
    LED.show();
    delay(10000);
  }

  if(light<=400 && Soil_moisture>800){
    if((400-light)>255)
      LED.setBrightness(255);
    else
      LED.setBrightness(400-light);
    digitalWrite(A1A, HIGH);
    LED.show();
    delay(10000);
    digitalWrite(A1A, LOW);
    digitalWrite(A2A, LOW);
  }
  
  if(light<=400 && Soil_moisture<=800){
    if((400-light)>255)
      LED.setBrightness(255);
    else
    LED.setBrightness(400-light);
    LED.show();
    digitalWrite(A1A, LOW);
    digitalWrite(A2A, LOW);
    delay(10000);
  }

  while(Serial.available()>0){
    rval = Serial.parseInt();
    gval = Serial.parseInt();
    bval = Serial.parseInt();

    if(Serial.read() =='\n'){
      LED.setPixelColor(0, LED.Color(rval, gval, bval));
      LED.setPixelColor(1, LED.Color(rval, gval, bval));
      LED.setPixelColor(2, LED.Color(rval, gval, bval));
      LED.setPixelColor(3, LED.Color(rval, gval, bval));
      LED.setPixelColor(4, LED.Color(rval, gval, bval));
      LED.setPixelColor(5, LED.Color(rval, gval, bval));
      LED.setPixelColor(6, LED.Color(rval, gval, bval));
      LED.setPixelColor(7, LED.Color(rval, gval, bval));
      LED.setPixelColor(8, LED.Color(rval, gval, bval));
      LED.setPixelColor(9, LED.Color(rval, gval, bval));
      LED.setPixelColor(10, LED.Color(rval, gval, bval));
      LED.setPixelColor(11, LED.Color(rval, gval, bval));
      lcd.setCursor(0,0);
      lcd.print(rval);
    }
  }

  lcd.clear();
}
