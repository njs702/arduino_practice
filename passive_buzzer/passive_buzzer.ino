#include <LiquidCrystal_I2C.h>

#define A 262 // 도 
#define B 294 // 레 
#define C 330 // 미 
#define D 349 // 파 
#define E 392 // 솔 
#define _F 440 // 라 
#define G 494 // 시 
#define H 523 // 도

#define B5 587 // 5옥타브 레
#define C5 659 // 5옥타브 미
#define D5 698 // 5옥타브 파
#define E5 784 // 5옥타브 솔
#define F5 880 // 5옥타브 라
#define G5 988 // 5옥타브 시
#define H5 1046 // 6옥타브 도


LiquidCrystal_I2C lcd(0x27,16,2);

int buzzer_pin = 6;
int button0_Pin = 8;   // 1번째 스위치
int button1_Pin = 9;   // 2번째 스위치
int button2_Pin = 10;  // 3번째 스위치
int melody[4][70] = {
    {E,E,_F,_F,E,E,C,E,E,C,C,B,E,E,_F,_F,E,E,C,E,C,B,C,A}, // 학교종이 떙떙떙
    {E,C,C,E,C,A,B,C,B,A,C,E,H,E,H,E,H,E,C,E,B,D,C,B,A}, // 산토끼
    {523,523,523,523,523,
    659,784,784,659,523,
    784,784,659,784,784,659,
    523,523,523,
    
    784,784,659,523,
    784,784,784,
    784,784,659,523,
    784,784,784,
    
    784,784,659,523,
    784,784,784,880,784,
    1047,784,1047,784,
    659,587,523}, // 곰 세마리
};

// 곰 세마리 박자
int noteDurations[]={ 
    4,8,8,4,4, 
    4,8,8,4,4, 
    8,8,4,8,8,4, 
    4,4,2, 
    4,4,4,4, 
    4,4,2, 
    4,4,4,4, 
    4,4,2, 
    4,4,4,4, 
    8,8,8,8,2, 
    4,4,4,4, 
    4,4,2 
};

int cur_num = 0;

void setup(){
    pinMode(buzzer_pin,OUTPUT);
    pinMode(button0_Pin, INPUT_PULLUP);  // 1번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button1_Pin, INPUT_PULLUP);  // 2번째 스위치 핀(Pin) 입력 포트 설정
    pinMode(button2_Pin, INPUT_PULLUP);  // 3번째 스위치 핀(Pin) 입력 포트 설정
    lcd.init();
    lcd.backlight();
}

void school_bell(){
    // 학교종이 땡떙땡
    for(int i=0;i<12;i++){
        tone(buzzer_pin,melody[cur_num][i],200);
        delay(300);
        if(i==6){
            delay(300);
        }
    }
    delay(700);

    for(int i=12;i<sizeof(melody[cur_num])/sizeof(int);i++){
        tone(buzzer_pin,melody[cur_num][i],200);
        delay(300);
        if(i==18){
            delay(300);
        }
    }
    //noTone(buzzer_pin);
}

void mountain_rabbit(){
    for(int i=0;i<12;i++){
        tone(buzzer_pin,melody[cur_num][i],200);
        delay(500);
        if(i == 5){
            delay(300);
        }
    }
    delay(700);
    for(int i=12;i<sizeof(melody[cur_num])/sizeof(int);i++){
        tone(buzzer_pin,melody[cur_num][i],200);
        delay(300);
        if(i==18){
            delay(300);
        }
    }
    //noTone(buzzer_pin);
    
}

void bear3(){
    for (int i = 0; i < 49; i++) { 
        int Durations = 1000/noteDurations[i]; // 음계의 음길이 계산 
        tone(buzzer_pin, melody[cur_num][i], Durations); 
        int pauseBetweenNotes = Durations *1.3 ; 
        delay(pauseBetweenNotes); 
        noTone(buzzer_pin); 
    }

}

void loop(){
    char buff[10];
    if(cur_num == 0){
        lcd.setCursor(0,0);
        sprintf(buff,"%10s","school");
        lcd.print(buff);
    }

    if(cur_num == 1){
        lcd.setCursor(0,0);
        sprintf(buff,"%10s","rabbit");
        lcd.print(buff);
    }

    if(cur_num == 2){
        lcd.setCursor(0,0);
        sprintf(buff,"%10s","bear3");
        lcd.print(buff);
    }

    if(digitalRead(button0_Pin)==LOW){
        if(cur_num == 0){
            school_bell();
        }
        if(cur_num == 1){
            mountain_rabbit();
        }
        if(cur_num == 2){
            bear3();
        }
    }

    if(digitalRead(button1_Pin)==LOW){
        //noTone(buzzer_pin);
        delay(500); // 값이 순간적으로 여러 번 바뀔 수 있는 것을 방지
        if(cur_num == 0){
            cur_num = 2;
        }
        else cur_num--;
    }

    if(digitalRead(button2_Pin)==LOW){
        //noTone(buzzer_pin);
        delay(500); // 값이 순간적으로 여러 번 바뀔 수 있는 것을 방지
        if(cur_num == 2){
            cur_num = 0;
        }
        else cur_num++;
    }

}