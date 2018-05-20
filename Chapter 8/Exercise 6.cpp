#include "std_lib_facilities.h"

vector<string> func_reverse(vector<string> orig_vec) {
	vector<string> reversed_vec;

	for (int i = 0; i < orig_vec.size(); ++i) {
		reversed_vec.push_back(orig_vec[(orig_vec.size() - 1) - i]); //Creates a new (reversed) vector by adding the last index value of the orig_vec to the first index of the reversed_vec 
	}

	return reversed_vec;
}

vector<string> func_swap(vector<string> orig_vec) {
	for (int i = 0; i < orig_vec.size() / 2; ++i) {

		string temp = orig_vec[i]; //Stores the index value as a temp value 
		orig_vec[i] = orig_vec[(orig_vec.size() - 1) - i]; //The first index value becomes the last index value
		orig_vec[(orig_vec.size() - 1) - i] = temp; //The last index value becomes the first index value
	}
	return orig_vec;
}

int main() {
	string s;
	vector<string> orig_vec;
	vector<string> reversed_vec;

	cout << "Please enter a series of strings separated by a white-space. End the series with 'q'" << endl;
	while (cin >> s) {
		if (s == "q") break;
		else orig_vec.push_back(s); //Creates the base vector
	}

	cout << endl << "Your series of strings reversed with method 1 (additional vector) is: " << endl;
	reversed_vec = func_reverse(orig_vec); //Calls on the function func_reverse
	for (int i = 0; i < reversed_vec.size(); ++i) {
		cout << reversed_vec[i] << " ";
	}

	cout << endl << endl << "Your series of strings reversed with method 2 (no additional vector, swap) is: " << endl;
	orig_vec = func_swap(orig_vec); //Calls on the function func_swap
	for (int i = 0; i < orig_vec.size(); ++i) {
		cout << orig_vec[i] << " ";
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
