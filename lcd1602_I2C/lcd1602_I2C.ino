#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    lcd.init();
    lcd.backlight();
}

void loop(){
    lcd.setCursor(0,0);
    lcd.print("Welcome to");
    lcd.setCursor(3,1);
    lcd.print("the LK world!");
}