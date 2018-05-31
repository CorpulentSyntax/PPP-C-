#include "mbed.h"

AnalogIn irsensor(A0);
Serial serial(USBTX, USBRX);
PwmOut dimmer(D3);
InterruptIn button(USER_BUTTON);
Timer debounce;
DigitalOut led(A5);
Ticker sample;

enum State {
    STATE_RUNNING,
    STATE_FROZEN,
} state = STATE_RUNNING;

double distance = 0.0;

void calc_distance()
{
    double voltage = irsensor.read();
    distance = 2.95 * pow(voltage,-1.16);
    if (distance < 4.0) distance = 4.0;
    if (distance > 30.0) distance = 30.0;
}

void toggle()
{
    if (debounce.read_ms() > 200) {
        if (state == STATE_FROZEN) state = STATE_RUNNING;
        else if (state == STATE_RUNNING) state = STATE_FROZEN;
        led!=led;
        debounce.reset();
    }
}

int main()
{
    dimmer.period(0.001);
    serial.baud(9600);
    sample.attach(&calc_distance, 0.01);

    debounce.start();
    button.rise(&toggle);
    while(1) {
        switch (state) {
            case STATE_RUNNING:
                serial.printf("Distance: %.0f\r\n", distance);
                dimmer = 0.04 * distance - 0.15;
                wait(0.01);
                break;

            case STATE_FROZEN:
                break;
        }
    }
}
