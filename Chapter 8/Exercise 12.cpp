#include "std_lib_facilities.h"

void print_until_s(vector<string>& v, string& quit) {
	cout << endl;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit) return; //Stops the function if the cut-off word is recognized
		cout << v[i] << endl;
	}
}

void print_until_ss(vector<string>& v, string& quit) {
	int counter = 0;
	cout << endl;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit) {
			if (counter == 1) return; //Only stops the function if the cut-off word has been recognized twice
			else ++counter;
		}
		cout << v[i] << endl;
	}
}

int main() {
	string s;
	vector<string> v;
	string quit_at;

	cout << "Please enter a series of strings separated by a white-space, end the series with 'q': " << endl;
	while (cin >> s) {
		if (s == "q") break;
		v.push_back(s); //Creates the vector of strings

	}
	cout << endl << "Enter the cut-off word for the print function: " << endl;
	cin >> quit_at;

	print_until_s(v, quit_at); //Calls on the functions
	print_until_ss(v, quit_at);

	cout << endl;
	system("pause");
	return 0;
}
