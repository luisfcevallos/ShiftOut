#include <Arduino.h>
#include <ShiftOut.h>

#define LATCH_PIN 4
#define DATA_PIN 5
#define CLOCK_PIN 6

#define BIT_SEED 128

ShiftOut myRegister(LATCH_PIN, DATA_PIN, CLOCK_PIN);

void setup() {
    myRegister.init();
}

void loop() {
    for (size_t counter = 0; counter <= 8; counter++) {
        int temp = BIT_SEED >> (8 - counter);   // 0, 1, 2, 4, 8, 16, 32, 64, 128
        myRegister.send(temp);
    }
}
