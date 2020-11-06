#include <Adafruit_NeoPixel.h>


#include "myarray.h"
#include "telegram.h"



#define BUTTON_COLOUR D5    // the number of the pushbutton pin
#define BUTTON_MODE D6    // the number of the pushbutton pin


#define PIN_BRIGHTNESS A0


const int timeThreshold = 500;
unsigned long counter = 0;
long timeCounter = 0;

volatile bool is_change_colour = false; //variable usada en interupciones
volatile bool is_change_mode = false; //variable usada en interupciones
volatile bool stop_mode = false; //variable usada en interupciones

short brightness = 50;

short mode_strip = 0;




//Designamos nuestro pin de datos
#define PIN_LEDS D7

//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
#define NUMPIXELS     5

//Definimos el número de pixeles de la cinta y el pin de datos
//   Parámetro 1 = número de pixeles de la cinta
//   Parámetro 2 = número de pin de datos del Arduino
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN_LEDS, NEO_GRB + NEO_KHZ800);


// FIXME comprobar la diferencia entre 155 y 255 en los colores
MyArray<uint32_t> set_array_colours() {
  MyArray<uint32_t> array_colours(7);

  // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255
  uint32_t red = strip.Color(150, 0, 0);
  array_colours.add(red);

  uint32_t green = strip.Color(0, 150, 0);
  array_colours.add(green);

  uint32_t blue = strip.Color(0, 0, 150);
  array_colours.add(blue);

  uint32_t yellow = strip.Color(150, 150, 0);
  array_colours.add(yellow);

  uint32_t purple = strip.Color(150, 0, 150);
  array_colours.add(purple);

  uint32_t sky_blue = strip.Color(0, 150, 150);
  array_colours.add(sky_blue);

  uint32_t white = strip.Color(150, 150, 150);
  array_colours.add(white);
  return array_colours;
}







// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color) {
  int wait = 50;
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    if (stop_mode) {
      stop_mode = false;
      return;
    }
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color) {
  int wait = 50;
  do {
    for (int a = 0; a < 100; a++) { // Repeat 10 times...
      for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
        strip.clear();         //   Set all pixels in RAM to 0 (off)
        // 'c' counts up from 'b' to end of strip in steps of 3...
        for (int c = b; c < strip.numPixels(); c += 3) {
          if (stop_mode) {
            stop_mode = false;
            return;
          }
          strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
        }
        strip.show(); // Update strip with new contents
        delay(wait);  // Pause for a moment
      }
    }
  } while (true);
}

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow() {
  int wait = 10;
  while (true) {
    // Hue of first pixel runs 5 complete loops through the color wheel.
    // Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
    // means we'll make 5*65536/256 = 1280 passes through this outer loop:
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
      Serial.println("rainbow-----------------");
      for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
        if (stop_mode) {
          stop_mode = false;
          return;
        }
        // Offset pixel hue by an amount to make one full revolution of the
        // color wheel (range of 65536) along the length of the strip
        // (strip.numPixels() steps):
        int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
        // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
        // optionally add saturation and value (brightness) (each 0 to 255).
        // Here we're using just the single-argument hue variant. The result
        // is passed through strip.gamma32() to provide 'truer' colors
        // before assigning to each pixel:
        strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}

// Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
void theaterChaseRainbow() {
  int wait = 50;
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  while (true) {
    //for (int a = 0; a < 30; a++) { // Repeat 30 times...
    for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for (int c = b; c < strip.numPixels(); c += 3) {
        if (stop_mode) {
          stop_mode = false;
          return;
        }
        // hue of pixel 'c' is offset by an amount to make one full
        // revolution of the color wheel (range 65536) along the length
        // of the strip (strip.numPixels() steps):
        int hue = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show();                // Update strip with new contents
      delay(wait);                 // Pause for a moment
      firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
    }
  }
}


void staticColour(uint32_t color) {
  strip.fill(color, 0, strip.numPixels());
  strip.show();                          //  Update strip to match


  /*for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match

    }*/
}


/*
  void cascade(uint32_t color) {
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
      strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      strip.show();                          //  Update strip to match
    }
    strip.clear();
    delay(50);
  }
  }*/
