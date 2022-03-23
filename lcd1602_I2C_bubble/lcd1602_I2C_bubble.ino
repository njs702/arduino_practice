#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27,16,2);

int numbers[800] = {0,};
int number;

void bubble_sort(int dataSet[],int dataSize){
    int temp = 0;
    for(int i=0;i<dataSize-1;i++){
        for(int j=0;j<dataSize-(i+1);j++){
            if(dataSet[j]>dataSet[j+1]){
                temp = dataSet[j+1];
                dataSet[j+1] = dataSet[j];
                dataSet[j] = temp;
            }
        }
    }
}

void setup(){
    Serial.begin(9600);
    /* Serial.begin(9600);
    Serial.print(F("정렬 전 데이터 10개"));
    for(int i=0;i<5;i++){
        Serial.print(F("hi"));
    }
    for(int i=799;i>789;i--){
        Serial.print(F("hi"));
    } */
    //lcd.init();
    //lcd.backlight();
    
    randomSeed(analogRead(0));
    
}

void loop(){
    if(Serial.available()){
        for(int i=0;i<800;i++){
        numbers[i] = random(1,801);
        }
        Serial.print("before");
        for(int i=0;i<10;i++){
            Serial.print(numbers[i]);
        }
        bubble_sort(numbers,800);
        Serial.print("after");
        for(int i=0;i<10;i++){
            Serial.print(numbers[i]);
        }
    }
    
    /* for(int i=0;i<5;i++){
        lcd.setCursor((i*2),0);
        lcd.print(numbers[i]);
    }
    for(int i=0;i<4;i++){
        lcd.setCursor(4*i,1);
        lcd.print(numbers[i+796]);
    }
    lcd.setCursor(0,1);
    lcd.print(numbers[799]); */
    
}