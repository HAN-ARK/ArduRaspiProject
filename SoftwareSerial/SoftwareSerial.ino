#include <SerialESP8266wifi.h>
#include <SoftwareSerial.h>

#define RX 9 
#define TX 10 

SoftwareSerial ESP_wifi(RX, TX);
 
void setup() { 
  Serial.begin(9600); 
  Serial.println("SoftwareSerial Test Begin");
  ESP_wifi.begin(9600); 
  Serial.println("ESP8266 Module ready");
  ESP_wifi.setTimeout(5000); 
  delay(1000); 
} 
void loop() { 
  if (Serial.available()){
    ESP_wifi.write(Serial.read()); 
    Serial.println("ESP8266 Module read");
  } 
  if (ESP_wifi.available()) { 
    Serial.write(ESP_wifi.read()); 
    Serial.println("ESP8266 Module write");
  }
      }
