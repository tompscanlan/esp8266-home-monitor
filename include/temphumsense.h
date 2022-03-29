#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

extern float temperature;
extern float humidity;
extern int pinDHT;

extern DHT_Unified dht;
extern uint32_t tempHumSenseDelayMS;

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)
void tempHumSenseSampleLoop();
void tempHumSenseSetup();