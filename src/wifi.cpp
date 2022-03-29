#if defined(ESP8266)
#include <ESP8266WiFi.h> //https://github.com/esp8266/Arduino
#else
#include <WiFi.h>
#endif

#include <ESPAsyncWebServer.h>   //Local WebServer used to serve the configuration portal
#include <ESPAsyncWiFiManager.h> //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include <time.h>
#include <stdio.h>

#include "httpd.h"
#include "wifi.h"

DNSServer dns;

int CONFIG_PORTAL_TIMEOUT = 90;        // test cp timeout
int WIFI_CONFIG_TRIGGER_PIN = 0;       // gpio for button
bool WIFI_MANAGER_IS_BLOCKING = false; // use blocking or non blocking mode, non global params wont work in non blocking

const char *wssid = "when you can fly";
const char *wpassword = "huskystar643";

unsigned int timeout = 120; // seconds to run for
unsigned int startTime = millis();
bool portalRunning = false;
bool startAP = false; // start AP and webserver if true, else start only webserver

void wifiLoop()
{

#ifdef USEOTA
    ArduinoOTA.handle();
#endif
}

void wifiSetup()
{
    AsyncWiFiManager wifiManager(&server, &dns);
    // reset settings - for testing
    // wifiManager.resetSettings();

    wifiManager.autoConnect();
    Serial.println("connected...yeey :)");

#ifdef USEOTA

#if defined(_DEBUG_) || defined(_TEST_)
    Serial.println("Allowing OTA");
#endif

    ArduinoOTA.onStart([]()
                       { Serial.println("\nOTA Start"); });

    ArduinoOTA.onEnd([]()
                     { Serial.println("\nOTA End"); });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                          { Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100))); });

    ArduinoOTA.onError([](ota_error_t error)
                       {
        Serial.printf("OTA Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
            Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR)
            Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR)
            Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR)
            Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR)
            Serial.println("End Failed"); });

    // ArduinoOTA.setTimeout(20000);
    // ArduinoOTA.
    ArduinoOTA.begin();

#endif
}
