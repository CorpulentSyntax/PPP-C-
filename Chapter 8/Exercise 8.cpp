#include "std_lib_facilities.h"

vector<double> sorting(vector<double> vec_age, vector<string> vec_name, vector<double> sort_age, vector<string> copy_name) {
	for (int i = 0; i < vec_name.size(); ++i) {
		for (int j = 0; j < vec_name.size(); ++j) {
			if (copy_name[i] == vec_name[j]) {
				sort_age[j] = vec_age[i]; //If the name in the sorted name vector is equal to the name in the original vector reassign the index value of the original age (i) to the new index location (j)
			}
		}
	}
	return sort_age;
}

int main()
try {
	double age;
	string name;
	vector<string> vec_name;
	vector<double> vec_age;

	cout << "Enter a string of names separated by a white-space, end the series with 'q': " << endl;
	while (cin >> name && name != "q") {
		for (int i = 0; i < vec_name.size(); ++i) {
			if (name == vec_name[i]) error("Duplicate name");
		}
		vec_name.push_back(name);
	}

	cout << endl << "Now please enter the age of each name" << endl;
	for (int i = 0; i < vec_name.size(); ++i) {
		cout << vec_name[i] << ": ";
		cin >> age;
		vec_age.push_back(age);
	}

	vector<double> sort_age(vec_name.size());
	vector<string> copy_name = vec_name;
	sort(vec_name.begin(), vec_name.end()); //Sorts the name vector
	sort_age = sorting(vec_age, vec_name, sort_age, copy_name); //Calls the function 'sorting'

	cout << endl << "Let's sort the list by name" << endl;
	for (int i = 0; i < vec_name.size(); ++i) {
		cout << "- " << vec_name[i] << " is " << sort_age[i] << " y.o." << endl;
	}

	cout << endl;
	system("pause");
	return 0;
	}


catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	system("pause");
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	system("pause");
	return 2;
}
