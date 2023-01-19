#include "ESP8266WiFi.h"
#include <Arduino_GFX_Library.h>

#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */
Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */,240 /* width */, 240 /* height */,0 /* col offset 1 */, 0 /* row offset 1 */,53 /* col offset 2 */, 40 /* row offset 2 */);
#endif /* !defined(DISPLAY_DEV_KIT) */

#define TFT_BL 12// default backlight pin, you may replace DF_GFX_BL to actual backlight pindsrsfdsrsfdsdzdsad

const char* ssid = "Tech SB_2G";
const char* password =  "jc643111h@";
 
WiFiServer wifiServer(80);
 
void setup() {
 
  Serial.begin(115200);
  gfx->begin();
  gfx->fillScreen(BLACK);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  gfx->setCursor(65, 30);
  gfx->setTextColor(ORANGE);
  gfx->setTextSize(3);
  gfx->println("Client");
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
 
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
 
  gfx->setCursor(35, 60);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println(WiFi.localIP());
  delay(1000);  

  wifiServer.begin();
}
 
void loop()
{

  gfx->setCursor(65, 30);
  gfx->setTextColor(ORANGE);
  gfx->setTextSize(3);
  gfx->println("Client");
  
  WiFiClient client = wifiServer.available();
  if (client) 
  { 
    
    while (client.connected()) 
    {
      while (client.available()>0) 
      {
        char c = client.read();
        Serial.write(c);
        gfx->setCursor(110, 100);
        gfx->setTextColor(ORANGE);
        gfx->setTextSize(5);
        gfx->println(c);
        delay(2000);
        gfx->setCursor(110, 100);
        gfx->setTextColor(BLACK);
        gfx->setTextSize(5);
        gfx->println(c);
        }
      delay(10);
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
