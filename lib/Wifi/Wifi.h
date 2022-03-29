
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

const char *wssid = "when you can fly";
const char *wpassword = "huskystar643";

class WifiTask : public Task
{
public:
    void setup()
    {
        uint32_t notConnectedCounter = 0;
        uint32_t notConnectedRetries = 150;

        Serial.println();
        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(wssid);

        WiFi.begin(wssid, wpassword);

        while (WiFi.status() != WL_CONNECTED)
        {
            delay(100);
            Serial.print(".");
            notConnectedCounter++;
            if (notConnectedCounter > notConnectedRetries)
            { // Reset board if not connected after some time
                Serial.println("Resetting due to Wifi not connecting...");
                ESP.restart();
            }
        }

        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());

        ArduinoOTA.begin();
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
        ArduinoOTA.handle();
        delay(5000);
    }
} wifi_task;
