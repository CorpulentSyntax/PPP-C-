#include "mbed.h"

DigitalOut ns_red(D2);
DigitalOut ns_orange(D3);
DigitalOut ns_green(D4);
DigitalOut ew_red(D5);
DigitalOut ew_orange(D6);
DigitalOut ew_green(D7);
DigitalIn button_tons(D8);
DigitalIn button_toew(D9);
Timer wait_20;

enum State {
    STATE_NORTHSOUTH,
    STATE_EASTWEST
} state = STATE_NORTHSOUTH;


void ns_togreen()
{
    wait(1);
    ns_red = !ns_red;
    ns_green = !ns_green;
}

void ns_tored()
{
    ns_green = !ns_green;
    ns_orange = !ns_orange;
    wait(1);
    ns_orange = !ns_orange;
    ns_red = !ns_red;
}

void ew_togreen()
{
    wait(1);
    ew_red = !ew_red;
    ew_green = !ew_green;
}

void ew_tored()
{
    ew_green = !ew_green;
    ew_orange = !ew_orange;
    wait(1);
    ew_orange = !ew_orange;
    ew_red = !ew_red;
}

void wait_while_green()
{
    wait_20.start();
    while (wait_20.read_ms() < 20000) {
        if (button_toew == 0 || button_tons == 0) {
            wait_20.reset();
            while (wait_20.read_ms() < 5000);
            break;
        }
    }
    wait_20.stop();
    wait_20.reset();
}

int main()
{
    ns_red = 1;
    ew_red = 1;

    while(1) {
        switch (state) {
            case STATE_NORTHSOUTH:
                ns_togreen();
                wait_while_green();
                ns_tored();
                state = STATE_EASTWEST;
                break;
            case STATE_EASTWEST:
                ew_togreen();
                wait_while_green();
                ew_tored();
                state = STATE_NORTHSOUTH;
                break;
        }
    }
}
