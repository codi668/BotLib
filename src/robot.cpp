#include <robot.h>
#include <timer.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>
#include <FastLED.h>
#include <Wire.h>

BluetoothSerial SerialBT; // Create an instance of BluetoothSerial


float Vref = 3.3;                    // Referenzspannung 3.3V
float V = (100000 + 47000) / 100000; // Spannungsteiler Verhältnis
float ADC_rate = 4095.0;             // Successive-approximation ADC mit 12 Bit

float BatteryLevel()
{
    float average = 0;
    for (int i = 0; i < 10; i++)
    {
        int sensorValue = analogRead(BATTERIE_ADC);
        float voltage = sensorValue * (Vref / ADC_rate);
        float actualVoltage = voltage * V;
        average += actualVoltage;
    }
    return average / 10; // Durchschnitt
}

void setupBot()
{
    Serial.begin(BAUD_RATE);      // Serielle Schnittstelle initialisieren
    SerialBT.begin(BT_NAME);      // Bluetooth Schnittstelle initialisieren
    pinMode(BATTERIE_ADC, INPUT); // Batterie Spannungsmessung initialisieren
    pinMode(MOTO_R_GESCHW, OUTPUT);
    pinMode(MOTO_L_GESCHW, OUTPUT);
    pinMode(DAC, OUTPUT);

    // LEDs initialisieren
    // FastLED.addLeds<SK9822, LED_DATA_PIN, LED_CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.setBrightness(255); // Maximale Helligkeit
    // FastLED.clear();            // Alle LEDs ausschalten
    // FastLED.show();

    initTimer(); // Timer initialisieren

    Serial.println("System bereit."); // Debug-Ausgabe
}