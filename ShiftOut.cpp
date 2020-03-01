#include "ShiftOut.h"

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
