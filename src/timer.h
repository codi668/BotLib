#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

#define WAIT_ONE_SEC 10000
#define DAC 25 // Trig
#define WHEEL_L 2
#define WHEEL_R A4
#define WHEEL_L_DIRECTION 15
#define WHEEL_R_DIRECTION A5
#define TRUE 1

extern volatile int flag;
extern volatile int expired;
extern volatile int delta_time;

void initTimer();
void IRAM_ATTR service();

#endif // TIMER_H