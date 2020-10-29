/**
  @file manage_leds.ino
  @brief Gestion de leds
  @author Pablo Rocamora pablojoserocamora@gmail.com
  @date 14/12/2020
*/

#include "manage_leds.h"


MyArray<uint32_t> array_colours = set_array_colours();


void change_colour1() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    is_change_colour = true;
    stop_mode = true;
  }
}

void change_mode1() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    is_change_mode = true;
    stop_mode = true;
  }
}

void change_colour() {
  Serial.println("change_colour...");
  //counter++;
  //Serial.println(String(millis()) + "   " + String(timeCounter + timeThreshold));

  array_colours.next_index();

  // TODO ES POSIBLE QUE TENGA QUE REDUCIR EL mode_strip ANTES DE LLAMAR A LA FUNCION PARA QUE VUELVA A ENTRAR EN EL MISMO CASE
  //mode_strip = (mode_strip - 1) % 5;
  Serial.println(mode_strip);
  change_mode_led(false);

}

void change_mode() {
  Serial.println("change_mode...");
  change_mode_led(true);
}


/**
   Metodo para establecer el brillo, lee el potenciometro y si ha cambiuado el valor respecto a la lectura anterior actualiza
   el valor y establece el nuevo brillo
*/
void check_pt() {
  int sensorValue = analogRead(PIN_BRIGHTNESS);
  // map it to the range of the analog out:
  int outputValue = map(sensorValue, 0, 1023, 0, 255);
  //Serial.println(outputValue);

  //int outputValue = map(sensorValue, 0, 1023, 200, 2000);  //Map Potentiometer range to frequency range
  //sensorValue = sensorValue >> 2; //Map Potentiometer range to 8 bit binary range - this is faster and uses less flash
  if (outputValue != brightness) {
    if ( outputValue < 20) // if set to 0 britgness after imposible on
      outputValue = 20;
    brightness = outputValue;
    strip.setBrightness(brightness); // Set BRIGHTNESS to about (max = 255)
    strip.show();
  }
}



void change_mode_led(bool update_mode) {

  Serial.println("change_mode_led...");
  if (update_mode)
    mode_strip = (mode_strip + 1) % 5;

  stop_mode = false;

  strip.clear();

  Serial.println(mode_strip);
  switch (mode_strip) {
    case 0:
      Serial.println("colorWipe...");
      colorWipe(array_colours.get_actual_value());
      break;
    case 1:
      Serial.println("theaterChase...");
      theaterChase(array_colours.get_actual_value());
      break;
    case 2:
      Serial.println("rainbow...");
      rainbow();
      break;
    case 3:
      Serial.println("theaterChaseRainbow...");
      theaterChaseRainbow();
      break;
    case 4:
      Serial.println("staticColour...");
      staticColour(array_colours.get_actual_value());
      break;
    default:
      // statements
      break;
  }

}



void setup() {
  Serial.begin(9600);
  //num_colour = false;
  // num_mode = false;
  Serial.println("start");

  pinMode(BUTTON_COLOUR, INPUT);
  pinMode(BUTTON_MODE, INPUT);
  pinMode(PIN_BRIGHTNESS, INPUT);

  //https://www.luisllamas.es/que-son-y-como-usar-interrupciones-en-arduino/
  attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), change_colour1, FALLING); //
  attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), change_mode1, FALLING); //

  Serial.println("start2");

  // Inicializamos nuestra cinta led RGB
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
  staticColour(array_colours.get_actual_value());
  Serial.println("start3");
  //cascade(strip.Color(150, 0 , 0));
}



void loop() {
  check_pt();

  if (is_change_colour) {
    is_change_colour = false;
    change_colour();
  }

  if (is_change_mode) {
    is_change_mode = false;
    change_mode();
  }

  //strip.setBrightness(10);  strip.show();  //FIXME BORRRARs

  //change_mode_led();  //FIXME BORRRARs
  //change_colour();

  //array_colours.next_index();  //FIXME BORRRARs
  //Serial.println("...");
  delay(50);
}
