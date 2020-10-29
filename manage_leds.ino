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
    array_colours.next_index();

    // TODO ES POSIBLE QUE TENGA QUE REDUCIR EL mode_strip ANTES DE LLAMAR A LA FUNCION PARA QUE VUELVA A ENTRAR EN EL MISMO CASE
    // mode_strip = (mode_strip - 1) % 5;
    change_mode_led();
  }
}

void change_mode() {
  //counter++;
  //Serial.println(String(millis()) + "   " + String(timeCounter + timeThreshold));
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();

    change_mode_led();
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
    strip.show();
  }
}



void change_mode_led() {
  strip.clear();

  switch (mode_strip) {
    case 0:
      colorWipe(array_colours.get_actual_value());
      break;
    case 1:
      theaterChase(array_colours.get_actual_value());
      break;
    case 2:
      rainbow();
      break;
    case 3:
      theaterChaseRainbow();
      break;
    case 4:
      staticColour(array_colours.get_actual_value());
      break;
    default:
      // statements
      break;
  }
  mode_strip = (mode_strip + 1) % 5;
}



void setup() {
  Serial.begin(9600);
  //num_colour = false;
  // num_mode = false;

  pinMode(BUTTON_COLOUR, INPUT);
  pinMode(BUTTON_MODE, INPUT);

  //https://www.luisllamas.es/que-son-y-como-usar-interrupciones-en-arduino/
  attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), change_colour, FALLING); //
  attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), change_mode, FALLING); //

  // Inicializamos nuestra cinta led RGB
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
  staticColour(strip.Color(0, 150, 150));
}



void loop() {
  if (num_colour) {
    Serial.println(counter);
    counter = 0;
    num_colour = false;
    timeCounter = millis();
  }

  check_pt();

  strip.setBrightness(10);  strip.show();  //FIXME BORRRARs

  change_mode_led();  //FIXME BORRRARs

  array_colours.next_index();  //FIXME BORRRARs

  delay(500);
}
