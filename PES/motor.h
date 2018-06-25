#ifndef _MOTOR_H
#define _MOTOR_H

#include "mbed.h"

class Motor
{
    //attributes

    PwmOut _motor_pwm;
    DigitalOut _frwd;
    DigitalOut _bkwd;


public:
    //methods
    Motor(PinName motor_pwm, PinName frwd, PinName bkwd); //constructor
    void letsDrive(bool direction, float dutycycle); //0 = vooruit, 1 = achteruit
    void setPeriod (float period);
    void Stop();
};

#endif