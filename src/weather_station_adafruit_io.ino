#include "config.h"

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DATA_PIN 2

DHT_Unified dht(DATA_PIN, DHT22);

AdafruitIO_Feed *temperature = io.feed("temp-feed");
AdafruitIO_Feed *humidity = io.feed("humidity-feed");

void setup() {
  dht.begin();
  io.connect();
  while(io.status() < AIO_CONNECTED) {
    delay(500);
  }
}

void loop() {
  io.run();

  sensors_event_t event;
  dht.temperature().getEvent(&event);

  float celsius = event.temperature;
  float fahrenheit = (celsius * 1.8) + 32;

  temperature->save(fahrenheit);
  dht.humidity().getEvent(&event);
  humidity->save(event.relative_humidity);

  delay(DELAY_MINS*60*1000);
}
