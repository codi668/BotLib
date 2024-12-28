#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>
#include <FastLED.h>
#include <Wire.h>

// Motor pins:
#define MOTO_R_GESCHW 2
#define MOTO_L_GESCHW 32

// Voreinstellungen
// Voreinstellungen
#define BAUD_RATE 115200
#define BT_NAME "EL-ROBOT-KHH" // Bluetooth-Name des Gerätes
#define FIVE_SEC 50000         // 5 Sekunden in 100µs Schritten
#define ONE_SEC 10000          // 1 Sekunde in 100µs Schritten

// ADC und DAC pins:
#define BATTERIE_ADC 39 // ADC-Pin zur Batteriepegelmessung
#define DAC 25          // DAC-Pin für die PWM-Ausgabe

// LED pins
#define LED_DATA_PIN 23  // LED Data pin
#define LED_CLOCK_PIN 18 // LED Clock pin
#define NUM_LEDS 4       // Anzahl der LEDs

extern float Vref;                    // Referenzspannung 3.3V
extern float V; // Spannungsteiler Verhältnis
extern float ADC_rate;             // Successive-approximation ADC mit 12 Bit

extern float BatteryLevel();

#endif // ROBTO_H