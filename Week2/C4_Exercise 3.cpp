#include "std_lib_facilities.h"

int main() {
	vector<double> v;
	double dist;
	double sum = 0;
	double mean = 0;
	double small = 0;
	double large = 0;

	cout << "Please enter double type numbers followed by a space, end the serie with '/'\n";	//Allows for input into the program
	while (cin >> dist) {
		if (dist > 0) {
			v.push_back(dist);
		}
		else {
			cout << "Invalid input! Positive numbers only\n";	//Checks whether the input is positive (negative distance doesn't make sense)
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	small = v[0];								//Give an initial value to both small and large so the answer isn't continuously 0
	large = v[0];
	for (int i = 0; i < v.size(); ++i) {					//This loop checks whether the current vector value is smaller or greater than the previous value
		sum += v[i];							//It also adds all entered values together to calculate the sum
		if (v[i] < small) {
			small = v[i];
		}
		else if (v[i] > large) {
			large = v[i];
		}
	}

	mean = sum / v.size();							//Assigns the value to mean according to the previous values in the loops
	cout << "The sum of all distances is: " << sum << "\n";
	cout << "The mean distance is: " << mean << "\n";
	cout << "The smallest distance is: " << small << "\n";
	cout << "The largest distance is: " << large << "\n";
	
	)

	v[v.size()]

	system("pause");
	return 0;
}
