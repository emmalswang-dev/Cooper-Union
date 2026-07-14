#include "arduino_secrets.h"

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int kittyX = 0;
int kittyY = 0;

byte testChar[8] = {
  0b00000, 0b01110, 0b10001, 0b10101, 0b10101, 0b10001, 0b01110, 0b00000};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte alien[8] = {
  0b01110,
  0b11111,
  0b10101,
  0b11111,
  0b01110,
  0b01010,
  0b10001,
  0b00000
};

byte pacman[8] = {
  0b01110,
  0b11111,
  0b11100,
  0b11000,
  0b11100,
  0b11111,
  0b01110,
  0b00000
};

byte cat[8] = {
  0b10001,
  0b11111,
  0b10101,
  0b11111,
  0b01110,
  0b01110,
  0b01010,
  0b00000
};


void setup(){
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, alien);
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  Serial.begin(9600);
}
/*
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello!");
}*/

void loop() {
  joystick();
  lcd.clear();
  lcd.setCursor(kittyX, kittyY);
  lcd.write(byte(0));
  delay(1000);

  int valX = analogRead(A0);
  int valY = analogRead(A1);

  Serial.print("X: ");
  Serial.print(valX);
  Serial.print("   Y: ");
  Serial.println(valY);
}

void joystick() {
  int valX = analogRead(A0);
  int valY = analogRead(A1);

  if (valX < 350 && kittyX > 0) {
    kittyX--;
  }

  if (valX > 500 && kittyX < 15) {
    kittyX++;
  }

  if (valY < 350 && kittyY > 0) {
    kittyY--;
  }

  if (valY > 500 && kittyY < 1) {
    kittyY++;
  }
}