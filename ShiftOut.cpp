#include <Arduino.h>

#define LATCH_PIN 4
#define DATA_PIN 5
#define CLOCK_PIN 6

#define BIT_SEED 128

void setup()
{
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
}

void loop()
{
    for (size_t counter = 0; counter <= 8; counter++) {
        int temp = BIT_SEED >> (8 - counter);

        digitalWrite(LATCH_PIN, LOW);
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, temp); // 13.66uS per bit 73.206Kbps
        digitalWrite(LATCH_PIN, HIGH);
    }
}