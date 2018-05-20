#include "std_lib_facilities.h"

vector<double> sorting(vector<double> vec_age, vector<string> vec_name, vector<double> sort_age, vector<string> copy_name) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (copy_name[i] == vec_name[j]) {
				sort_age[j] = vec_age[i]; //If the name in the sorted name vector is equal to the name in the original vector reassign the index value of the original age (i) to the new index location (j)
			}
		}
	}
	return sort_age;
}

int main() {
	double age;
	vector<string> vec_name = { "Bob", "Henk", "Karel", "Diederik", "Lodewijk" }; // In this case the names are given
	vector<double> vec_age;
	vector<double> sort_age(5);

	cout << "Please enter the age for each name: " << endl;
	for (int i = 0; i < 5; ++i) {
		cout << vec_name[i] << ": ";
		cin >> age;
		vec_age.push_back(age); //Creates the age vector
	}
	
	vector<string> copy_name = vec_name;
	sort(vec_name.begin(), vec_name.end()); //Sorts the name vector
	sort_age = sorting(vec_age, vec_name, sort_age, copy_name); //Calls the function 'sorting'

	cout << endl << "Let's sort the names" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << vec_name[i] << " is " << sort_age[i] << " y.o." << endl;
	}

	system("pause");
	return 0; 
}
