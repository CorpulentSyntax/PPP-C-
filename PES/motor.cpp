#include "motor.h"
#include "mbed.h"

Motor::Motor(PinName motor_pwm, PinName frwd, PinName bkwd) : _motor_pwm(motor_pwm), _frwd(frwd), _bkwd(bkwd)
{
    _motor_pwm = 0;
    _frwd = 0;
    _bkwd = 0;
}

void Motor::letsDrive(bool direction, float dutycycle)
{
    if (direction == 0) {
        _frwd = 1;
        _bkwd = 0;
    } else if (direction == 1) {
        _frwd = 0;
        _bkwd = 1;
    }
    _motor_pwm = dutycycle;
}

void Motor::setPeriod(float pwmperiod)
{
    _motor_pwm.period(pwmperiod);
}

void Motor::Stop()
{
    _frwd = 1;
    _bkwd = 1;
    _motor_pwm = 0.001;
}