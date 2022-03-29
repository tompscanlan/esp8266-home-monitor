#include <Arduino.h>
#include <Scheduler.h>

// extern long motion;
long motion = 0;
long motionDetect = LOW;
long motionState = LOW;
int pinPIR = D5;

int ledON = LOW;
int ledOFF = HIGH;

int debounceMS = 500;

class PIR : public Task
{
public:
    void setup()
    {
        pinMode(pinPIR, INPUT);
        pinMode(LED_BUILTIN_AUX, OUTPUT);
    }
    void loop()
    {
        delay(100);
        // Serial.print("Sample PIR...");
        // motionDetect = digitalRead(pinPIR);
        // Serial.println(motionDetect ? "Motion" : "No Motion");

        // if (motionDetect == HIGH)
        // {
        //     delay(debounceMS);
        //     if (motionState == LOW)
        //     {
        //         Serial.println("Switch state to motion");
        //         motionState = HIGH;
        //         digitalWrite(LED_BUILTIN_AUX, ledON);
        //     }
        // }
        // else
        // {
        //     delay(debounceMS);
        //     if (motionState == HIGH)
        //     {
        //         Serial.println("Switch state to no motion");
        //         motionState = LOW;
        //         digitalWrite(LED_BUILTIN_AUX, ledOFF);
        //     }
        // }
    }
} PIR_task;