/**
  @file manage_leds.ino
  @brief Gestion de leds
  @author Pablo Rocamora pablojoserocamora@gmail.com (aka procamora)
  @date 14/10/2020
*/

#include "manage_leds.h"


MyManagerWs2812b ws2812b;


ICACHE_RAM_ATTR void changeColour() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    ws2812b.isChangeColour = true;
    ws2812b.stopMode = true;
  }
}

ICACHE_RAM_ATTR void changeModel() {
  if (millis() > timeCounter + timeThreshold) {
    timeCounter = millis();
    ws2812b.isChangeMode = true;
    ws2812b.stopMode = true;
  }
}


/**
   Metodo para establecer el brillo, lee el potenciometro y si ha cambiuado el valor respecto a la lectura anterior actualiza
   el valor y establece el nuevo brillo
*/
void check_pt() {
  int sensorValue = analogRead(PIN_BRIGHTNESS);
  // map it to the range of the analog out:
  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255);
  //Serial.println(outputValue);

  int invert = 255 - outputValue;
  //Serial.println(invert);
  if (invert != ws2812b.getBrightness()) {
    if (invert < 15) // if set to 0 britgness after imposible on
      invert = 10;
    else if (invert > 180) // if set to 0 britgness after imposible on
      invert = 250;
    ws2812b.setBrightness(invert);
  }
}


// cppcheck-suppress unusedFunction
void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(BUTTON_COLOUR, INPUT);
  pinMode(BUTTON_MODE, INPUT);
  pinMode(PIN_BRIGHTNESS, INPUT);

  //https://www.luisllamas.es/que-son-y-como-usar-interrupciones-en-arduino/
  attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), changeColour, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), changeModel, FALLING);

  ws2812b.start();

  ws2812b.modeColourError();
  delay(500);
}


// cppcheck-suppress unusedFunction
void loop() {
  Serial.println(ws2812b.getBrightness());
  check_pt();

  if (ws2812b.isChangeColour) {
    ws2812b.isChangeColour = false;
    ws2812b.changeColour();
  }

  if (ws2812b.isChangeMode) {
    ws2812b.isChangeMode = false;
    ws2812b.changeMode();
  }
  delay(50);
}
