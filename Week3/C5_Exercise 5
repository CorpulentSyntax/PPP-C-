#include "std_lib_facilities.h"

double ctok(double c) {
	if (c < -273.15) error("The given temperature is below absolute zero");
	double k = c + 273.15;
	return k;
}

double ktoc(double k) {
	if (k < 0.00) error("The given temperature is below absolute zero");
	double c = k - 273.15;
	return c;
}

int main() 
try {
	double deg = 0.0;
	double conv;
	char unit;

	cout << "Enter degrees in Celsius (c/C) or Kelvin (k/K) followed by the unit:\n";
	cin >> deg >> unit;

	if (unit == 'C' || unit == 'c') {
		conv = ctok(deg);
		cout << deg << " degrees Celsius is " << conv << " degrees Kelvin\n";
	}
	else if (unit == 'K' || unit == 'k') {
		conv = ktoc(deg);
		cout << deg << " degrees Kelvin is " << conv << " degrees Celsius\n";
	}
	else {
		cout << "Invalid unit used. Use C or K, please try again\n";
	}

	system("pause");
	return 0;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	system("pause");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n"; \
		system("pause");
	return 2;
}
