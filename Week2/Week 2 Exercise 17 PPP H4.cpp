#include "std_lib_facilities.h"

int main() {
	vector<string> v;
	string name = "";
	string mode = "";
	string temp;
	int cnt = 0;
	int max = 0;
	int start;

	cout << "Please enter a serie of strings separated by a space and ended with a '/': \n";

	while (cin >> name) {
		if (name == "/") {
			break;
		}
		else {
			v.push_back(name);
		}
	}
	sort(v.begin(), v.end());

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
	
	cout << "The minimum is: " << v[0] << "\n";
	cout << "The maximum is: " << v[v.size()-1] << "\n";
	cout << "The mode is: " << mode << "\n";

	system("pause");
	return 0;
}

