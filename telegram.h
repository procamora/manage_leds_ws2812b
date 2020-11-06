
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include "TelegramCertificate.h" // es necesario porque uso la version 1.0 que aun no lo tiene
#include <UniversalTelegramBot.h>


#include "credentials.h"

#define MODO_DEBUG true

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
const unsigned long BOT_MTBS = 1000; // mean time between scan messages
unsigned long bot_lasttime;          // last time messages' scan has been done


#define TAM_ARRAY 3  // array de string que se le pasa por referencia


void parseaComando(String comando, String arrays[TAM_ARRAY]) {
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

void genera_teclado(String chat_id, String msg) {
  String fila1 = "[\"/set_rele\", \"/get_rele\", \"/get_temp\"],";
  String fila2 = "[\"/set_timer\", \"/get_timer\", \"/modo_automatico\"],";
  String fila3 = "[\"/start\", \"/help\"]";

  String keyboardJson = "[" + fila1 + fila2 + fila3 + "]";
  bot.sendMessageWithReplyKeyboard(chat_id, msg, "HTML", keyboardJson, true, true, false);
}

void show_start(String chat_id) {
  String msg = "Bienvenido al BOT de Pablo para la gestion de temperatura\n";
  msg += "/start : Inicia la conversacion \n";
  msg += "/get_temp : Obtienes la temperatua actual \n";
  msg += "/get_rele : Obtienes el estado actual del rele \n";
  msg += "/set_rele : Activa / Desactiva el rele \n";
  msg += "/get_timer : Obtienes el tiempo restante para que se active el temporizador \n";
  msg += "/set_timer : Activas el temporizador para una accion en x tiempo \n";
  msg += "/modo_automatico : Activas el modo automatico \n";
  msg += "/help : Muestra la ayuda \n";
  msg += "Version 1.0 \n";
  genera_teclado(chat_id, msg);
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

    String parse_comandos[TAM_ARRAY]; //array que contrandra comando mas argumentos
    parseaComando(text, parse_comandos);
    if (MODO_DEBUG) {
      Serial.println(parse_comandos[0]);
      Serial.println(parse_comandos[1]);
      Serial.println(parse_comandos[2]);
    }

    //MODO ADMINISTRADOR
    if (String(ID_TELEGRAM) == chat_id) {
      if (parse_comandos[0] == "/exit")
        genera_teclado(chat_id, "Accion cancelada"); //mando mensaje + pongo nuevo teclado
      else if (parse_comandos[0] == "/help")
        show_start(chat_id);
      else if (parse_comandos[0] == "/start")
        show_start(chat_id);
    } else {
      bot.sendMessage(chat_id, "no tienes permiso para usar este bot", "");
    }
  }
}
