#ifndef _MANAGE_WS2812B_H_
#define _MANAGE_WS2812B_H_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "myarray.h"

//Designamos nuestro pin de datos
#define PIN_LEDS       D7
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUM_PIXELS     6

//https://www.tweaking4all.com/hardware/arduino/adruino-led-strip-effects/#LEDStripEffectFire


class MyManagerWs2812b {
  public:
    MyManagerWs2812b();
    ~MyManagerWs2812b();
    void start();
    void setBrightness(int newBrightness);
    unsigned int getBrightness() const;
    void changeMode();
    void changeColour();
    void modeColourError();

    volatile bool stopMode = false; //variable usada en interupciones
    volatile bool isChangeColour = false; //variable usada en interupciones
    volatile bool isChangeMode = false; //variable usada en interupciones

    uint32_t red = Adafruit_NeoPixel::Color(255, 0, 0); // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255
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
    void modeStaticColour(uint32_t color);
    void modeTheaterChase(uint32_t color);
    void modeRainbow();
    void modeTheaterChaseRainbow();
    void modeRgbLoop();
    void switchColor(int color, int intensity);

};

#endif
