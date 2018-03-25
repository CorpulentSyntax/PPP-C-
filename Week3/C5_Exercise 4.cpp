#include "std_lib_facilities.h"

double ctok(double c) {
	if (c < -273.15) error("Temperature below absolute zero!"); //If the temp in K is below 0K the computation is invalid
	double k = c + 273.15; //Calculation used to calculate Kelvin from Celsius
	return k;
}

int main() 
try {
	double d = 0;
	double conv;

	cout << "Enter degrees in Celsius (C):\n";
	cin >> d;
	conv = ctok(d); //Calls up the ctok function
	cout << d << " degrees Celsius is " << conv << " degrees Kelvin\n";

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
