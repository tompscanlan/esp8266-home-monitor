
#include <ESP8266WiFi.h>
#include <Scheduler.h>

const char *ssid = "when you can fly";
const char *password = "huskystar643";

class WifiTask : public Task
{
public:
    void setup()
    {

        Serial.println();
        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(ssid);

        WiFi.begin(ssid, password);

        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.print(".");
        }

        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }
    void loop()
    {
        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("Wifi disconnected!");
        }
        else
        {
            Serial.println("IP address: ");
            Serial.println(WiFi.localIP());
        }
        delay(10000);
    }
} wifi_task;
