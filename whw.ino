#include "DHT.h"

#define SENSOR_PIN 2

DHT dht(SENSOR_PIN, DHT11);

void setup()
{
    Serial.begin(9600);

    dht.begin();
}

void loop()
{
    delay(2000);

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Error reading temp");
    }

    Serial.println(temperature);
    Serial.println(humidity);
}