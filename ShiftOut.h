#ifndef SHIFT_OUT
#define SHIFT_OUT

#include <Arduino.h>

class ShiftOut {
private:
    int latchPin, dataPin, clockPin;

public:
    ShiftOut(int, int, int);
    void init();
    void send(byte);
};

#endif
