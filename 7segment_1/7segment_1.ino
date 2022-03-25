// 0에서 9까지 숫자 표현을 위한
// 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
  0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6
};
int digit_select_pin[] = {66, 67, 68, 69}; // 자릿수 선택 핀
// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {8, 9, 2, 3, 4, 6, 5, 1};

void setup() {
    for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
        pinMode(segment_pin[i], OUTPUT);
    }
}

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int number) { 
    for (int i = 0; i < 8; i++) {
        boolean on_off = bitRead(patterns[number], 7 - i);
        digitalWrite(segment_pin[i], on_off);
    }
}

void loop() {
    for(int i=0;i<10;i++){
        show_digit(i);
        delay(500);
    }
}