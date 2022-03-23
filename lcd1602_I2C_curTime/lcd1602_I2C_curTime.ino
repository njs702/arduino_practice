#include <LiquidCrystal_I2C.h>

//#include <LiquidCrystal_I2C_Hangul.h>

#include <core_build_options.h>
#include <swRTC.h>
#include <stdlib.h>

//#include <core_build_options.h>
//#include <swRTC.h>

swRTC rtc; //클래스 개체 선언
LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    lcd.init(); // lcd 초기화
    lcd.backlight();
    rtc.stopRTC();
    rtc.setTime(12,0,0);
    rtc.setDate(23,3,2022);
    rtc.startRTC();
}

void loop(){
    
    int a = 4;
    lcd.setCursor(0,0);
    //itoa(rtc.getYear(),year,5);
    lcd.print(rtc.getYear());
    lcd.setCursor(a,0);
    lcd.print('/');
    if(rtc.getMonth()<10){
        lcd.setCursor(a+1,0);
        lcd.print(rtc.getMonth());
        lcd.print('/');
        lcd.setCursor(a+3,0);
        lcd.print(rtc.getDay());
    }
    else{
        lcd.setCursor(a+1,0);
        lcd.print(rtc.getMonth());
        lcd.print('/');
        lcd.setCursor(a+4,0);
        lcd.print(rtc.getDay());
    }
    
    lcd.setCursor(0,1);
    lcd.print(rtc.getHours());
    lcd.setCursor(2,1);
    lcd.print(':');
    lcd.setCursor(3,1);
    lcd.print(rtc.getMinutes(),DEC);
    lcd.setCursor(5,1);
    lcd.print(':');
    lcd.setCursor(6,1);
    lcd.print(rtc.getSeconds());
    
    
}