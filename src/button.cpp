#include "button.h"

void button_init(tButton* button, int pin, int debounce){
    button->pin = pin;
    button->debounce = debounce;
    button->active = false;
    button->state = 0;
}

void button_check(tButton* b, void (*press)(), void (*release)()){
    b->state = digitalRead(b->pin);
    
    if(b->state){
        if(!b->active){
            b->active = true;
            delay(b->debounce);
            press();
        }
    }else{
        if(b->active){
            b->active = false;
            delay(b->debounce);
            release();
        }
    }
}
