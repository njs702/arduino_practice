#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

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
    lcd.init();
    lcd.backlight();
    randomSeed(analogRead(0));
    for(int i=0;i<800;i++){
        numbers[i] = random(1,801);
    }
    

}

void loop(){
    bubble_sort(numbers,800);
    if(Serial.available()){
        for(int i =0;i<10;i++){
            Serial.print("작은 숫자 10개 출력");
            Serial.print(numbers[i]);
        }
        for(int i =799;i>789;i++){
            Serial.print("큰 숫자 10개 출력");
            Serial.print(numbers[i]);
        }
    }

}