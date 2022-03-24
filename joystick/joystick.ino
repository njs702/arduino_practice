#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int joystick_x = 0;
int joystick_y = 1;

void Clcd_display(long data, long data2) // 텍스트 LCD 디스플레이 함수
{
    int j, k, l, m, j2, k2, l2, m2 = 0;
    j = (data % 10000) / 1000; //-------1000의자리
    k = (data % 1000) / 100; //-------100의자리
    l = (data % 100) / 10; //-------10의자리
    m = (data % 10);    //-------1의자리

    j2 = (data2 % 10000) / 1000; //-------1000의자리
    k2 = (data2 % 1000) / 100; //-------100의자리
    l2 = (data2 % 100) / 10; //-------10의자리
    m2 = (data2 % 10);    //-------1의자리

    Serial.print("X Axis:");
    Serial.print(j);
    Serial.print(k);
    Serial.print(l);
    Serial.print(m);

    Serial.print("Y Axis:");
    Serial.print(j2);
    Serial.print(k2);
    Serial.print(l2);
    Serial.print(m2);
    /* lcd.setCursor(0, 0); // LCD 문자출력 시작(열,행)라인 설정
    lcd.print("X Axis:"); // 메시지 출력할 내용
    lcd.print(j);   //-------1000의자리
    lcd.print(k);   //-------100의자리
    lcd.print(l);   //-------10의자리
    lcd.print(m);   //-------1의자리

    lcd.setCursor(0, 1); // LCD 문자출력 시작(열,행)라인 설정
    lcd.print("Y Axis:"); // 메시지 출력할 내용
    lcd.print(j2);   //-------1000의자리
    lcd.print(k2);   //-------100의자리
    lcd.print(l2);   //-------10의자리
    lcd.print(m2);   //-------1의자리 */
}

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop(){
    int x = analogRead(joystick_x);      // 조이스틱 X축의 아날로그 신호를 x에 저장
    int y = analogRead(joystick_y);      // 조이스틱 Y축의 아날로그 신호를 y에 저장
    Clcd_display(x, 1024 - y);
    delay(2000);                                  // 100ms만큼 지연
}