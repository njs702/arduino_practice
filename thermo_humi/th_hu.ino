#include <dht.h>

static temp_humid_data temp_humid;
dht DHT;
int DHT_11_PIN = 2;

typedef struct{
    float humid; // store humidity value
    float temp; // store temperature value
}temp_humid_data;


void setup(){
    Serial.begin(9600);
}

void loop(){
    DHT.read11(DHT_11_PIN);
    
    temp_humid.humid = DHT.humidity;
    temp_humid.temp = DHT.temperature;

    /* Serial.print("Humidity: ");
    Serial.print(temp_humid.humid);
    Serial.print(" %, Temp: ");
    Serial.print(temp_humid.temp);
    Serial.println(" Celsius"); */
    
    delay(2000);

}