#include <Arduino.h>
#include <unity.h>

#include <ESP8266WiFi.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

const char *wssid = "when you can fly";
const char *wpassword = "huskystar643";

void test_wifi_connect(void)
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
            break;
        }
    }

    TEST_ASSERT_EQUAL(WL_CONNECTED, WiFi.status());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_wifi_connect);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
    if (i < max_blinks)
    {
        RUN_TEST(test_wifi_connect);
        delay(500);
        i++;
    }
    else if (i == max_blinks)
    {
        UNITY_END(); // stop unit testing
    }
}