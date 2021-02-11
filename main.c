#include "HueControl.h"
#include <string.h>
#include <stdio.h>


// Wifi network SSID
const char *ssid = "SSID-WLAN";

// Wifi network password
const char *password = "Password";


// IP or Hostname of Hue gateway
String ip="IP";

// Hue gateway user name
String user_name ="user_name" ;
void setup()
{

  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to the WiFi network");
  


}

void loop()
{
    // light 1 ON
  light(1,true);
  delay(500);
   // light 1 OFF
  light(1,false);
  delay(500);
  // group 1 ON 
  group(1,true);
  delay(500);
  // group 1 OFF
  group(1,false);
  delay(500);
  // group 1 100% in 8bit max 255
  brightness("group",1,254);
  delay(500);
  // group 1 0% in 8bit 
  brightness("group",1,0);
  delay(500);
  // light 1 100% in 8bit 
  brightness("light",1,254);
  delay(500);
  // light 1 0% in 8bit
  brightness("light",1,0);
  delay(500);
  // light 1 on White Red, Green, Blue in 8bit 
  color("light",1,255,255,255);
}