/**
 *  TCA9548A library
 *
 *  @author Akash Vibhute
 *  @author < akash . roboticist [at] gmail . com >
 *  @version 0.1
 *  @date May/24/2016
 */
 
#include "tca9548a.h"
 
TCA9548A::TCA9548A( PinName sda, PinName scl, uint8_t i2c_address, PinName resetPin, uint32_t hz ) : i2c_(sda, scl), reset_pin(resetPin)
{
    i2c_addr = i2c_address;
    i2c_.frequency(hz);
}

 
void TCA9548A::select( uint8_t channel )
{
    char data; //create temporary char buffer
    
    if(channel >= 8) return;
    
    data = 1 << channel;
    i2c_.write( i2c_addr << 1, &data, 1);
}
 
void TCA9548A::reset( )
{
    reset_pin = 0;
    wait_ms(1);
    reset_pin = 1;
}
 