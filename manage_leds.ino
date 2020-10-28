/**
  @file manage_leds.ino
  @brief Gestion de leds
  @author Pablo Rocamora pablojoserocamora@gmail.com
  @date 14/12/2020
*/

#include "manage_leds.h"


MyArray<uint32_t> array_colours = set_array_colours();


void change_colour() {
  //counter++;
  //Serial.println(String(millis()) + "   " + String(timeCounter + timeThreshold));
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    // Serial.println("exit_bucle");
    //num_colour = true;
    setColour(array_colours.get_actual_value());
    array_colours.next_index();
  }
}

void change_mode() {
  counter++;
  //Serial.println(String(millis()) + "   " + String(timeCounter + timeThreshold));
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    // Serial.println("exit_bucle");
    num_colour = true;
  }
}

/**
   Metodo para establecer el brillo, lee el potenciometro y si ha cambiuado el valor respecto a la lectura anterior actualiza
   el valor y establece el nuevo brillo
*/
void check_pt() {
  int sensorValue = analogRead(PIN_BRIGHTNESS);
  // map it to the range of the analog out:
  int outputValue = map(sensorValue, 0, 1023, 0, 255);

  //int outputValue = map(sensorValue, 0, 1023, 200, 2000);  //Map Potentiometer range to frequency range
  //sensorValue = sensorValue >> 2; //Map Potentiometer range to 8 bit binary range - this is faster and uses less flash
  if (outputValue != brightness) {
    brightness = outputValue;
    strip.setBrightness(brightness); // Set BRIGHTNESS to about (max = 255)
  }
}


void setup() {
  Serial.begin(9600);
  num_colour = false;
  num_mode = false;

  pinMode(BUTTON_COLOUR, INPUT);
  pinMode(BUTTON_MODE, INPUT);

  //https://www.luisllamas.es/que-son-y-como-usar-interrupciones-en-arduino/
  attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), change_colour, FALLING); //
  attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), change_mode, FALLING); //

  // Inicializamos nuestra cinta led RGB
  strip.begin();
  strip.setBrightness(brightness);
  setColour(array_colours.get_actual_value());
}



void loop() {
  if (num_colour) {
    Serial.println(counter);
    counter = 0;
    num_colour = false;
    timeCounter = millis();
  }

  check_pt();
  strip.setBrightness(10);  //FIXME BORRRARs

  staticColour(array_colours.get_actual_value(), 500); // Blue
  array_colours.next_index();

  // Fill along the length of the strip in various colors...
  colorWipe(array_colours.get_actual_value(), 50); // Blue

  array_colours.next_index();

  // Do a theater marquee effect in various colors...
  theaterChase(array_colours.get_actual_value(), 50); // Blue, half brightness

  rainbow(10);             // Flowing rainbow cycle along the whole strip
  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant


  delay(100);
}
