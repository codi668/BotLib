/*************************************************************************************************
 *
 * main.cpp
 *
 * Es muss ein Timer initialisiert werden, der periodisch Interrupts auslöst.
 * Er wird initialisiert, indem die Funktion `initTimer()` aufgerufen wird.
 * DIES IST UNBEDINGT NOTWENDIG, DA SONST DAS PROGRAMM NICHT FUNKTIONIERT.
 *
 * Dieses Programm initialisiert einen Timer, der periodisch Interrupts auslöst.
 * Die Variable `delta_time` wird verwendet, um die Dauer zu bestimmen, nach der
 * eine bestimmte Aktion ausgeführt wird. Der Timer-Interrupt setzt das Flag `flag`
 * auf `true`, wenn der Schwellenwert erreicht ist.
 *
 * Verwendung:
 * - `delta_time` gibt die Anzahl der Timer-Interrupts an, nach denen eine Aktion
 *   ausgeführt werden soll. Zum Beispiel bedeutet `delta_time = 10000`, dass die
 *   Aktion nach 10000 Timer-Interrupts ausgeführt wird.
 * - Im `loop()`-Abschnitt des Programms wird geprüft, ob `flag` auf `true` gesetzt
 *   wurde. Wenn ja, wird die entsprechende Aktion ausgeführt und `flag` wird
 *   zurückgesetzt.
 *
 * Beispiel:
 * - Setzen Sie `delta_time` auf 10000, um eine Aktion nach 10000 Timer-Interrupts
 *   auszuführen.
 *
 *************************************************************************************************/
#include "timer.h"

void setup()
{
  initTimer(); // Timer initialisieren
  Serial.begin(115200);
  delta_time = 1000; // Beispielwert, kann angepasst werden
}

void loop()
{
  delta_time = 10000; // Beispielwert, kann angepasst werden

  // Im Loop passiert nichts, da alle Aktionen im Interrupt durchgeführt werden
  if (expired)
  {
    // Wenn der Schwellenwert erreicht ist
    Serial.println("Aktion ausgeführt");
    expired = false; // Flag zurücksetzen, damit die Aktion nur einmal ausgeführt wird
  }
}