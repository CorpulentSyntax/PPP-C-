#include "mbed.h"
#include "HCSR04.h"
#include "VCNL4010.h"
#include "tca9548a.h"
#include "motor.h"

#define Grijs
#ifdef Wit
int cliff_threshold = 3300;
#endif
#ifdef Grijs
int cliff_threshold = 2900;
#endif

HCSR04 ussensor_left(A2, A3); //echo, trigger
HCSR04 ussensor_right(A4, A5);
TCA9548A i2c_sw(I2C_SDA, I2C_SCL);
Motor motor_left(D5, D3, D4); //pwm, frwd, bkwd
Motor motor_right(D6, D7, D8);
DigitalIn switchbutton(D11);
DigitalOut led(LED1);
Serial pc(USBTX, USBRX);
Timer timer;

enum State {
    STATE_DRIVING,
    STATE_TURNING,
    STATE_CLIFF
} state = STATE_DRIVING;

double sampleTime = 0.5;
double cliff_left = 0.0;
double cliff_right = 0.0;
double object_ir = 0.0;
unsigned int prox_cliff_left = 0;
unsigned int prox_cliff_right = 0;
unsigned int prox_object_ir = 0;
bool lifted = false;
int switchstate = 0;

int main()
{
    motor_left.setPeriod(0.001);
    motor_right.setPeriod(0.001);
    ussensor_left.setRanges(2, 400);
    ussensor_right.setRanges(2, 400);

    i2c_sw.select(1);
    VCNL40x0 cliff_left(I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);
    i2c_sw.select(2);
    VCNL40x0 cliff_right(I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);
    i2c_sw.select(0);
    VCNL40x0 object_ir(I2C_SDA, I2C_SCL, VCNL40x0_ADDRESS);

    while(1) {
        switchstate = switchbutton;
        if (switchstate == 1) {
            led = 1;
            switch (state) {
                case STATE_DRIVING: {
                    motor_left.Stop();
                    motor_right.Stop();
                    i2c_sw.select(1);
                    cliff_left.ReadProxiOnDemand(&prox_cliff_left);
                    i2c_sw.select(2);
                    cliff_right.ReadProxiOnDemand(&prox_cliff_right);
                    i2c_sw.select(0);
                    object_ir.ReadProxiOnDemand(&prox_object_ir);
                    if (prox_cliff_left < cliff_threshold || prox_cliff_right < cliff_threshold) {
                        state = STATE_CLIFF;
                        break;
                    }
                    if (switchstate == 0) break;
                    if (prox_object_ir > 3000) {
                        state = STATE_TURNING;
                        break;
                    }
                    lifted = false;
                    timer.reset();
                    timer.start();

                    ussensor_left.startMeasurement();
                    ussensor_right.startMeasurement();
                    if (switchstate == 0) break;
                    while(!ussensor_left.isNewDataReady() && !ussensor_right.isNewDataReady()) {
                        // wait for new data
                        // waiting time depends on the distance
                        if (switchstate == 0) break;
                    }

                    if (ussensor_left.getDistance_cm() <= 13 || ussensor_right.getDistance_cm() <= 13) {
                        state = STATE_TURNING;
                        break;
                    }
                    timer.stop();

                    motor_left.letsDrive(0, 0.3); //0 = frwd 1 = bkwd, pwm dutycycle
                    motor_right.letsDrive(0, 0.275);
                    wait_ms(500 - timer.read_ms());
                    break;
                }

                case STATE_TURNING:
                    motor_right.Stop();
                    motor_left.letsDrive(1, 0.5);
                    for (int i = 0; i < 6; i++) {
                        if (switchstate == 0) break;
                        wait(0.25);
                    }
                    motor_left.Stop();
                    wait(0.1);
                    state = STATE_DRIVING;
                    lifted = false;
                    break;

                case STATE_CLIFF:
                    if (lifted == true) {
                        motor_left.Stop();
                        motor_right.Stop();
                        wait(2);
                    }
                    if (switchstate == 0) break;
                    if (lifted == false) {
                        motor_left.letsDrive(1, 0.5);
                        motor_right.letsDrive(1, 0.1);
                        lifted = true;
                        wait(2);
                    }
                    state = STATE_DRIVING;
                    break;
            }

            if (switchstate == 0) {
                lifted = false;
                motor_left.Stop();
                motor_right.Stop();
                state = STATE_DRIVING;
                led = 0;
                wait(1);
            }
            wait(0.1);
        }
    }
