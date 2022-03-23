#include <limits.h>


void BubbleSort(uint16_t DataSet[], uint16_t length){
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-(i+1); j++)
        {
            if (DataSet[j] > DataSet[j+1])
            {
                int temp=DataSet[j+1];
                DataSet[j+1]=DataSet[j];
                DataSet[j]=temp;
            }
            
        }
        
    }
    
}
void MakeDataSet(uint16_t DataSet[], uint16_t length){
    for (int i = 0; i < length-1; i++)
    {
        DataSet[i]=length-i-1;
    }
    
}
void MakeRandomSet(uint16_t DataSet[], uint16_t length){
    for (int i = 0; i < length-1; i++)
    {
        DataSet[i]=random(UINT16_MAX);  //UINT16_MAX
    }
    
}



void PrintArray(uint16_t DataSet[], uint16_t length){
  
  for (size_t i = 0; i < 10; i++)
  {
    Serial.print(DataSet[i]);
    Serial.print(" ");
  }
  for (size_t i = 0; i < 10; i++)
  {
    Serial.print(DataSet[length-11+i]);
    Serial.print(" ");
  }
  Serial.println("...");
}
void setup()
{

    Serial.begin(9600);
    randomSeed(analogRead(0));

}
void loop()
{
    uint16_t _DataSet[800]={6,4,2,3,1,5};
    uint16_t length=sizeof(_DataSet)/sizeof(_DataSet[0]);
    uint16_t i=0;
    
    Serial.print( "Before : ");
    MakeRandomSet(_DataSet,length);
    PrintArray(_DataSet,length);
    for (size_t i = 0; i < 100; i++)
    {
        //MakeDataSet(_DataSet,length);
        MakeRandomSet(_DataSet,length);
        BubbleSort(_DataSet,length);
    }
    Serial.print( "After : ");
    PrintArray(_DataSet,length);

}