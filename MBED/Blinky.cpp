#include "mbed.h"
 
DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(A0);
 
int main() {
  while(1) {
    if (mybutton == 0) { // Button is pressed
        for (int i = 0; i <3; ++i) {   
            for (int j = 0; j < 3; ++j) {
               myled = !myled; // Toggle the LED state
               if (i % 2 == 0) wait(0.5);
               if (i % 2 == 1) wait(1); // 500 ms
               myled = !myled;
               wait(0.5);
              }
        }
     }
   }
 }
