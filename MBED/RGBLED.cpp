#include "mbed.h"

PwmOut PWM_red(D3); //Sets the correct pins on the Nucleo
PwmOut PWM_green(D5);
PwmOut PWM_blue(D6);

AnalogIn potmeter(A0);

void red() {
    PWM_red = -3.0 * abs(potmeter.read() - (1.0/3.0)) + 1.0; //Formula for the red part of the graph
}

void green() {
    PWM_green = 3.0 * abs(potmeter.read() - (1.0/2.0)) - (1.0/2.0); //Formula for the green part of the graph
}

void blue() {
    PWM_blue = -3.0 * abs(potmeter.read() - (2.0/3.0)) + 1.0; ////Formula for the blue part of the graph
}

int main() {
    PWM_red.period(0.010);
    PWM_green.period(0.010);
    PWM_blue.period(0.010);// set PWM period to 10 ms

    while(1) {
        red(); //Calls the functions above
        green();
        blue();
    }
}
