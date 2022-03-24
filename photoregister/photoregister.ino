#include <LiquidCrystal_I2C.h>

int red_pin = 3;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    pinMode(red_pin,OUTPUT);
}

void loop(){
    int sensorValue = analogRead(A0);
    char buff[10];
    if(sensorValue<200){
        digitalWrite(red_pin,HIGH);
        lcd.setCursor(0,0);
        sprintf(buff,"%5s","NIGHT");
        lcd.print(buff);
        lcd.setCursor(0,1);
        lcd.print(sensorValue);
        delay(500);
    }
    else{
        digitalWrite(red_pin,LOW);
        lcd.setCursor(0,0);
        sprintf(buff,"%5s","DAY");
        lcd.print(buff);
        lcd.setCursor(0,1);
        lcd.print(sensorValue);
        delay(500);
    }
    //Serial.print(sensorValue);
    //delay(500);

}