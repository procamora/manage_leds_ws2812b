

#include "myarray.h"
#include "ws2812b.h"



#define BUTTON_COLOUR 2    // the number of the pushbutton pin
#define BUTTON_MODE 3    // the number of the pushbutton pin


#define PIN_BRIGHTNESS A0


const int timeThreshold = 1000;
unsigned long counter = 0;
long timeCounter = 0;

volatile bool num_colour = false; //variable usada en interupciones
volatile bool num_mode = false; //variable usada en interupciones

short brightness = 50;
