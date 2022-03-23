#include <LiquidCrystal_I2C.h>

// 저항의 크기가 변함, 가변 저항
// AD컨버젼 된 값을 시리얼모니터에 표현
// AD컨버젼 된 값은 0~1023으로 디지털 값 표현

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    lcd.init();
    lcd.backlight();
    //Serial.begin(9600);
}

void loop(){
    // A0핀에 아날로그 전압을 디지털 값으로 변환한 후 sensorValue에 저장
    int sensorValue = analogRead(A0);
    /* Serial.print("[LKE LAB]  value : ");  // 시리얼 모니터에 출력할 내용
    Serial.println(sensorValue);  // 시리얼 모니터에 sensorValue 값 출력 */
    lcd.setCursor(0,0);
    lcd.print(sensorValue);
    if(sensorValue>1000){
        lcd.setCursor(3,0);
        
    }
    
    
}