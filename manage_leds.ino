/**
  @file manage_leds.ino
  @brief Gestion de leds
  @author Pablo Rocamora pablojoserocamora@gmail.com (aka procamora)
  @date 14/10/2020
*/

#include "manage_leds.h"

MyManagerWs2812b ws2812b = MyManagerWs2812b();


ICACHE_RAM_ATTR void change_colour1() {
    if (millis() > timeCounter + timeThreshold) {
        timeCounter = millis();
        is_change_colour = true;
        ws2812b.stopMode = true;
    }
}

ICACHE_RAM_ATTR void change_mode1() {
    if (millis() > timeCounter + timeThreshold) {
        timeCounter = millis();
        is_change_mode = true;
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

    //int outputValue = map(sensorValue, 0, 1023, 200, 2000);  //Map Potentiometer range to frequency range
    //sensorValue = sensorValue >> 2; //Map Potentiometer range to 8 bit binary range - this is faster and uses less flash
    if (outputValue != ws2812b.getBrightness()) {
        if (outputValue < 10) // if set to 0 britgness after imposible on
            outputValue = 5;
        else if (outputValue > 180) // if set to 0 britgness after imposible on
            outputValue = 250;
        ws2812b.updateBrightness(outputValue);
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
    //attachInterrupt(digitalPinToInterrupt(BUTTON_COLOUR), change_colour1, FALLING); //
    //attachInterrupt(digitalPinToInterrupt(BUTTON_MODE), change_mode1, FALLING); //

    Serial.println("start2");
    ws2812b.start();
    Serial.println("start3");
}


// cppcheck-suppress unusedFunction
void loop() {

  delay(500);
  ws2812b.getBrightness();
    /*check_pt();

    if (is_change_colour) {
        is_change_colour = false;
        ws2812b.changeColour();
    }

    if (is_change_mode) {
        is_change_mode = false;
        ws2812b.changeMode();
    }*/

    Serial.println("...");
    delay(500);
}
