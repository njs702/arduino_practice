#include <LiquidCrystal_I2C.h>
#define trig 7
#define echo 6

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    lcd.init();
    lcd.backlight();
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
}

int ultra_sonic(){
    float return_time, howlong;
    digitalWrite(trig,HIGH); // 초음파 발사
    delay(5);
    digitalWrite(trig,LOW); // 초음파 발사 정지
    return_time = pulseIn(echo,HIGH);
    howlong = ((float)(340*return_time) / 10000) /2;  // 시간을 거리로 계산
    return howlong;
}

void loop(){
    char buff[10];
    sprintf(buff,"%4d",ultra_sonic());
    lcd.setCursor(0,0);
    lcd.print(buff);
    delay(100);
}