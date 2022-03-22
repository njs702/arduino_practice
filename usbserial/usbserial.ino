#include <string.h>

char character;

// 아두이노 보드가 켜졌을 떄 한 번만 실행되는 함수
void setup(){
    Serial.begin(9600); // 시리얼 포트 속도 설정해주기
    // 이 외에도 시리얼 포트에 대한 추가 설정을 해 주어야 한다
    // 통신 에러 설정 등등

    Serial.println("Hello world!"); // 시리얼 모니터에 문자열 출력

    pinMode(LED_BUILTIN, OUTPUT);
}

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
            }
}

// 전원이 공급되는 동안 계속 실행되는 함수
void loop(){
    
    if(Serial.available()){ // 시리얼 포트 안에 데이터가 들어온다면
        character = Serial.read(); // 통신으로 받은 데이터를 읽어서 저장
        // Serial.print(character); // 해당 데이터 출력

        if(character == 'a'){
            Serial.println("Basic LED control, blink 1");
            func_basic_led();
        }
        
        if(character == 'b'){
            Serial.println("Basic LED control, repeat 5 times");
            for(int i=0;i<5;i++){
                func_basic_led();
            }
        }

        if(character == 'c'){
            Serial.println("Send SOS using LED , repeat 3 times");
            func_sos();
        }

    }
}