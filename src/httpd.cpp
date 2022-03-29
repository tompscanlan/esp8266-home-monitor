#include "httpd.h"
#include "temphumsense.h"

AsyncWebServer server(80);

void prepServer(AsyncWebServer *server)
{
    server->on("/", HTTP_GET, handleMetricsRequest);
    server->on("/metrics", HTTP_GET, handleMetricsRequest);
    server->onNotFound(handleNotFound);
    server->begin();
}

void handleMetricsRequest(AsyncWebServerRequest *request)
{
    char page[1000];
    sprintf(page,
            "# HELP dht22_temperature Temperature in C as measured by a dht22\n"
            "# TYPE dht22_temperature gauge\n"
            "dht22_temperature %f\n\n"
            "# HELP dht22_humidity Humidity as measured by a dht22\n"
            "# TYPE dht22_humidity gauge\n"
            "dht22_humidity %f\n\n",
            temperature, humidity);

    request->send(200, "text/plain", page);
}

void handleNotFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "404: Not found");
}