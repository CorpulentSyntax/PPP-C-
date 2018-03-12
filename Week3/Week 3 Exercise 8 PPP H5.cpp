#include "std_lib_facilities.h"

int main() 
try {
	int n = 0;
	int val;
	vector<int> vec;
	int total = 0;

	cout << "Please enter the number of values you want to sum:\n";
	cin >> n;
	if (n <= 0) error("Value needs to be greater than zero");
	cout << "\nNow enter some integers (press '/' to stop):\n";

	while (cin >> val) {
		vec.push_back(val);
	}

	if (vec.size() < n) {
		error("You wanted to sum more values than you entered, please try again");

	}
	else {
		for (int y = 0; y <= n - 1; ++y) {
			total += vec[y];
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