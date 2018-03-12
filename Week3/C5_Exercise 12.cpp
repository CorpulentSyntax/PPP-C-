#include "std_lib_facilities.h"

int bulls;
int cows;

vector<int> itov(int n)
{
	if (n>9999 || n<0) error("int_to_vector called with wrong number");
	vector<int> v(4);
	v[0] = n / 1000 % 10;
	v[1] = n / 100 % 10;
	v[2] = n / 10 % 10;
	v[3] = n % 10;
	return v;
}

void check(vector<int> vecn, vector<int> vec)
{
	bulls = 0;
	cows = 0;
	vector<char> is_bull(4, 'n');
	vector<char> is_cow(4, 'n');
	for (int i = 0; i<vec.size(); ++i) {
		if (vecn[i] == vec[i]) {
			++bulls;
			is_bull[i] = 'y';
		}
	}
	for (int i = 0; i<vec.size(); ++i) {
		if (is_bull[i] == 'n') {
			for (int j = 0; j<vecn.size(); ++j) {
				if (is_bull[j] == 'n' && is_cow[j] == 'n') {
					if (vec[i] == vecn[j]) {
						++cows;
						is_cow[j] = 'y';
					}
				}
			}
		}
	}
}

int main() 
try {
	vector<int> vec = { 3, 1, 8, 0 };
	int g;
	
	cout << "Please enter your guess!\n";
	while (cin >> g) {
		vector<int> vecn = itov(g);
		check(vecn, vec);
	
		if (bulls == 4) {
			cout << "You have guessed the number!\n";
			system("pause");
			exit(EXIT_SUCCESS);
		}
		else if (bulls < 4) {
			cout << "Number of bulls: " << bulls << endl;
			cout << "Number of cows: " << cows << endl;
		}

		cout << "Please enter your next guess:\n";
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
