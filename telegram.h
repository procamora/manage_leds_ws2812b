#ifndef _TELEGRAM_H_
#define _TELEGRAM_H_

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define MODO_DEBUG true
#include "credentials.h"


const unsigned long BOT_MTBS = 1000; // mean time between scan messages

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

//#define TAM_ARRAY 3  // array de string que se le pasa por referencia


//parserCommand(String comando, String arrays[TAM_ARRAY]);
void generateKeyboard(String chat_id, String msg);
void showStart(String chat_id);
void handleNewMessages(int numNewMessages);



/*
  void parserCommand(String comando, String arrays[TAM_ARRAY]) {
  char delimitador = ' ';
  int commaIndex = comando.indexOf(delimitador);
  //  Search for the next comma just after the first
  int secondCommaIndex = comando.indexOf(delimitador, commaIndex + 1);

  arrays[0] = comando.substring(0, commaIndex);
  arrays[1] = comando.substring(commaIndex + 1, secondCommaIndex);
  arrays[2] = comando.substring(secondCommaIndex + 1); //+1 para quitar espacio en blanco

  //cuando solo hay 1 parametro el 2 y 3 contienen el primer parametro, asi los dejo vacios
  if (arrays[1][0] == '/')
    arrays[1] = "";
  if (arrays[2][0] == '/')
    arrays[2] = "";
  }
*/
void generateKeyboard(String chat_id, String msg) {
  String row1 = "[\"/next_colour\", \"/get_colour\"],";
  String row2 = "[\"/next_mode\", \"/get_brg\", \"/get_mode\"],";
  String row3 = "[\"/start\", \"/help\"]";

  String keyboardJson = "[" + row1 + row2 + row3 + "]";
  bot.sendMessageWithReplyKeyboard(chat_id, msg, "HTML", keyboardJson, true, true, false);
}

void showStart(String chat_id) {
  String msg = "Welcome to the bot of @procamora for the management of leds ws2812b\n";
  msg += "/start : Start the bot\n";
  msg += "/next_colour : Change the colour of the leds.\n";
  msg += "/get_colour : You get the color code of the leds.\n";
  msg += "/next_mode : You change the operation mode of the leds.\n";
  msg += "/get_mode : You get the name of the operation code.\n";
  msg += "/get_brg : You get the brightness of the leds.\n";
  msg += "/help : Muestra la ayuda \n";
  msg += "Version 1.0 \n";
  generateKeyboard(chat_id, msg);
}



void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    bot.sendMessage(bot.messages[i].chat_id, bot.messages[i].text, "");

    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;
    if (MODO_DEBUG) {
      Serial.println(chat_id);
      Serial.println(text);
    }

    /*String parse_comandos[TAM_ARRAY]; //array que contrandra comando mas argumentos
      parserCommand(text, parse_comandos);
      if (MODO_DEBUG) {
      Serial.println(parse_comandos[0]);
      Serial.println(parse_comandos[1]);
      Serial.println(parse_comandos[2]);
      }*/

    //MODO ADMINISTRADOR
    if (String(ID_ADMIN) == chat_id) {
      if (text == "/exit")
        generateKeyboard(chat_id, "Accion cancelada"); //mando mensaje + pongo nuevo teclado
      else if (text == "/help")
        showStart(chat_id);

      else if (text == "/start")
        showStart(chat_id);

      else if (text == "/next_colour")
        bot.sendMessage(chat_id, "pendiente next_colour", "");

      else if (text == "/get_colour")
        bot.sendMessage(chat_id, "pendiente get_colour", "");

      else if (text == "/next_mode")
        bot.sendMessage(chat_id, "pendiente next_mode", "");

      else if (text == "/get_mode")
        bot.sendMessage(chat_id, "pendiente get_mode", "");

      else if (text == "/get_brg")
        bot.sendMessage(chat_id, "pendiente get_brg", "");

    } else {
      bot.sendMessage(chat_id, "no tienes permiso para usar este bot", "");
    }
  }
}



#endif
