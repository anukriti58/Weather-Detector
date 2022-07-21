#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>


#define DHTPIN 07 

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2); 

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(4,0);
  lcd.print("20UEC027");
  lcd.setCursor(1,1);
  lcd.print("READING SENSOR");
  dht.begin();
}

void loop() {
  
  float temperature, humidity;

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  delay(1000); 

  lcd.clear();

  if (temperature<=15){
   lcd.print("Cold &"); 
  } else if ((temperature>15) && (temperature<=25)){
   lcd.print("Warm &"); 
  } else {
   lcd.print("Hot &"); 
  }
  
  if (humidity<=50){
   lcd.print(" Not Humid");
  } else {
   lcd.print(" Humid");
  }
  
  lcd.setCursor(0,1);
  lcd.print("T:"); 
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");
}
