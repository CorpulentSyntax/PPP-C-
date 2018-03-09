//This program calculates the total number of grains recieved and current number of grains per square
#include "std_lib_facilities.h"

int main() {
	int grains = 0;
	int current = 1;

	cout << "Total\t\t" << "Current square\t\t" << "Square\n";
	for (int square = 1; square < 64; ++square) {								//This loops allows for 64 consequent calculations
		grains += current;														//Adds the new amount of grains to the previous
		cout << grains << "\t\t" << current << "\t\t" << square << "\n";
		current *= 2;															//Doubles the variable current as required
	}
	system("pause");
	return 0;
}
