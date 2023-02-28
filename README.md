# SquaryFi

<img src ="https://cdn.shopify.com/s/files/1/1217/2104/products/2_12d19ffa-bcda-47bf-8ea9-bb76fc40aee3.png?v=1670307456&width=400" />

SquaryFi is an ESP-12E-based square LCD display that features a compact and appealing 1.54-inch display module. This wi-fi device has 65K RGB colors, a clear and vivid presenting effects opens many more possibilities to boost its engagement with all of your projects. To limit the number of IO pins required, SquaryFi incorporates an integrated ST7789 Driver and SPI Interface for LCD.

## Features:

* On board ESP8266-12E module
* 1.54" LCD Display
* Resolution of 240 x 240
* Operating voltage of 3.3V
* USB type-C
* Battery connector
* Charging IC(MCP73831)

## Features of LCD:

* Operating voltage of 3.3v/5v
* Resolution 240 x 240 pixels
* SPI communication Interface
* 350 nits brightness
* ST7789 driver
* IPS display panel
* Pixel Size 0.1101 x 0.1035mm
* ST7789 driver
* Dimension 35 x 32.00mm
* 65K RGB colors

## Hardware Overview

<img src ="https://github.com/sbcshop/SquaryFi-Software/blob/main/images/Squary%20Fi.png" />


BUTTON 1 - Boot/Flash

BUTTON 2 - GPIO10

BUTTON 3 - GPIO9

BUTTON 4 - Reset


## Working

To start working with our SquaryFi board follow the steps below:

***Step.1 - First thing first,*** install the CP2102 usb driver to detect our board as a usb device in your system. We have provided a ***Zip file (CP210x_VCP_Windows.zip)*** of it in this Repository. After downloading and extracting the zip file locate ***setup file*** compatible with your system and inatall this driver. You can also visit to below link for download the cp2102 drver for your system; ***https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads*** and download the CP210x VCP based on your operating system and install it.

***Step.2 - Getting Ready Arduino IDE***, open the arduino ide and add extension link of ESP8266 board in preference section for this click on Files-->Preferences after this you will get a popup window loacate here Additional boards manager URLs and paste this link ***"http://arduino.esp8266.com/stable/package_esp8266com_index.json"*** the click on OK. After that click on ***Board Manager Icon*** located in left side of the IDE and search for ESP8266 board and Install it.

2. Open Arduino IDE
   <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img6.JPG" />

3. Now install Esp8266 board, for this go to file -> preferences
   <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img7.png" />
  
   * Paste two urls,in "additional board manager urls"
   
     ```http://arduino.esp8266.com/stable/package_esp8266com_index.json```
     
     ```https://dl.espressif.com/dl/package_esp32_index.json```
     
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img8.png" />
   
   * Now install ESP8266 board, go tools -> boards -> board manager
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img9.png" />
     
   * Write ESP8266 in search bar
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img10.png" />
    
   * Lets, check boards are install or not, go to tools -> boards
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img11.png" />
 4. Now go to sketch -> include library -> manage libraries
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img12.png" />
     
 5. Install all libraries which is mention below
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img13.JPG" />
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img14.JPG" />
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img15.JPG" />
    
 6. Choose Port and ESP8266 board from board manager
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img16.png" />
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img17.png" /> 


Similarly install this library as well
* TFT_eSPI.h


***Step.4 - For Compiling and uploading code*** in your SquaryFi board, Open Arduino IDE and click on ***File section*** at the top left corner of ***IDE*** and open any Example from downloaded repostory  provided here. Now, plugin your board in your pc via USB type-c cable and look for the port, if ***you properly connected your board to PC by installing compatible VCP driver(as in Step.1)*** you will get the available port as shown below:

<img src ="https://github.com/sbcshop/SquaryFi-Software/blob/main/images/Scr5.png" />

<img src ="https://github.com/sbcshop/SquaryFi-Software/blob/main/images/Scr4.png" />


Step.5 - After all these setups, click on ***Tick Button*** to compile your code and ***Arrow Button*** to compile and upload the currnet code in your SquaryFi board. 

## Examples Directory

This folder contains exmaple code files according to the basic functionalities we can use in our SquaryFi board


* ***Battery_Level_LCD*** is for display Battery Level on screen and give worning when the battery level decreases(Discharge).

* ***SquaryFi_Client*** is the exmaple code for cummunicating between your SquaryFi board and smartphone. The cummunication can be established by installing an    androide app provided in this Repository. After insatlling the app upload this code in your SquaryFi Board and when it will coonnect to your wifi it show an IP on display. Now, open the installed app and put the IP in addres section and port shold be 80 then click on connect. After succesfull connection you can send data to your SquaryFi board display by using mobile phone

* ***wifi_weather_display*** is the example code for displaying weather data on Screen. For this you only have to update your wifi credentials and you can also change the location of weather data receive from.

* ***Display_images*** is the example code of display images on TFT display. For this, open the code and add the necessary library in main code(Display_images.ino) upload this code to our SquaryFi board. In current exmple code we are showing three different images, you can also modify or add your images by converting it into Hex code(.h file) from below link;
http://javl.github.io/image2cpp/

* ***Button_Demo*** In this example, if you press any of the buttons, B1, B2, and B3, an LED on GPIO16 Pin glows.


## Documentation

* [SquaryFi Hardware](https://github.com/sbcshop/SquaryFi-Hardware)
* [Getting Started with NodeMCU](http://www.nodemcu.com/index_en.html)
* [NodeMCU Github Examples](https://github.com/orgs/nodemcu/repositories)
* [NodeMCU Datasheet](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)

## Related Products

* [SquaryPi](https://shop.sb-components.co.uk/products/squary?variant=40443840921683) -  RP2040 Varient

 ![SquaryPi](https://cdn.shopify.com/s/files/1/1217/2104/products/1_5874b3b5-2a2f-453e-bf54-abbf2a26acb9.png?v=1670307456&width=300)
 
 * [Roundy](https://shop.sb-components.co.uk/products/roundy?variant=39785171681363) - 1.28" Round LCD version based on ESP8266 and RP2040
 
 ![Roundy](https://cdn.shopify.com/s/files/1/1217/2104/products/roundypi.png?v=1650457581&width=300)

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>


