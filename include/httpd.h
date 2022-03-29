#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

extern AsyncWebServer server;

void prepServer(AsyncWebServer *server);
void handleMetricsRequest(AsyncWebServerRequest *request);
void handleNotFound(AsyncWebServerRequest *request);
