#ifndef _MANAGE_LEDS_H_
#define _MANAGE_LEDS_H_

#define MODO_DEBUG true


#define BUTTON_COLOUR      D5    // the number of the pushbutton pin
#define BUTTON_MODE        D6    // the number of the pushbutton pin
#define PIN_BRIGHTNESS     A0


//unsigned long counter = 0;
long timeCounter = 0;
const int timeThreshold = 500;

#include "manage_ws2812b.h"


#endif
