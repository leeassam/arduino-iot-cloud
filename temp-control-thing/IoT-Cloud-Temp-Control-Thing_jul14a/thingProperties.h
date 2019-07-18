#include <ArduinoIoTCloud.h>
#include <WiFiConnectionManager.h>

const char THING_ID[] = "822b2632-55e9-43fb-bc24-373f379c20df";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onFanOnChange();
void onMaxTempChange();
void onOverrideFanControlChange();

bool fan_on;
float temperature;
float max_temp;
bool override_fan_control;

void initProperties(){
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(fan_on, READWRITE, ON_CHANGE, onFanOnChange);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL, 0.100000);
  ArduinoCloud.addProperty(max_temp, READWRITE, ON_CHANGE, onMaxTempChange);
  ArduinoCloud.addProperty(override_fan_control, READWRITE, ON_CHANGE, onOverrideFanControlChange);
}

ConnectionManager *ArduinoIoTPreferredConnection = new WiFiConnectionManager(SSID, PASS);
