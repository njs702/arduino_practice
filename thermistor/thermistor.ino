#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop() {

    Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    T = T - 273.15;
    lcd.setCursor(0,0);
    lcd.print(T);
    T = (T * 9.0)/ 5.0 + 32.0; 
    lcd.setCursor(0,1);
    lcd.print(T);
    /* Serial.print("Temperature: "); 
    Serial.print(T);
    Serial.println(" F");  */
    delay(500);
}