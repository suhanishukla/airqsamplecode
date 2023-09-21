#include "DHT.h"
#define DHT11PINin 14 
#define DHT11PINout 32

DHT dhtin(DHT11PINin, DHT11);
DHT dhtout(DHT11PINout, DHT11); 
void setup()
{
  
  Serial.begin(9600);
/* Start the DHT11 Sensor */
  dhtin.begin();
  dhtout.begin(); 
}

void loop()
{
  float insidehumid = dhtin.readHumidity();
  float insidetemp = dhtin.readTemperature() * 1.8 + 32;
  float outsidehumid = dhtout.readHumidity(); 
  float outsidetemp = dhtout.readTemperature() * 1.8 + 32; 
  Serial.print("insideTemperature: ");
  Serial.print(insidetemp);
  //Serial.print("C ");
  Serial.print("insideHumidity: ");
  Serial.println(insidehumid);
  Serial.print("outside temp: "); 
  Serial.println(outsidetemp); 
  Serial.print("outide humid: ");
  Serial.println(outsidehumid); 

  delay(1000);
}