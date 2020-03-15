#include "DHT.h"
#define DHTPIN 12     // pin number
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

String TextForSms ;
String humidity = " Humidity: %";
String temperature = "   Temperature";
String sign = " *C";

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT11 test!");
 
  dht.begin();
}

void loop() {
    delay(2000);

    int h = dht.readHumidity();
  // Read temperature as Celsius
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit
  int f = dht.readTemperature(true);
  
    if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int hi = dht.computeHeatIndex(f, h);
  
  TextForSms = TextForSms + "Humidity: ";
  TextForSms.concat(h);
  TextForSms = TextForSms + "%    Temperature: ";
  TextForSms.concat(t);
  TextForSms = TextForSms + "*C";
  Serial.println(TextForSms);
  delay(2000);
  TextForSms = " ";
  
   if ( t > 37 )
   Serial.println("Temperature Exceeded"); 

}
