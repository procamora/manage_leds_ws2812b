
#include "manage_ws2812b.h"


void delay(int pause) {

}

MyManagerWs2812b::MyManagerWs2812b() {
  //Definimos el número de pixeles de la cinta y el pin de datos
  //   Parámetro 1 = número de pixeles de la cinta
  //   Parámetro 2 = número de pin de datos del Arduino
  strip = Adafruit_NeoPixel(NUM_PIXELS, PIN_LEDS, NEO_GRB + NEO_KHZ800);

  MyManagerWs2812b::insertArrayColours();
}

MyManagerWs2812b::~MyManagerWs2812b() {
  strip.clear();
}

void MyManagerWs2812b::start() {
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
  staticColour(sky_blue);

}

void MyManagerWs2812b::updateBrightness(int newBrightness) {
  brightness = newBrightness;
  strip.setBrightness(newBrightness);
  strip.show();
}

unsigned int MyManagerWs2812b::getBrightness() const {
  return brightness;
}

void MyManagerWs2812b::changeColour() {
  arrayColours.next_index();
  changeModeLed(false);
}

void MyManagerWs2812b::changeMode() {
  changeModeLed(true);
}


void MyManagerWs2812b::changeModeLed(bool isChangeMode) {
  Serial.println("changeModeLed...");
  if (isChangeMode)
    modeStrip = (modeStrip + 1) % 5;

  stopMode = false;

  strip.clear();

  //if (MODO_DEBUG)
  //    Serial.println(mode_strip);
  switch (modeStrip) {
    case 0:

      colorWipe(arrayColours.get_actual_value());
      break;

    case 1:
      theaterChase(arrayColours.get_actual_value());
      break;

    case 2:
      rainbow();
      break;

    case 3:
      theaterChaseRainbow();
      break;

    case 4:
      staticColour(arrayColours.get_actual_value());
      break;

    default:
      // statements
      break;
  }
}


void MyManagerWs2812b::insertArrayColours() {
  arrayColours.add(green);
  arrayColours.add(red);
  arrayColours.add(blue);
  arrayColours.add(yellow);
  arrayColours.add(purple);
  arrayColours.add(sky_blue);
  arrayColours.add(white);
}







// Some functions of our own for creating animated effects -----------------

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void MyManagerWs2812b::colorWipe(uint32_t color) {
  int wait = 50;
  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    if (stopMode) {
      stopMode = false;
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
void MyManagerWs2812b::theaterChase(uint32_t color) {
  int wait = 50;
  do {
    for (int a = 0; a < 100; a++) { // Repeat 10 times...
      for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
        strip.clear();         //   Set all pixels in RAM to 0 (off)
        // 'c' counts up from 'b' to end of strip in steps of 3...
        for (int c = b; c < strip.numPixels(); c += 3) {
          if (stopMode) {
            stopMode = false;
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
void MyManagerWs2812b::rainbow() {
  int wait = 10;
  while (true) {
    // Hue of first pixel runs 5 complete loops through the color wheel.
    // Color wheel has a range of 65536 but it's OK if we roll over, so
    // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
    // means we'll make 5*65536/256 = 1280 passes through this outer loop:
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
      for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
        if (stopMode) {
          stopMode = false;
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
void MyManagerWs2812b::theaterChaseRainbow() {
  int wait = 50;
  int firstPixelHue = 0;     // First pixel starts at red (hue 0)
  while (true) {
    //for (int a = 0; a < 30; a++) { // Repeat 30 times...
    for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in increments of 3...
      for (int c = b; c < strip.numPixels(); c += 3) {
        if (stopMode) {
          stopMode = false;
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


void MyManagerWs2812b::staticColour(uint32_t color) {
  strip.fill(color, 0, strip.numPixels());
  strip.show();                          //  Update strip to match


  /*for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match

    }*/
}

/*
  void cascade(uint32_t color) {
    while (true) {
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
                if (stopMode) {
                    stopMode = false;
                    return;
                }
                strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
                strip.show();                          //  Update strip to match
            }
            strip.clear();
            delay(50);
        }
    }
  }*/
