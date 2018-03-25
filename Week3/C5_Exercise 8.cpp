#include "std_lib_facilities.h"

int main() 
try {
	int n = 0;
	int val;
	vector<int> vec;
	int total = 0;

	cout << "Please enter the number of values you want to sum:\n";
	cin >> n;
	if (n <= 0) error("Value needs to be greater than zero"); //The amount of values you want to sum can't be negative
	cout << "\nNow enter some integers (press '/' to stop):\n";

	while (cin >> val) {
		vec.push_back(val); //Adds the new entered value to the front of the vector
	}

	if (vec.size() < n) {
		error("You wanted to sum more values than you entered, please try again"); //You cant sum the value if it doesnt exist!

	}
	else {
		for (int y = 0; y <= n - 1; ++y) {
			total += vec[y]; //Sums the values until the index number is n-1
		}
		cout << "\nThe sum is: " << total << "\n";
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
