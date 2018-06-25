#include "mbed.h"
#include "HCSR04.h"
#include "VCNL4010.h"
#include "tca9548a.h"

Serial pc(USBTX, USBRX);
Timer timer;
TCA9548A i2c_sw(I2C_SDA, I2C_SCL);

DigitalOut left_frwd(D2);
DigitalOut left_bkwd(D4);
DigitalOut right_frwd(D7);
DigitalOut right_bkwd(D8);
PwmOut motor_left(D5);
PwmOut motor_right(D6);

void both_forwards()
{
    left_frwd = 1;
    left_bkwd = 0;
    right_frwd = 1;
    right_bkwd = 0;
}

void both_backwards()
{
    left_frwd = 0;
    left_bkwd = 1;
    right_frwd = 0;
    right_bkwd = 1;
}

void left_backwards()
{
    left_frwd = 0;
    left_bkwd = 1;
    right_frwd = 0;
    right_bkwd = 0;
}

void right_backwards()
{
    left_frwd = 0;
    left_bkwd = 0;
    right_frwd = 0;
    right_bkwd = 1;
}

void both_stop()
{
    left_frwd = 0;
    left_bkwd = 0;
    right_frwd = 0;
    right_bkwd = 0;
}

void left_forwards()
{
    left_frwd = 1;
    left_bkwd = 0;
    right_frwd = 0;
    right_bkwd = 0;
}

int main()
{
    motor_left.period(0.01);
    motor_right.period(0.01);
    motor_left = 0.6;
    motor_right = 0.6;
    unsigned int  ProxiValue=0;
    //unsigned int  ProxiValue1=0;
    //unsigned int  ProxiValue2=0;
    i2c_sw.select(0);
    VCNL40x0 object (I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);
    //i2c_sw.select(1);
    //VCNL40x0 cliff_1 (I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);
    //i2c_sw.select(2);
    //VCNL40x0 cliff_2 (I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);
    while(1) {
        // i2c_sw.select(1);
        //cliff_1.ReadProxiOnDemand(&ProxiValue1);      // read ambi value on demand
        //pc.printf("Proximity value 1: %5.0i cts\r\n", ProxiValue1);
        //i2c_sw.select(2);
        ///wait(0.01);
        //cliff_2.ReadProxiOnDemand(&ProxiValue2);
        //wait(0.01);    // read ambi value on demand
        //pc.printf("Proximity value 2: %5.0i cts\r\n", ProxiValue2);
        i2c_sw.select(0);
        wait(0.01);
        object.ReadProxiOnDemand(&ProxiValue);      // read ambi value on demand
        //pc.printf("Proximity value object %5.0i cts\r\n", ProxiValue);
        wait(0.01);
        if (ProxiValue > 1815) {
            left_backwards();
            wait(1);
            both_forwards();
            wait(0.5);
            left_forwards();
            wait(1);
        }
        /* } else if (ProxiValue1 < 2800) {
             both_stop();
             wait(1.2);
         } else if (ProxiValue2 < 2800) {
             both_stop();
             wait(1.2);*/
        else  both_forwards();
        wait(0.01);
    }
}
