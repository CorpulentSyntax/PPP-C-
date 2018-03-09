//Dit programma sorteert (oplopend) 3 ingevoerde integers
#include "std_lib_facilities.h"

int main() {	
	int val1 = 0;
	int val2 = 0;
	int val3 = 0;
	int small = 0;																
	int medium = 0;
	int large = 0;
	cout << "Please enter a range of 3 numbers (separated by a space): ";
	cin >> val1 >> val2 >> val3;											
	
	if (val1 <= val2) {			//Vergelijkt de waardes en schrijft deze toe aan de variabele small, medium of large op basis van logica en vergelijking
		if (val1 <= val3) {
			small = val1;
			if (val2 <= val3) {
				medium = val2;
				large = val3;
			}
			else {
				medium = val3;
				large = val2;
			}
		}
		else {
			small = val3;
			medium = val1;
			large = val2;
		}
	}
	else {
		if (val1 > val3) {
			large = val1;
			if (val2 <= val3) {
				small = val2;
				medium = val3;
			}
			else {
				small = val3;
				medium = val2;
			}
		}
		else {
			small = val2;
			medium = val1;
			large = val3;
		}
	}

	cout << small << ", " << medium << ", " << large << "\n";	//Outputs de 3 int waardes gesorteerd op waarde gescheiden door een komma
	
	system("pause");														
	return 0;
}
