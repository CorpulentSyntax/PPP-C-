/** TCA9548A library
 *
 * @author Akash Vibhute
 * @author < akash . roboticist [at] gmail . com >
 * @version 0.1
 * @date May/24/2016
 *
 * @section LICENSE
 *
 * Copyright (c) 2015 Akash Vibhute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *
 */
 
#ifndef TCA9548A_H
#define TCA9548A_H
 
#include "mbed.h"
 
/** TCA9548A class
 *
 *  @section DESCRIPTION
 *  TCA9548A: Low-Voltage 8-Channel I2C Switch With Reset
 *  The TCA9548A device has eight bidirectional translating switches that can be 
 *  controlled through the I2C bus. The SCL/SDA upstream pair fans out to eight 
 *  downstream pairs, or channels. Any individual SCn/SDn channel or combination 
 *  of channels can be selected, determined by the contents of the programmable
 *  control register.
 *
 *  The TCA9548A has a user 8 selectable address in the range 0x70 thru 0x77 (7-bit),
 *  based on the configuration of Addr pins (A0, A1, A2). Default address is 0x70 for
 *  A0:A2 pull down.
 *
 *  Datasheet for TCA9548A can be found at:
 *  http://www.ti.com/lit/ds/symlink/tca9548a.pdf
 *
 *  Example:
 *  @code
 *  #include "mbed.h"
 *  #include "LM75B.h"
 *  #include "TCA9548A.h"
 *  
 *  TCA9548A i2c_sw(I2C_SDA, I2C_SCL); //default address 0x70 applied
 *  
 *  int main()
 *  {
 *      // By default TCA9548A performs a power on reset and all downstream ports are deselected
 *      
 *      i2c_sw.select(0);               //  select  the channel 0
 *      LM75B tmp0(I2C_SDA, I2C_SCL);   //  making instance after a branch of I2C bus (which is connecting the LM75B) enabled
 *  
 *      i2c_sw.select(1);               //  select  the channel 1
 *      LM75B tmp1(I2C_SDA, I2C_SCL);   //  making instance after a branch of I2C bus (which is connecting the LM75B) enabled
 *  
 *      while(1) {
 *          
 *          i2c_sw.select(0);           //  select  the channel 0
 *          printf( "%.3f\r\n", tmp0.read() );
 *  
 *          i2c_sw.select(1);           //  select  the channel 1
 *          printf( "%.3f\r\n", tmp1.read() );
 *  
 *          wait( 1.0 );
 *      }
 *  }
 *  @endcode
 */
 
class TCA9548A
{
public:
 
    /** Create a TCA9546A instance connected to specified I2C pins with specified address
     *
     * @param sda I2C-bus SDA pin
     * @param scl I2C-bus SCL pin
     * @param i2c_address I2C-bus address (default: 0x70)
     * @param reset TCA9546A reset pin (default: NC for simple pullup connected)
     * @param hz I2C bus frequency (default: 400kHz)
     */
    TCA9548A( PinName sda, PinName scl, uint8_t i2c_address = 0x70, PinName resetPin = NC, uint32_t hz = 400000 );
 
    /** Selecting a channel
     *
     *  Switch to commended downstream I2C channel
     *
     * @param channel channel number
     */
    void select(uint8_t channel);
 
    /** Reset TCA9546A
     *
     *  Reset switch
     */
    void reset();
 
 
private:
    I2C i2c_;
    DigitalOut reset_pin;
    uint8_t i2c_addr;

};
 
#endif  //  TCA9548A_H