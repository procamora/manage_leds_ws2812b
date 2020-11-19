#ifndef _MANAGE_WS2812B_H_
#define _MANAGE_WS2812B_H_

//#include "Adafruit_NeoPixel.h"
#include <Adafruit_NeoPixel.h>

#include "myarray.h"

//Designamos nuestro pin de datos
#define PIN_LEDS D7
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUM_PIXELS     5


class MyManagerWs2812b {
  public:
    MyManagerWs2812b();

    ~MyManagerWs2812b();

    void start();

    void updateBrightness(int newBrightness);

    unsigned int getBrightnessStrip() const;

    void changeMode();

    void changeColour();
    void colourError();

    volatile bool stopMode = false; //variable usada en interupciones
    // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255
    uint32_t red = Adafruit_NeoPixel::Color(255, 0, 0);
    uint32_t green = Adafruit_NeoPixel::Color(0, 255, 0);
    uint32_t blue = Adafruit_NeoPixel::Color(0, 0, 255);
    uint32_t yellow = Adafruit_NeoPixel::Color(255, 255, 0);
    uint32_t purple = Adafruit_NeoPixel::Color(255, 0, 255);
    uint32_t sky_blue = Adafruit_NeoPixel::Color(0, 255, 255);
    uint32_t white = Adafruit_NeoPixel::Color(255, 255, 255);
  private:
    Adafruit_NeoPixel strip;
    MyArray<uint32_t> arrayColours = MyArray<uint32_t>(7);
    unsigned int brightness = 50;
    unsigned int modeStrip = 0;

    //void setColors();
    void insertArrayColours();

    void changeModeLed(bool isChangeMode);

    void colorWipe(uint32_t color);

    void theaterChase(uint32_t color);

    void rainbow();

    void theaterChaseRainbow();

    void staticColour(uint32_t color);

};

#endif
