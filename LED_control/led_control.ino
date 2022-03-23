#include <LiquidCrystal_I2C.h>

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
long temp = 0;
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

void func_stair(){
    digitalWrite(led0_Pin,HIGH);
    delay(500);
    digitalWrite(led0_Pin,LOW);
    
    digitalWrite(led1_Pin,HIGH);
    delay(500);
    digitalWrite(led1_Pin,LOW);

    digitalWrite(led2_Pin,HIGH);
    delay(500);
    digitalWrite(led2_Pin,LOW);

    digitalWrite(led3_Pin,HIGH);
    delay(500);
    digitalWrite(led3_Pin,LOW);

    digitalWrite(led4_Pin,HIGH);
    delay(500);
    digitalWrite(led4_Pin,LOW);
}

void func_stair_back(){
    digitalWrite(led4_Pin,HIGH);
    delay(500);
    digitalWrite(led4_Pin,LOW);
    
    digitalWrite(led3_Pin,HIGH);
    delay(500);
    digitalWrite(led3_Pin,LOW);

    digitalWrite(led2_Pin,HIGH);
    delay(500);
    digitalWrite(led2_Pin,LOW);

    digitalWrite(led1_Pin,HIGH);
    delay(500);
    digitalWrite(led1_Pin,LOW);

    digitalWrite(led0_Pin,HIGH);
    delay(500);
    digitalWrite(led0_Pin,LOW);
}

void func_stair_go_back(){
    func_stair();
    func_stair_back();
}

void func_sos(){
    for(int i=0;i<3;i++){
        digitalWrite(led0_Pin,HIGH);
        digitalWrite(led1_Pin,HIGH);
        digitalWrite(led2_Pin,HIGH);
        digitalWrite(led3_Pin,HIGH);
        digitalWrite(led4_Pin,HIGH);
        delay(200);
        digitalWrite(led0_Pin,LOW);
        digitalWrite(led1_Pin,LOW);
        digitalWrite(led2_Pin,LOW);
        digitalWrite(led3_Pin,LOW);
        digitalWrite(led4_Pin,LOW);
        delay(200);
    }

    for(int i=0;i<3;i++){
        digitalWrite(led0_Pin,HIGH);
        digitalWrite(led1_Pin,HIGH);
        digitalWrite(led2_Pin,HIGH);
        digitalWrite(led3_Pin,HIGH);
        digitalWrite(led4_Pin,HIGH);
        delay(1000);
        digitalWrite(led0_Pin,LOW);
        digitalWrite(led1_Pin,LOW);
        digitalWrite(led2_Pin,LOW);
        digitalWrite(led3_Pin,LOW);
        digitalWrite(led4_Pin,LOW);
        delay(1000);
    }

    for(int i=0;i<3;i++){
        digitalWrite(led0_Pin,HIGH);
        digitalWrite(led1_Pin,HIGH);
        digitalWrite(led2_Pin,HIGH);
        digitalWrite(led3_Pin,HIGH);
        digitalWrite(led4_Pin,HIGH);
        delay(200);
        digitalWrite(led0_Pin,LOW);
        digitalWrite(led1_Pin,LOW);
        digitalWrite(led2_Pin,LOW);
        digitalWrite(led3_Pin,LOW);
        digitalWrite(led4_Pin,LOW);
        delay(200);
    }
}

void func_game(){
    if(temp == 1){
        digitalWrite(led0_Pin,HIGH);
        delay(1000);
        digitalWrite(led0_Pin,LOW);
    }

    if(temp == 2){
        digitalWrite(led1_Pin,HIGH);
        delay(1000);
        digitalWrite(led1_Pin,LOW);
    }

    if(temp == 3){
        digitalWrite(led2_Pin,HIGH);
        delay(1000);
        digitalWrite(led2_Pin,LOW);
    }

    if(temp == 4){
        digitalWrite(led3_Pin,HIGH);
        delay(1000);
        digitalWrite(led3_Pin,LOW);
    }

    if(temp == 5){
        digitalWrite(led4_Pin,HIGH);
        delay(1000);
        digitalWrite(led4_Pin,LOW);
    }
}

/* 스위치를 누를 시에 LED가 켜지도록 한다 */
void loop()  // 무한 루프
{   
    temp = random(1,6);
    if(digitalRead(button0_Pin)==LOW){      
        func_stair();
    }

    if(digitalRead(button1_Pin)==LOW){      
        func_stair_back();
    }
 
    if(digitalRead(button2_Pin)==LOW){      
        func_stair_go_back();            
    }
    if(digitalRead(button3_Pin)==LOW){      
        func_sos();          
    }

    if(digitalRead(button4_Pin)==LOW){      
        func_game();       
    }
}            