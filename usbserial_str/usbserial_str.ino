#include <string.h>
String input_str;

void setup(){
    Serial.begin(9600); // 시리얼 포트 속도 설정해주기
    pinMode(LED_BUILTIN,OUTPUT);
}

// 간단한 LED 제어 함수
void func_basic_led(){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}
// sos 신호 보내는 함수
void func_sos(){
    for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                    delay(200);                       // wait for a second
                    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
                    delay(200);                       // wait for a second
                }
                for(int j=0;j<3;j++){
                    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                    delay(1000);                       // wait for a second
                    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
                    delay(1000);                       // wait for a second
                }
                for(int j=0;j<3;j++){
                    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
                    delay(200);                       // wait for a second
                    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
                    delay(200);                       // wait for a second
                }
                delay(800);
            }
            
}

void loop(){
    if(Serial.available()){
        input_str = Serial.readStringUntil('\n');
        Serial.println(input_str);
        if(input_str.equals("basic")){
            func_basic_led();
        }
        if(input_str.equals("basic5")){
            for(int i=0;i<5;i++){
                func_basic_led();
            }
        }
        if(input_str.equals("sos")){
            func_sos();
        }
    }
}