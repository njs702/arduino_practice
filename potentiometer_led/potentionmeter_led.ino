#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int red = 2;
int blue = 3;
int white = 4;

void setup(){
    lcd.init();
    lcd.backlight();
    /* Serial.begin(9600); */
    pinMode(red,OUTPUT);
    pinMode(blue,OUTPUT);
    pinMode(white,OUTPUT);
}

void loop(){
    // A0핀에 아날로그 전압을 디지털 값으로 변환한 후 sensorValue에 저장
    int sensorValue = analogRead(A0);
    String str = String(sensorValue);
    
    lcd.setCursor(0,0);
    lcd.print("resistance:");
    
    lcd.setCursor(11,0);
    lcd.print(str);

    lcd.setCursor(0,1);
    lcd.print("LCD color:");
    
    if(sensorValue < 350){
        digitalWrite(red,HIGH);
        digitalWrite(blue,LOW);
        digitalWrite(white,LOW);
        lcd.setCursor(10,1);
        lcd.print('R');
    }
    else if(sensorValue < 700){
        digitalWrite(red,LOW);
        digitalWrite(blue,HIGH);
        digitalWrite(white,LOW);
        lcd.setCursor(10,1);
        lcd.print('B');
    }
    else{
        digitalWrite(red,LOW);
        digitalWrite(blue,LOW);
        digitalWrite(white,HIGH);
        lcd.setCursor(10,1);
        lcd.print('W');
    }
    
}