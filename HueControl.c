/*************************************************************
Hue @ ESP32
communication between ESP and Hue gateway
Version: 1.00
by Freddy
function:
Control lights and groups 
*************************************************************/
#include <WiFi.h>
#include <HTTPClient.h>
#include <math.h>
#include <string.h>
#include "HueControl.h"


brightness(char device_type[], byte id, int brightness){
  if(strcmp(device_type,"light"){
     HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/lights/";
  req_string += id;
  req_string += "/state";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"bri\":";
  put_string += brightness;
  put_string += "}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();
  }

  if(strcmp(device_type,"group"){
     HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/groups/";
  req_string += id;
  req_string += "/action";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"bri\":";
  put_string += brightness;
  put_string += "}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();  
  
  }

}
void color(char device_type[], byte id, int red, int green, int blue)
{
   if (red > 0.04045)
  {
    red = pow((red + 0.055) / (1.0 + 0.055), 2.4);
  }
  else
    red = (red / 12.92);

  if (green > 0.04045)
  {
    green = pow((green + 0.055) / (1.0 + 0.055), 2.4);
  }
  else
    green = (green / 12.92);

  if (blue > 0.04045)
  {
    blue = pow((blue + 0.055) / (1.0 + 0.055), 2.4);
  }
  else
    blue = (blue / 12.92);

  float X = red * 0.664511 + green * 0.154324 + blue * 0.162028;
  float Y = red * 0.283881 + green * 0.668433 + blue * 0.047685;
  float Z = red * 0.000088 + green * 0.072310 + blue * 0.986039;
  float x = X / (X + Y + Z);
  float y = Y / (X + Y + Z);

  if(strcmp(device_type,"light"){
  HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/lights/";
  req_string += id;
  req_string += "/state";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"xy\":[";
  put_string += x;
  put_string +=",";
  put_string += y;
  put_string += "]}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();
  }
  if(strcmp(device_type,"group"){
    HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/groups/";
  req_string += id;
  req_string += "/action";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"xy\":[";
  put_string += x;
  put_string +=",";
  put_string += y;
  put_string += "]}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();  
  }

}

void light(byte light_id, bool current_state)
{
  HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/lights/";
  req_string += light_id;
  req_string += "/state";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"on\":";
  put_string += (current_state) ? "true" : "false";
  put_string += "}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}
void group(byte group_id, bool current_state)
{
  HTTPClient http;
  String req_string;
  req_string = "http://";
  req_string += ip;
  req_string += "/api/";
  req_string += user_name;
  req_string += "/groups/";
  req_string += group_id;
  req_string += "/action";
  Serial.println(req_string);
  http.begin(req_string);
  http.addHeader("Content-Type", "text/plain");

  String put_string;
  put_string = "{\"on\":";
  put_string += (current_state) ? "true" : "false";
  put_string += "}";

  int httpResponseCode = http.PUT(put_string);

  if (httpResponseCode > 0)
  {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  }
  else
  {
    Serial.print("Error on sending PUT Request: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}


