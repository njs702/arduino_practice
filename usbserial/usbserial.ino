char character;

// 아두이노 보드가 켜졌을 떄 한 번만 실행되는 함수
void setup(){
    Serial.begin(9600); // 시리얼 포트 속도 설정해주기
    // 이 외에도 시리얼 포트에 대한 추가 설정을 해 주어야 한다
    // 통신 에러 설정 등등

    Serial.println("Hello world!"); // 시리얼 모니터에 문자열 출력
}

// 전원이 공급되는 동안 계속 실행되는 함수
void loop(){
    if(Serial.available()){ // 시리얼 포트 안에 데이터가 들어온다면
        character = Serial.read();
        Serial.print(character);
    }
}