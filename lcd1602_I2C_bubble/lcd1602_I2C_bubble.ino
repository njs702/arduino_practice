#include <stdlib.h>
#include <LiquidCrystal_I2C.h>

#define MAX 500
LiquidCrystal_I2C lcd(0x27, 16, 2);
int data[MAX];

void tmp(int *A, int *B)
{
    int tmp;
    tmp = *A;
    *A = *B;
    *B = tmp;
}

void setup()
{
    
    Serial.begin(9600);
    
    for(int i = 0 ; i < MAX ; i++)
        data[i] = rand();
    Serial.print("before \n");
    Serial.println("up");
    for(int i = 0; i<10 ; i++)Serial.println(data[i]);
    Serial.println("down");
    for(int i = 0; i<10 ; i++)Serial.println(data[MAX - 9 + i]);
    for(int j =0;j<MAX ; j++)
        for(int i = 0; i < MAX-1 ; i++)
        {
            if(data[i]<data[i+1])
            {
                tmp(&data[i], &data[i+1]);
            }
        }
    Serial.print("after \n");
    Serial.println("up");
    for(int i = 0; i<10 ; i++)Serial.println(data[i]);
    Serial.println("down");
    for(int i = 0; i<10 ; i++)Serial.println(data[MAX - 9 + i]);
    lcd.init();  
    lcd.backlight();
}
void loop()
{
    //if(Serial.available())
    
        for(int i = 0; i<10 ; i++){
            lcd.setCursor(0, 0); 
            lcd.print(data[i]);
            lcd.setCursor(0, 1); 
            lcd.print(data[MAX - 9 + i]);
            delay(1000);
        }
    
}