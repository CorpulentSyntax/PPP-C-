#include "std_lib_facilities.h"

double ctof(double c) {
	double f = 9.0/5*c+32;
	return f;
}

double ftoc(double f) {
	double c = (f-32)/(9.0/5);
	return c;
}

int main() {
	double deg = 0;
	double conv;
	char unit;

	cout << "Enter degrees in Celsius (c/C) or Fahrenheit (f/F) followed by the unit:\n";
	cin >> deg >> unit;

	if (unit == 'C' || unit == 'c') {
		conv = ctof(deg);
		cout << deg << " degrees Celsius is " << conv << " degrees Fahrenheit\n";
	}
	else if (unit == 'F' || unit == 'f') {
		conv = ftoc(deg);
		cout << deg << " degrees Fahrenheit is " << conv << " degrees Celsius\n";
	}
	else {
		cout << "Invalid unit used. Use C or F, please try again\n";
	}

	system("pause");
	return 0;
}
