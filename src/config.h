// Adafruit IO username and key
#define IO_USERNAME    "username"
#define IO_KEY         "key"

// WIFI creds
#define WIFI_SSID       "ssid"
#define WIFI_PASS       "pw"

// Time between publishing sensor data to feed.
#define DELAY_MINS 10

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

