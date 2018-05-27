#include "mbed.h"
 
DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(A0);
 
void morse_sos(){
   for (int i = 0; i <3; ++i) {
     for (int j = 0; j < 3; ++j) {
        myled = !myled; // Toggle the LED state
        if (i % 2 == 0) wait(0.5); // The first and third time this loop is executed the led will remain on for 500 ms each time (short blink)
        if (i % 2 == 1) wait(1); // The second time this loop is executed the led will remain on for 1 s each time (long blink)
        myled = !myled;
        wait(0.5);
     } 
   }
 } 
 
int main() {
  while(1) {
    if (mybutton == 0) morse_sos(); // Button is pressed
   }
 }
