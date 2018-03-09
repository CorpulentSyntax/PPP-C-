#include "std_lib_facilities.h"

int main() {
	vector<int> v;
	int number = 0;
	int mode = 0;
	int cnt = 0;
	int max = 0;
	int temp;
	int start;

	cout << "Please enter a series of int numbers separated by a space and ended with a '/': \n";
	
	while (cin >> number) {
		v.push_back(number);
	}
	sort(v.begin(), v.end());

	if (v[0] >= 0) {
		while (cnt < v.size()) {
			start = cnt;
			temp = v[cnt];
			while (cnt < v.size() && v[cnt] == temp) {
				++cnt;
			}
			if (cnt - start > max) {
				mode = temp;
				max = cnt - start;
			}
		}
		cout << "The mode is: " << mode << "\n";
	}
	else {
		cout << "The input accepts positive numbers only.\nPlease try again.\n";
	}

	system("pause");
	return 0;
}

