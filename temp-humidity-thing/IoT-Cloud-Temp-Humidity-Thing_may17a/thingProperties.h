#include <ArduinoIoTCloud.h>
#include <WiFiConnectionManager.h>

const char THING_ID[] = "9bbaa63b-ba60-4201-9811-db72fff39392";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)


float humidity;
float temperature;

void initProperties(){
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(humidity, READ, ON_CHANGE, NULL, 1.000000);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL, 0.500000);
}

ConnectionManager *ArduinoIoTPreferredConnection = new WiFiConnectionManager(SSID, PASS);
