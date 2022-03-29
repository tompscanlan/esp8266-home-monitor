#include <Arduino.h>

#include <TaskScheduler.h>

int LED1 = LED_BUILTIN;
int LED2 = LED_BUILTIN_AUX;

// ch 1 : LED is driven by the boolean variable;
// false = OFF, true = ON
#define PERIOD1 500
#define DURATION 10000

void blink1CB();
Task tBlink1(PERIOD1 *TASK_MILLISECOND, DURATION / PERIOD1, &blink1CB, &ts, true);

// === 1 =======================================
bool LED_state = false;
void blink1CB()
{
    if (tBlink1.isFirstIteration())
    {
        _PP(millis());
        _PL(": Blink1 - simple flag driven");
        LED_state = false;
    }

    if (LED_state)
    {
        LEDOff();
        LED_state = false;
    }
    else
    {
        LEDOn();
        LED_state = true;
    }

    if (tBlink1.isLastIteration())
    {
        tBlink2.restartDelayed(2 * TASK_SECOND);
        LEDOff();
    }
}

// class BlinkTask : public Task
// {
// protected:
//     void setup()
//     {
//         state1 = HIGH;
//         state2 = LOW;

//         pinMode(LED1, OUTPUT);
//         pinMode(LED2, OUTPUT);
//     }

//     void loop()
//     {
//         state1 = state1 == HIGH ? LOW : HIGH;
//         state2 = state2 == HIGH ? LOW : HIGH;

//         sprintf(log, "LED state %d, %d\n", state1, state2);
//         Serial.print(log);

//         digitalWrite(LED1, state1);
//         digitalWrite(LED2, state2);
//         delay(1000);
//     }

// private:
//     char log[100];
//     uint8_t state1;
//     uint8_t state2;
// } blink_task;
