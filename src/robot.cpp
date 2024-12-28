#include <robot.h>

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