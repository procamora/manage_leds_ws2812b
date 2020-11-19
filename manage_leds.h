#ifndef _MANAGE_LEDS_H_
#define _MANAGE_LEDS_H_

#define MODO_DEBUG true




#define BUTTON_COLOUR D5    // the number of the pushbutton pin
#define BUTTON_MODE D6    // the number of the pushbutton pin

//Designamos nuestro pin de datos
//#define PIN_LEDS D7

//Designamos cuantos pixeles tenemos en nuestra cinta led RGB
//#define NUMPIXELS     5

#define PIN_BRIGHTNESS A0


//unsigned long counter = 0;
long timeCounter = 0;
const int timeThreshold = 500;



volatile bool is_change_colour = false; //variable usada en interupciones
volatile bool is_change_mode = false; //variable usada en interupciones


#include "manage_ws2812b.h"


#endif
