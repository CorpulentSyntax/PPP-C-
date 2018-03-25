#include "std_lib_facilities.h"

double ctof(double c) {
	double f = 9.0/5*c+32; //Calculation used to calculate Fahrenheit from Celsius
	return f;
}

double ftoc(double f) {
	double c = (f-32)/(9.0/5); //Calculation used to calculate Celsius from Fahrenheit
	return c;
}

int main() {
	double deg = 0;
	double conv;
	char unit;

	cout << "Enter where you want to calculate to (Celcius C/c or Fahrenheit F/f) followed by the value:" << endl;
	cin >> deg >> unit;

	if (unit == 'F' || unit == 'f') {
		conv = ctof(deg); //Calls up the ctof function if the unit is F or f
		cout << deg << " degrees Celsius is " << conv << " degrees Fahrenheit" << endl;
	}
	else if (unit == 'C' || unit == 'c') {
		conv = ftoc(deg); //Calls up the ftoc function if the unit is C or c
		cout << deg << " degrees Fahrenheit is " << conv << " degrees Celsius" << endl;
	}
	else {
		cout << "Invalid unit used. Use C or F, please try again" << endl; //Unit can only be C/c or F/f
	}

	system("pause");
	return 0;
}
