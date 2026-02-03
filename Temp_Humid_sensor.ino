
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
  Serial.println("TEMPERATURE AND HUMIDITY DEVICE");
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  
}

void loop(){
   if  (convertF(DHT.temperature)> 80.00){
digitalWrite(9,HIGH);

digitalWrite(13,HIGH);

  }
  else{
    digitalWrite(13,LOW);
  }
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print("C ");
  Serial.print("or ");
  Serial.print(convertF(DHT.temperature));
  Serial.println("F ");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("% ");

  delay(5000);
     
}
float convertF(float a){
  a *=9;
  a/= 5;
  a+= 32;
  return a;
}

