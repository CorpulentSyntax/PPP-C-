#include "std_lib_facilities.h"

double ctok(double c) {
	double k = c + 273.15; //Calculation used to calculate Kelvin from Celsius
	return k;
}

int main() {
	double d = 0;
	double conv;

	cout << "Enter degrees in Celsius (C):\n";
	cin >> d;
	conv = ctok(d); //Calls up the ctok function

	if (conv < 0) { //If the temp in K is below 0K the computation is invalid
		cout << "The given temperature is below absolute zero.\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
	else {
		cout << d << " degrees Celsius is " << conv << " degrees Kelvin\n";
	}

	system("pause");
	return 0;
}
