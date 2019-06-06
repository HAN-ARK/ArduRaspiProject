SoftwareSerial esp8266(6, 7); // RX, TX

void setup()
{
  Serial.begin(9600); 
  esp8266.begin(9600);
}

void loop()
{
  while (Serial.available())
    esp8266.write(Serial.read());
  while (esp8266.available())
    Serial.write(esp8266.read());
}
