/**
 * Dieses Miniprogramm ist als weitere Prüfungsaufgabe in der CMT-Kurzarbeit gedacht
 * Dieses Programm sendet drei 5V Spannungspulse auf das Digitale Pin 3 des Arduinos
 * 1. Stelle den Signalverlauf der drei Pulse am Oszilloskop dar möglichst übersichtlich dar.
 * 2. Messen Sie die Periodendauer eines Pulses und geben Sie die daraus resultierende Frequenz an.
 * 3. Bestimmen Sie die Zeit, die der Arduino für den Übergang von 0V auf 5V benötigt. (Screenshot)
 * 4. Was ist das maximale Rauschen (Spannungsdifferenz) im Pegelzustand HIGH, bzw das Rauschen im Pegelzusand LOW.
 */

#include <Arduino.h>

void setup() {
  DDRD = 0xFF;
}


void loop() {
  PORTD |= (1 << PD3);
  delay(500);
  PORTD &= ~(1 << PD3);
  delay(500);
}
