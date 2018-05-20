#include "std_lib_facilities.h"

vector<int> func_reverse(vector<int> orig_vec) {
	vector<int> reversed_vec;

	for (int i = 0; i < orig_vec.size(); ++i) {
		reversed_vec.push_back(orig_vec[(orig_vec.size() - 1) - i]); //Creates a new (reversed) vector by adding the last index value of the orig_vec to the first index of the reversed_vec 
	}

	return reversed_vec;
}

int main() {
	int nmbr;
	vector<int> orig_vec;
	vector<int> reversed_vec;

	cout << "Please enter a series of integers separated by a white-space. End the series with 'q'" << endl;
	while (cin >> nmbr) {
		orig_vec.push_back(nmbr); //Creates the base vector
	}

	cout << endl << "Your series of integers reversed with method 1 (additional vector) is: " << endl;
	reversed_vec = func_reverse(orig_vec); //Calls on the function func_reverse
	for (int i = 0; i < reversed_vec.size(); ++i) {
		cout << reversed_vec[i] << " ";
	}

	cout << endl << endl << "Your series of integers reversed with method 2 (no additional vector, swap) is: " << endl;
	for (int i = 0; i < orig_vec.size() / 2; ++i) {
		swap(orig_vec[i], orig_vec[(orig_vec.size() - 1) - i]);
	}

	for (int i = 0; i < orig_vec.size(); ++i) {
		cout << orig_vec[i] << " ";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
