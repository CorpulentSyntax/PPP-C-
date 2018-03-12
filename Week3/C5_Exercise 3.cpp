#include "std_lib_facilities.h"

double ctok(double c) {
	double k = c + 273.15;
	return k;
}

int main() {
	double d = 0;
	double conv;

	cout << "Enter degrees in Celsius (C):\n";
	cin >> d;
	conv = ctok(d);

	if (conv < 0) {
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
