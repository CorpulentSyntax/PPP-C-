#include "std_lib_facilities.h"

int main()
try {
	int n = 0;
	double val;
	vector<int> vec;
	vector<double> vec_exact;
	int total = 0;
	double total_exact = 0.0;

	cout << "Please enter the number of values you want to sum:\n";
	cin >> n;
	if (n <= 0) error("Value needs to be greater than zero");
	cout << "\nNow enter some integers (press '/' to stop):\n";

	while (cin >> val) {
		vec.push_back(val);
		vec_exact.push_back(val);
	}

	if (vec.size() < n) error("You wanted to sum more values than you entered, please try again");
	else {
		for (int i = 0; i <= n - 1; ++i) {
			total += vec[i];
			total_exact += vec_exact[i];
		}
		if (total != total_exact) error("Result cannot be interpreted as an int");
		else cout << "\nThe sum is: " << total << "\n" << total_exact;
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