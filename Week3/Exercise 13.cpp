#include "std_lib_facilities.h"

int bulls;
int cows;

vector<int> itov(int n)
{
	if (n>9999 || n<0) error("Wrong input! Numbers between 0000 and 9999 only");
	vector<int> v(4);
	v[0] = n / 1000 % 10;
	v[1] = n / 100 % 10;
	v[2] = n / 10 % 10;
	v[3] = n % 10;
	return v;
}

vector<int> rand_number()
{
	vector<int> random(4);
	random[0] = randint(9);
	random[1] = randint(9);
	random[2] = randint(9);
	random[3] = randint(9);
	return random;
}

void check(vector<int> vec_guess, vector<int> answer)
{
	bulls = 0;
	cows = 0;
	vector<char> is_bull(4, 'n');
	vector<char> is_cow(4, 'n');
	for (int i = 0; i<answer.size(); ++i) {
		if (vec_guess[i] == answer[i]) {
			++bulls;
			is_bull[i] = 'y';
		}
	}
	for (int i = 0; i<answer.size(); ++i) {
		if (is_bull[i] == 'n') {
			for (int j = 0; j<vec_guess.size(); ++j) {
				if (is_bull[j] == 'n' && is_cow[j] == 'n') {
					if (answer[i] == vec_guess[j]) {
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
	
	int guess = 0;
	int seed = 0;

	cout << "Please enter a seed: ";
	cin >> seed;
	srand(seed);
	vector<int> answer = rand_number();

	cout << "Please enter your guess!\n";
	while (cin >> guess) {
		vector<int> vec_guess = itov(guess);
		check(vec_guess, answer);

		if (bulls == 4) {
			cout << "You have guessed the number!\n";
			answer = rand_number();
			system("pause");
			exit(EXIT_SUCCESS);
		}
		else if (bulls < 4) {
			cout << "Number of bulls: " << bulls << endl;
			cout << "Number of cows: " << cows << endl;
		}

		cout << "\nPlease enter your next guess:\n";
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
