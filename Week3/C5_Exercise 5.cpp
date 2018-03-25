#include "std_lib_facilities.h"

double ctok(double c) {
	if (c < -273.15) error("The given temperature is below absolute zero"); //If the temp in K is below 0K the computation is invalid
	double k = c + 273.15; //Calculation used to calculate Kelvin from Celsius
	return k;
}

double ktoc(double k) {
	if (k < 0.00) error("The given temperature is below absolute zero"); //If the temp in K is below 0K the computation is invalid
	double c = k - 273.15; //Calculation used to calculate Calsius from Kelvin
	return c;
}

int main() 
try {
	double deg = 0.0;
	double conv;
	char unit;

	cout << "Please enter where you want to calculate to (Celsius C/c or Kelvin K/k) followed by the value: " << endl;
	cin >> unit >> deg;

	if (unit == 'K' || unit == 'k') {
		conv = ctok(deg); //Calls up the ctok function if the unit is K or k
		cout << deg << " degrees Celsius is " << conv << " degrees Kelvin" << endl;
	}
	else if (unit == 'C' || unit == 'c') {
		conv = ktoc(deg); //Calls up the ktoc function if the unit is C or c
		cout << deg << " degrees Kelvin is " << conv << " degrees Celsius" << endl;
	}
	else {
		cout << "Invalid unit used. Use C/c or K/k, please try again" << endl; //Unit can only be C/c or K/k
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
	cerr << "Unknown exception!" << endl; \
		system("pause");
	return 2;
}
