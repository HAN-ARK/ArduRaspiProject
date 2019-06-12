/*
   Author: Hanbyul Park
   Description: TEJ Final Project
   Date: 06 June, 2019
*/
#include "ESP8266.h"
/*
   Library for allowing Arduino
   to access nodemcu model
   that has pre-installed AT firmware.
*/
#include <SoftwareSerial.h>
/*
   Library for allowing Arduino
   to communicate other module through
   Tx/Rx digital pins
*/

//WIFI Connection Settings
#define SSID "Onestar"
#define PASSWORD "02200820"

//TCP Client configuration for Raspberry Socket Server
#define HOST_NAME "192.168.0.19"
#define HOST_PORT (23)

//SoftwareSerial class configuration
#define TX 9 //D10
#define RX 10  //D9
SoftwareSerial nodemcu(RX, TX);
ESP8266 wifi(nodemcu);

bool isConnected = false;

void setup() {
  Serial.begin(9600);
  Serial.print("setup begin\r\n");

  Serial.print("FW Version:");
  Serial.println(wifi.getVersion().c_str());

  if (wifi.setOprToStationSoftAP())
  {
    Serial.print("to station + softap ok\r\n");
  }
  else
  {
    Serial.print("to station + softap err\r\n");
  }

  if (wifi.joinAP(SSID, PASSWORD))
  {
    Serial.print("Join AP success\r\n");
    Serial.print("IP:");
    Serial.println( wifi.getLocalIP().c_str());
  }
  else
  {
    Serial.print("Join AP failure\r\n");
  }

  if (wifi.disableMUX()) {
    Serial.print("single ok\r\n");
  }
  else
  {
    Serial.print("single err\r\n");
  }

  Serial.print("setup end\r\n");

}

void loop(void)
//Testing
{
  if ( isConnected == false)
  {
    while (1)
    {
      if (wifi.createTCP(HOST_NAME, HOST_PORT))
      {
        Serial.print("create tcp ok\r\n");
        isConnected = true;
        Serial.print("Escape the inner loop\r\n");
        break;
      }
      else
      {
        Serial.print("create tcp err\r\n");
      }
    }
  }
}
