/**
  @file manage_leds.ino
  @brief Gestion de leds
  @author Pablo Rocamora pablojoserocamora@gmail.com (aka procamora)
  @date 14/10/2020
*/

#include "manage_leds.h"


MyArray<uint32_t> array_colours = set_array_colours();


ICACHE_RAM_ATTR void change_colour1() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    is_change_colour = true;
    stop_mode = true;
  }
}

ICACHE_RAM_ATTR void change_mode1() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    is_change_mode = true;
    stop_mode = true;
  }
}

void change_colour() {
  //if (MODO_DEBUG)
  //  Serial.println("change_colour...");
  //counter++;
  //Serial.println(String(millis()) + "   " + String(timeCounter + timeThreshold));

  array_colours.next_index();

  // TODO ES POSIBLE QUE TENGA QUE REDUCIR EL mode_strip ANTES DE LLAMAR A LA FUNCION PARA QUE VUELVA A ENTRAR EN EL MISMO CASE
  //mode_strip = (mode_strip - 1) % 5;
  //if (MODO_DEBUG)
  // Serial.println(mode_strip);
  change_mode_led(false);

}

void change_mode() {
  /*if (MODO_DEBUG)
    Serial.println("change_mode...");*/
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
    if (outputValue < 10) // if set to 0 britgness after imposible on
      outputValue = 5;
    else if (outputValue > 180) // if set to 0 britgness after imposible on
      outputValue = 250;
    brightness = outputValue;
    strip.setBrightness(brightness); // Set BRIGHTNESS to about (max = 255)
    strip.show();
  }
}


void change_mode_led(bool update_mode) {
  if (MODO_DEBUG)
    Serial.println("change_mode_led...");
  if (update_mode)
    mode_strip = (mode_strip + 1) % 5;

  stop_mode = false;

  strip.clear();

  if (MODO_DEBUG)
    Serial.println(mode_strip);
  switch (mode_strip) {
    case 0:
      if (MODO_DEBUG)
        Serial.println("colorWipe...");
      colorWipe(array_colours.get_actual_value());
      break;
    case 1:
      if (MODO_DEBUG)
        Serial.println("theaterChase...");
      theaterChase(array_colours.get_actual_value());
      break;
    case 2:
      if (MODO_DEBUG)
        Serial.println("rainbow...");
      rainbow();
      break;
    case 3:
      if (MODO_DEBUG)
        Serial.println("theaterChaseRainbow...");
      theaterChaseRainbow();
      break;
    case 4:
      if (MODO_DEBUG)
        Serial.println("staticColour...");
      staticColour(array_colours.get_actual_value());
      break;
    default:
      // statements
      break;
  }

}


// cppcheck-suppress unusedFunction
void setup() {
  Serial.begin(115200);
  Serial.println();
  //num_colour = false;
  // num_mode = false;
  Serial.println("start1");

  pinMode(BUTTON_COLOUR, INPUT);
  pinMode(BUTTON_MODE, INPUT);
  pinMode(PIN_BRIGHTNESS, INPUT);

  //https://www.luisllamas.es/que-son-y-como-usar-interrupciones-en-arduino/
  attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), change_colour1, FALLING); //
  attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), change_mode1, FALLING); //


  Serial.println("start2");


  // Inicializamos nuestra cinta led RGB
  strip.begin();

  check_pt();

  staticColour(strip.Color(255, 165, 0));
  Serial.println("start3");
  //cascade(strip.Color(150, 0 , 0));

  Serial.println("start3");

}


// cppcheck-suppress unusedFunction
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

  Serial.println("...");
  delay(500);
}
