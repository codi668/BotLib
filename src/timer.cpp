#include "timer.h"

volatile int flag;
volatile int expired;
volatile int delta_time;

void initTimer()
{
    // Timer initialisieren
    hw_timer_t *timer = timerBegin(0, 80, true); // 80 = Prescaler
    // timerAttachInterrupt(timer, &myTimer, true);
    timerAttachInterrupt(timer, &service, true);
    timerAlarmWrite(timer, 100, true); // Timer läuft alle 0.01 ms
    timerAlarmEnable(timer);
}

void IRAM_ATTR service() // Periodische Timer-Interrupt, der alle 0.1 msec abläuft
{
    static int32_t myTimerCount = 0;
    static int32_t expiredCount = 0;

    myTimerCount++;
    expiredCount++;

    int threshold = 10000;         // Beispielwert, kann angepasst werden
    if (myTimerCount >= threshold) // Wenn der Schwellenwert erreicht ist
    {
        flag = true; // Flag wird gesetzt
        myTimerCount = 0;
    }

    if (expiredCount >= delta_time) // Wenn der Schwellenwert erreicht ist
    {
        expired = true; // Flag wird gesetzt
        expiredCount = 0;
    }
}