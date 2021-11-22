#include <SimpleDHT.h>

extern float temperature;
extern float humidity;

int pinDHT22 = 2; // D4
SimpleDHT22 dht22(pinDHT22);

class TempHumSenseTask : public Task
{
public:
    void setup()
    {
    }
    void loop()
    {
        Serial.println("=================================");
        Serial.println("Sample DHT22...");

        // read without samples.
        // @remark We use read2 to get a float data, such as 10.1*C
        //    if user doesn't care about the accurate data, use read to get a byte data, such as 10*C.
        int err = SimpleDHTErrSuccess;
        if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
        {
            Serial.print("Read DHT22 failed, err=");
            Serial.print(SimpleDHTErrCode(err));
            Serial.print(",");
            Serial.println(SimpleDHTErrDuration(err));
            delay(2000);
            return;
        }

        Serial.print("Sample OK: ");
        Serial.print((float)temperature);
        Serial.print(" *C, ");
        Serial.print((float)humidity);
        Serial.println(" RH%");

        // DHT22 sampling rate is 0.5HZ. We need to delay before next sample
        delay(5000);
    }
} temphumsense_task;