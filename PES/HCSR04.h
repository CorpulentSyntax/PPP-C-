#ifndef HCSR04_H_TVZMT
#define HCSR04_H_TVZMT

/** A distance measurement class using ultrasonic sensor HC-SR04.
 *  
 * Example of use:
 * @code
 * #include "mbed.h"
 * #include "HCSR04.h"
 *
 * Serial pc(USBTX, USBRX);
 * Timer timer;
 *
 * int main() {
 *     HCSR04 sensor(p5, p7);
 *     sensor.setRanges(10, 110);
 *     pc.printf("Min. range = %g cm\n\rMax. range = %g cm\n\r",
 *       sensor.getMinRange(), sensor.getMaxRange());
 *     while(true) {
 *         timer.reset();
 *         timer.start();
 *         sensor.startMeasurement();
 *         while(!sensor.isNewDataReady()) {
 *             // wait for new data
 *             // waiting time depends on the distance
 *         }
 *         pc.printf("Distance: %5.1f mm\r", sensor.getDistance_mm());
 *         timer.stop();
 *         wait_ms(500 - timer.read_ms()); // time the loop
 *     }
 * }
 * @endcode
 */
class HCSR04 {
    
    public:
    
    /** Receives two PinName variables.
     * @param echoPin mbed pin to which the echo signal is connected to
     * @param triggerPin mbed pin to which the trigger signal is connected to
     */
    HCSR04(PinName echoPin, PinName triggerPin);
    
    /** Start the measurement. Measurement time depends on the distance.
     *  Maximum measurement time is limited to 25 ms (400 cm).
     */
    void startMeasurement();
    
    /** Returns the distance in cm. Requires previous call of startMeasurement().
     * @returns distance of the measuring object in cm.
     */
    float getDistance_cm();
    
    /** Returns the distance in mm. Requires previous call of startMeasurement().
     * @returns distance of the measuring object in mm.
     */
    float getDistance_mm();
    
    /** Sets the minimum and maximum ranges between the factory values of 2 cm and 400 cm.
     *  @param minRange Minimum range in cm. Must be between 2 cm and maxRange.
     *  @param maxRange Maximum range in cm. Must be between minRange and 400 cm.
     */
    void setRanges(float minRange, float maxRange);
    
    /** Retreives the minimum sensor range set by the user.
     * @returns the minimum sensor range set by the user in cm.
     */
    float getMinRange();
    
    /** Retreives the maximum sensor range set by the user.
     * @returns the maximum sensor range set by the user in cm.
     */
    float getMaxRange();
    
    /** Checks if the new data is ready.
     * @returns true if new data is ready, false otherwise.
     */
    bool isNewDataReady();
    
    private:
    
    InterruptIn echo;       // echo pin
    DigitalOut trigger;     // trigger pin
    Timer timer;            // echo pulsewidth measurement
    float distance;         // store the distance in cm
    float minDistance;      // minimum measurable distance
    float maxDistance;      // maximum measurable distance
    Timeout triggerTimeout, echoTimeout;
    bool newDataReady, timerStarted;
    
    /** Start the timer. */
    void startTimer();
    
    /** Stop the timer. */
    void stopTimer();
    
    /** Initialization. */
    void init();
    
    void turnOffTrigger();
};

#endif