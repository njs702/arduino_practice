int led0_Pin = 0;  // 1번째 LED
int led1_Pin = 1;  // 2번째 LED
int led2_Pin = 2;  // 3번째 LED
int led3_Pin = 3;  // 4번째 LED
int led4_Pin = 4;  // 5번째 LED
int button0_Pin = 8;   // 1번째 스위치
int button1_Pin = 9;   // 2번째 스위치
int button2_Pin = 10;  // 3번째 스위치
int button3_Pin = 11;  // 4번째 스위치
int button4_Pin = 12;  // 5번째 스위치

void setup()  // 초기화
{   
    //randomSeed(analogRead(0));
    pinMode(LED_BUILTIN,OUTPUT);
    pinMode(led0_Pin, OUTPUT);  // 1번째 LED 핀(Pin) 출력 포트 설정
    pinMode(led1_Pin, OUTPUT);  // 2번째 LED 핀(Pin) 출력 포트 설정
    pinMode(led2_Pin, OUTPUT);  // 3번째 LED 핀(Pin) 출력 포트 설정
    pinMode(led3_Pin, OUTPUT);  // 4번째 LED 핀(Pin) 출력 포트 설정
    pinMode(led4_Pin, OUTPUT);  // 5번째 LED 핀(Pin) 출력 포트 설정
    pinMode(button0_Pin, INPUT);  // 1번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button1_Pin, INPUT);  // 2번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button2_Pin, INPUT);  // 3번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button3_Pin, INPUT);  // 4번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button4_Pin, INPUT);  // 5번째 스위치 핀(Pin) 입력 포트 설정
    digitalWrite(led0_Pin,LOW);
    digitalWrite(led1_Pin,LOW);
    digitalWrite(led2_Pin,LOW);
    digitalWrite(led3_Pin,LOW);
    digitalWrite(led4_Pin,LOW);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    
    digitalWrite(led0_Pin,HIGH);
    delay(1);
    digitalWrite(led0_Pin,LOW);
    delay(9);
    
}