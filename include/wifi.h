#ifndef WIFI_H
#define WIFI_H
// #include <ESPAsyncWiFiManager.h> //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include "httpd.h"
// needed for library
// #include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h> //https://github.com/tzapu/WiFiManager
extern DNSServer dns;

extern int CONFIG_PORTAL_TIMEOUT;     // test cp timeout
extern int WIFI_CONFIG_TRIGGER_PIN;   // gpio for button
extern bool WIFI_MANAGER_IS_BLOCKING; // use blocking or non blocking mode, non global params wont work in non blocking
extern const char *wssid;
extern const char *wpassword;

extern bool portalRunning;

extern unsigned int timeout;
extern unsigned int startTime;
extern bool portalRunning;
extern bool startAP;

#define USEOTA
// enable OTA
#ifdef USEOTA
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#endif

void wifiInfo();
void wifiSetup();
void wifiLoop();
#endif