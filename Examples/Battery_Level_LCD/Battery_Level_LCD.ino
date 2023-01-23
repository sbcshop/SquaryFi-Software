#include <ESP8266WiFi.h>
#include <Arduino_GFX_Library.h>


#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

//Arduino_DataBus *bus = create_default_Arduino_DataBus();

Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */,240 /* width */, 240 /* height */,0 /* col offset 1 */, 0 /* row offset 1 */,53 /* col offset 2 */, 40 /* row offset 2 */);
#endif /* !defined(DISPLAY_DEV_KIT) */


int analogInPin  = A0;    // Analog input pin
int sensorValue;          // Analog Output of Sensor
float calibration = 0.25; // Check Battery voltage using multimeter & add/subtract the value
int bat_percentage;
int TFT_BL = 12;

void setup()
{
  Serial.begin(9600);
  delay(100);

    gfx->begin();
    gfx->fillScreen(BLACK);


    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

 
}
 
void loop()
{
  sensorValue = analogRead(analogInPin);
  delay(10);
  float voltage = (((sensorValue * 4.2) / 1024.0) - calibration); //multiply by two as voltage divider network is 100K & 100K Resistor
   // float voltage = (((sensorValue * 3.3) / 1024) + calibration) ; //Caliberation for output voltage

 
  bat_percentage = mapfloat(voltage, 2.8, 4.2, 0, 100); //2.8V as Battery Cut off Voltage & 4.2V as Maximum Voltage
 
  if (bat_percentage >= 100)
  {
    bat_percentage = 100;
  }
  if (bat_percentage <= 15)
  {
    bat_percentage = 15;
    gfx->setTextWrap(true);
    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 50);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("Battery Low! Please Charge");

  }
  if (bat_percentage <= 0)
  {
    bat_percentage = 1;
  }
 
  Serial.print("Analog Value = ");
  Serial.print(sensorValue);
  Serial.print("\t Output Voltage = ");
  Serial.print(voltage);
  Serial.print("\t Battery Percentage = ");
  Serial.println(bat_percentage);
  delay(1000);
  
    gfx->setTextWrap(false);
    //gfx->fillScreen(BLACK);
    gfx->setCursor(5, 70);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println(sensorValue);  

   
    gfx->setTextWrap(false);
    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 50);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("BPercent");

    
    gfx->setTextWrap(false);
    gfx->setCursor(0, 80);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println(bat_percentage);
    
    delay(1500);
}
 
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
