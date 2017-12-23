#include "keyboard.h"
#include "constants.h"
#include <stdint.h>

const int DELAY_MICROS = 16000;
Ze::Board keyboard;

uint8_t count;

void smart_delay(unsigned long start_time);

void setup() {

    delay(50);
    
    keyboard.init();

    Serial.begin(9600);

    delay(500);

}

void loop() {
    unsigned long start_time = micros();

    keyboard.update();

    smart_delay(start_time);

}

void smart_delay(unsigned long start_time) {
    unsigned long time = micros();

    // overflow has occurred
    if (time < start_time) return;

    unsigned long elapsed = time - start_time;
    if (elapsed > DELAY_MICROS) {
        Serial.print("Computing took more than 16 ms: ");
        Serial.println(elapsed);
        return;
    } else {
        //Serial.println(elapsed);
    }
    delayMicroseconds(DELAY_MICROS - elapsed);
}
