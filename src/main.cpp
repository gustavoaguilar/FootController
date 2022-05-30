#include <Arduino.h>
#include <Keyboard.h>
#include "button.h"


void action_reset_recording(void){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('r');
    Keyboard.release('r');
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_SHIFT);

    delay(50);

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('r');
    Keyboard.release('r');
    Keyboard.release(KEY_LEFT_CTRL);
}

void action_pause(void){
    Keyboard.press(' ');
}

tButton b1;
tButton b2;
tButton b3;

void setup() {
    button_init(&b1, 6, 50);
    button_init(&b2, 8, 50);
    button_init(&b3, 9, 50);
    pinMode(b1.pin, INPUT);
    pinMode(b2.pin, INPUT);
    pinMode(b3.pin, INPUT);
    
    pinMode(12, OUTPUT); //LED
    digitalWrite(12, HIGH);

    Keyboard.begin();
    Serial.begin(9600);
}

void loop() {
    button_check(&b1, NULL, &action_reset_recording);
    button_check(&b2, NULL, &action_reset_recording);
    button_check(&b3, NULL, &action_reset_recording);
    // button_check(&b2, &action_pause, NULL);
    delay(10);
}