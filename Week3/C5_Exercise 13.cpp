#include "std_lib_facilities.h"

int bulls = 0;
int cows = 0;

vector<int> itov(int n) //Converts the int guess to an int vector
{
	if (n<0 || n>9999) error("Wrong input! Numbers between 0000 and 9999 only");
	vector<int> v(4);
	v[0] = n / 1000 % 10;
	v[1] = n / 100 % 10;
	v[2] = n / 10 % 10;
	v[3] = n % 10;
	return v;
}

vector<int> new_rand_number() //Makes a new random number vector of numbers between 0-9
{
	vector<int> answer(4);
	answer[0] = randint(9);
	answer[1] = randint(9);
	answer[2] = randint(9);
	answer[3] = randint(9);
	return answer;
}

void check(vector<int> guess, vector<int> answer) //Checks if the guess is the same as the answer
{
	bulls = 0;
	cows = 0;
	vector<char> is_bull(4, 'n');
	vector<char> is_cow(4, 'n');
	for (int i = 0; i<answer.size(); ++i) { 
		if (guess[i] == answer[i]) { //Compares each index of the guess vector against the answer vector
			++bulls;
			is_bull[i] = 'y'; //If the value is a bull, making the is_bull index value y "removes" this index from trying
		}
	}
	for (int i = 0; i<answer.size(); ++i) {
		if (is_bull[i] == 'n') { //Checks if value has been removed because of is_bull
			for (int j = 0; j<guess.size(); ++j) {
				if (is_bull[j] == 'n' && is_cow[j] == 'n') { //Checks every other index of the answer vector against the first guess index, this is repeated for all non-removed indexes
					if (answer[i] == guess[j]) {
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
	srand(seed); //the seed randomises the random numbers
	vector<int> answer = new_rand_number();

	cout << "Please enter your guess!\n";
	while (cin >> guess) {
		if (guess < 0 || guess > 9999) cout << "Wrong input! Numbers between 0000 and 9999 only\n"; //Guess cant be negative of more than 4 digits
		else {
			vector<int> vec_guess = itov(guess);
			check(vec_guess, answer);
			if (bulls == 4) { //The number has been guessed if the number of bulls is 4
				cout << "You have guessed the number!\n";
				answer = new_rand_number(); //Sets a new answer if the guess was correct
			}
			if (bulls < 4) { //Displays the amount of bulls and cows
				cout << "Number of bulls: " << bulls << endl;
				cout << "Number of cows: " << cows << endl;
			}
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
