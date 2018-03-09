//Sorteert 3 ingevoerde strings op alfabet
#include "std_lib_facilities.h"

int main() {
	string val1;
	string val2;
	string val3;
	string small;															
	string medium;
	string large;
	cout << "Please enter 3 strings (separated by a space): ";
	cin >> val1 >> val2 >> val3;	

	if (val1 <= val2) {				//Vergelijkt de waardes en schrijft deze toe aan de variabele small, medium of large op basis van logica en vergelijking
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
