#ifndef BUTTON_H
#define BUTTON_H

#include<Arduino.h>

typedef struct{
    bool active;
    uint8_t state;
    uint8_t debounce;
    int pin;
}tButton;

void button_init(tButton* button, int pin, int debounce);
void button_check(tButton* b, void (*press)(), void (*release)());

#endif