#include <Arduino.h>
#include "HT_SSD1306Wire.h"

// Pantalla OLED de la Heltec WiFi LoRa 32 V3
SSD1306Wire display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);

// Encender alimentación externa de la placa
void VextON()
{
    pinMode(Vext, OUTPUT);
    digitalWrite(Vext, LOW);
}

void setup()
{
    Serial.begin(115200);

    // Encender alimentación del OLED
    VextON();
    delay(100);

    // Inicializar OLED
    display.init();

    // Limpiar pantalla
    display.clear();

    // Mostrar texto
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "HELTEC V3");

    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 25, "OLED funcionando!");
    display.drawString(0, 40, "ESP32-S3");

    // Enviar imagen a la pantalla
    display.display();

    Serial.println("OLED funcionando!");
}

void loop()
{
}