
#include <ESP8266WebServer.h>

// extern float temperature;
// extern float humidity;
// extern long motion;

ESP8266WebServer server(80); // Create a webserver object that listens for HTTP request on port 80

class ServeHttpTask : public Task
{
protected:
    void setup()
    {
        server.on("/", ServeHttpTask::handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
        server.on("/metrics", ServeHttpTask::handleRoot); // Call the 'handleRoot' function when a client requests URI "/"
        server.onNotFound(handleNotFound);                // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

        server.begin(); // Actually start the server
        Serial.println("HTTP server started");
    }

    void loop()
    {
        server.handleClient(); // Listen for HTTP requests from clients
        delay(1000);
    }

    static void handleRoot()
    {
        char page[1000];
        sprintf(page,
                "# HELP dht22_motion 1 for motion detected, 0 for none as measured by a PIR sensor\n"
                "# TYPE dht22_motion gauge\n"
                "dht22_motion %ld\n\n"
                "# HELP dht22_temperature Temperature in C as measured by a dht22\n"
                "# TYPE dht22_temperature gauge\n"
                "dht22_temperature %f\n\n"
                "# HELP dht22_humidity Humidity as measured by a dht22\n"
                "# TYPE dht22_humidity gauge\n"
                "dht22_humidity %f\n\n",
                motion, temperature, humidity);

        server.send(200, "text/plain", page); // Send HTTP status 200 (Ok) and send some text to the browser/client
    }

    static void handleNotFound()
    {
        server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
    }

private:
    char log[100];
    uint8_t state1;
    uint8_t state2;
} servehttp_task;
