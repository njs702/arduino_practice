void setup(){
    Serial.begin(9600);
}

void loop(){
    for(size_t i=0;i<100;i++){
        Serial.println(i);
        delay(500);
    }
    //Serial.print("\n");
}