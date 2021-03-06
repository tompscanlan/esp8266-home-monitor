#include <Arduino.h>

#include <Scheduler.h>

int LED1 = LED_BUILTIN;
int LED2 = LED_BUILTIN_AUX;

class BlinkTask : public Task
{
protected:
    void setup()
    {
        state1 = HIGH;
        state2 = LOW;

        pinMode(LED1, OUTPUT);
        pinMode(LED2, OUTPUT);
    }

    void loop()
    {
        state1 = state1 == HIGH ? LOW : HIGH;
        state2 = state2 == HIGH ? LOW : HIGH;

        sprintf(log, "LED state %d, %d\n", state1, state2);
        Serial.print(log);

        digitalWrite(LED1, state1);
        digitalWrite(LED2, state2);
        delay(1000);
    }

private:
    char log[100];
    uint8_t state1;
    uint8_t state2;
} blink_task;
