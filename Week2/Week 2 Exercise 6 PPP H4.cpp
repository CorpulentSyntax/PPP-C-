//This program writes the number 9 to its text value Nine and vice versa
#include "std_lib_facilities.h"

int main() {
	vector<string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };										//Defines the vector for both numbers and strings
	vector<string> text = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	string input;

	cout << "Please input an int value (0-9) or the capitalized textual representation of the numbers 0-9: ";
	while (cin >> input) {
		bool correct = false;
		for (int i = 0; i < text.size(); ++i) {																			//Starts the loop in which it is determinted what input is used
			if (text[i] == input) {
				cout << "The numeric representation of " << input << " is " << i << "\n";
				correct = true;																							//Boolean used to check whether the used syntax is correct
			}
			else if (numbers[i] == input) {
				cout << "The textual representation of " << input << " is " << text[i] << "\n";
				correct = true;
			}
		}

		if (!correct) {																									//If bool 'correct' is not true after finishing the loop this is the output
			cout << "Please input according to the syntax\n";
			system("pause");
			exit(EXIT_FAILURE);
		}

		system("pause");
		return 0;
	}
}