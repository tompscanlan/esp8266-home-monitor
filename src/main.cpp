#include <Arduino.h>

#include <Scheduler.h>
#include "Memory.h"
// #include "Blink.h"
#include "Wifi.h"
#include "TempHumSense.h"
#include "ServeHttp.h"
#include "PIR.h"

extern float temperature;
extern float humidity;
extern long motion;

float temperature = 0;
float humidity = 0;
long motion = 0;

void setup()
{
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);

  Scheduler.start(&wifi_task);
  // Scheduler.start(&blink_task);
  Scheduler.start(&mem_task);
  Scheduler.start(&temphumsense_task);
  Scheduler.start(&PIR_task);
  Scheduler.start(&servehttp_task);
  Scheduler.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Main loop.");
}