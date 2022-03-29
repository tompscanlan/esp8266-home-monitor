#include <Arduino.h>
#include "led.h"

void LEDOn()
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void LEDOff()
{
    digitalWrite(LED_BUILTIN, LOW);
}