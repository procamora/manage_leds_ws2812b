# manage_leds_ws2812b



https://arduino.github.io/arduino-cli/latest/getting-started/

```bash
arduino-cli config init

arduino-cli core update-index
arduino-cli core upgrade
arduino-cli core install esp8266:esp8266

arduino-cli lib update-index
arduino-cli lib upgrade
arduino-cli lib install ArduinoJso@5.13.5
arduino-cli lib install UniversalTelegramBot@1.1.0

```


```bash
arduino-cli compile --fqbn esp8266:esp8266:d1_mini manage_leds.ino
arduino-cli upload  --fqbn esp8266:esp8266:d1_mini -p /dev/ttyUSB0 manage_leds.ino
```
