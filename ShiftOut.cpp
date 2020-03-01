#include <Arduino.h>

#define LATCH_PIN 4
#define DATA_PIN 5
#define CLOCK_PIN 6

#define BIT_SEED 128

class ShiftOut {
private:
    int latchPin, dataPin, clockPin;

public:
    ShiftOut(int, int, int);
    void init();
    void send(byte);
};

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

ShiftOut::ShiftOut(int _latchPin, int _dataPin, int _clockPin): latchPin(_latchPin),
    dataPin(_dataPin), clockPin(_clockPin) {}

void ShiftOut::init() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
}

void ShiftOut::send(byte _data) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, _data); // 15.775uS per bit 63.391Kbps
    digitalWrite(latchPin, HIGH);
}
