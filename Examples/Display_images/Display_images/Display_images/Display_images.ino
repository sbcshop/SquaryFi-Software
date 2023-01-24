
#include <TFT_eSPI.h>
#include "Not_all_heros_wear_capes_lettering.h" //Image 1
#include "Metaverse.h"                          //Image 2
#include "Flower_pot_with_flowers.h"            //Image 3
#include "sb_logo.h"            //Image 4

TFT_eSPI ipsdisp= TFT_eSPI();           

void setup() {
 Serial.begin(115200);        //Initialise UART COmmunication with 115200 bits/s Baud Rate
 ipsdisp.begin();             //Initiatise SPI Bus
 ipsdisp.init();              //Initialise ST7789
 ipsdisp.setRotation(2);      //Value 1 means landescape mode; Value 2 means potrait mode
 ipsdisp.setSwapBytes(true);  //Swap the byte order for pushImage() - corrects endianness
 ipsdisp.fillScreen(TFT_WHITE); 
}

void loop() {
 ipsdisp.pushImage(0,0,240,320,image1);    //ipsdisp.pushImage(x1,y1,x2,y2,array of image 1 containting 16-bit RGB565 data of each pixel) 
 ipsdisp.setCursor(0,295,4);               //ipsdisp.setCurser(x axis,y axis,text font style i.e 1/2/4/6)
 ipsdisp.setTextColor(TFT_CYAN,TFT_BLACK); //ipsdisp.setTextColor(text color,text background color)
 ipsdisp.println(F("IMG TYP:Calligraphy  "));
 delay(10000);
 ipsdisp.pushImage(0,0,240,320,image2);    //ipsdisp.pushImage(x1,y1,x2,y2,array of image 2 containting 16-bit RGB565 data of each pixel) 
 ipsdisp.setCursor(0, 295,4);              //ipsdisp.setCurser(x axis,y axis,text font style i.e 1/2/4/6)
 ipsdisp.setTextColor(TFT_CYAN,TFT_BLACK); //ipsdisp.setTextColor(text color,text background color)
 ipsdisp.println(F("IMG TYP:Animated     "));
 delay(10000); 
 ipsdisp.pushImage(0,0,240,320,image3);    //ipsdisp.pushImage(x1,y1,x2,y2,array of image 3 containting 16-bit RGB565 data of each pixel) 
 ipsdisp.setCursor(0,295,4);               //ipsdisp.setCurser(x axis,y axis,text font style i.e 1/2/4/6)
 ipsdisp.setTextColor(TFT_CYAN,TFT_BLACK); //ipsdisp.setTextColor(text color,text background color)
 ipsdisp.println(F("IMG TYP:HD Photo     "));
 delay(10000);  

  ipsdisp.pushImage(0,0,240,240,image4sb_logo);    //ipsdisp.pushImage(x1,y1,x2,y2,array of image 3 containting 16-bit RGB565 data of each pixel) 
 ipsdisp.setCursor(0,295,4);               //ipsdisp.setCurser(x axis,y axis,text font style i.e 1/2/4/6)
 ipsdisp.setTextColor(TFT_CYAN,TFT_BLACK); //ipsdisp.setTextColor(text color,text background color)
 ipsdisp.println(F("IMG TYP:HD Photo     "));
 delay(10000); 
}
