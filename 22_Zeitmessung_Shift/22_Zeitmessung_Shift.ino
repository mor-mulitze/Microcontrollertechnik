/** Zeitmessung: jetzt fangen wir an zu spinnen ... */

/* Durch timer2 gibt es einen overhead, der natürlich selber clockcycles
 * frisst. Evtl könnte man versuchen diesen overhead durch inlinen von
 * timer2.reset() und timer2.get_count() noch weiter zu reduzieren.
 * Aber diesen overhead kann man sowieso herausrechnen indem man die
 * Zeit 8 mal b += a mit der Zeit 16 mal b += a vergleicht!
 *
 * Ergebnisse:
 * Ein b += a braucht:
 * unsigned char:      7/8 * 0.5us -> 7  clockcycle
 * unsigned int:       7/4 * 0.5us -> 14 clockcycle
 * unsigned long:      7/2 * 0.5us -> 28 clockcycle
 * unsigned long long: 9   * 0.5us -> 72 clockcycle
 *
 * 1 clockcycle entspricht 0.0625us
 */

#define MEASURE_START \
  noInterrupts(); \
  TCCR1A = 0; \
  TCCR1B = 1 << CS10; \
  TCNT1 = 0;

/** offset empty loop is 4 cycles with optimization off */
/** offset empty loop is 1 cycles with standard optimization */
#define MEASURE_STOP(c, offset) \
  c = TCNT1; \
  c = c - offset; \
  interrupts();

#define DIVISION(i) \
  { \
    randomSeed(analogRead(0)); \
    register int8_t a = random(30); \
    uint16_t cycles = 0; \
    MEASURE_START \
    a = a / i; \
    MEASURE_STOP(cycles, 1) \
    delay(10); \
    Serial.println(a); \
    Serial.print("Benoetigte Zeit für Division "); \
    Serial.print(i); \
    Serial.print(": "); \
    Serial.println(cycles); \
  }

#define SHIFT(i) \
  { \
    randomSeed(analogRead(0)); \
    register int8_t a = random(30); \
    uint16_t cycles = 0; \
    MEASURE_START \
    a = a >> i; \
    MEASURE_STOP(cycles, 1) \
    delay(10); \
    Serial.println(a); \
    Serial.print("Benoetigte Zeit für Shift "); \
    Serial.print(i); \
    Serial.print(": "); \
    Serial.println(cycles); \
  }

#pragma GCC push_options
#pragma GCC optimize ("-O0")

void setup()
{
  Serial.begin(9600);
  DIVISION(1);
  DIVISION(2);
  DIVISION(3);
  DIVISION(4);
  DIVISION(5);
  DIVISION(6);
  DIVISION(7);
  DIVISION(8);
  DIVISION(9);
  DIVISION(10);
  DIVISION(11);
  DIVISION(12);
  DIVISION(13);
  DIVISION(14);
  DIVISION(15);
  DIVISION(16);
  DIVISION(17);
  DIVISION(18);
  DIVISION(19);
  DIVISION(20);
  SHIFT(1);
  SHIFT(2);
  SHIFT(3);
  SHIFT(4);
  SHIFT(5);

}


void loop() {
}

#pragma GCC pop_options
