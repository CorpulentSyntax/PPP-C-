#include "mbed.h"
#include "HCSR04.h"

HCSR04::HCSR04(PinName echoPin, PinName triggerPin) : echo(echoPin), trigger(triggerPin) {
    init();
}

void HCSR04::init() {
    distance = -1;      // initial distance
    minDistance = 2;
    maxDistance = 400;
    newDataReady = timerStarted = false;
}

void HCSR04::startTimer() {
    if (!timerStarted) {
        timer.start(); // start the timer
        timerStarted = true;
        echoTimeout.attach_us(this, &HCSR04::stopTimer, 25000); // in case echo fall does not occur
        echo.fall(this, &HCSR04::stopTimer);
        echo.rise(NULL);
    }
}

void HCSR04::stopTimer() {
    timer.stop(); // stop the timer
    if (timerStarted) {
        distance = timer.read() * 1e6 / 58;
        if (distance < minDistance)
            distance = minDistance;
        if (distance > maxDistance)
            distance = maxDistance;
        newDataReady = true;
    }
    timer.reset();
    timerStarted = false;
    echoTimeout.detach();
    echo.fall(NULL);
}

void HCSR04::turnOffTrigger() {
    trigger = 0; 
}

void HCSR04::startMeasurement() {
    trigger = 1;
    triggerTimeout.attach_us(this, &HCSR04::turnOffTrigger, 10);
    echo.rise(this, &HCSR04::startTimer);
    newDataReady = false;
}

float HCSR04::getDistance_cm() {
    newDataReady = false;
    return distance;
}

float HCSR04::getDistance_mm() {
    newDataReady = false;
    return distance * 10;
}

bool HCSR04::isNewDataReady() {
    return newDataReady;
}

void HCSR04::setRanges(float minRange, float maxRange) {
    if (minRange < maxRange) {
        if (minRange >= 2 && minRange < 400) // bug from revs. 4 and 5 corrected
            minDistance = minRange;
        if (maxRange <= 400)
            maxDistance = maxRange;
    }
}

float HCSR04::getMinRange() {
    return minDistance;
}

float HCSR04::getMaxRange() {
    return maxDistance;
}