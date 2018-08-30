#include <OneWire.h>
#include <DallasTemperature.h>

#define HW_BUS 2

OneWire oneWire(HW_BUS);
DallasTemperature sensors(&oneWire);

boolean warning;
float temp;

void setup() {
  Serial.begin(9600);
  Serial.println("Thermometer v1.0 started");
  pinMode(LED_BUILTIN,OUTPUT);
  warning=false;
  sensors.begin();  
}

void loop() {
  sensors.requestTemperatures();
  temp=sensors.getTempCByIndex(0);
  Serial.println(temp);
  if(temp<27){ warning=true; }
  if(warning){ digitalWrite(LED_BUILTIN,true); }
  else{ digitalWrite(LED_BUILTIN,false); }
  delay(900000);
}
