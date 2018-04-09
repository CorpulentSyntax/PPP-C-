//Student: Mark van Broeckhuijsen
//Opdracht 

#include "std_lib_facilities.h"

int throw_single_dice() {
	return (rand() % 6) + 1; //Generates a random number between 1-6
}

vector<int> calc_values(int amount_throws) {
	int total_value = 0;
	vector<int> dice_value;

	for (int i = 0; i < amount_throws; ++i) {
		for (int j = 0; j < 4; ++j) { //Throws 4 dice per throw
			total_value += throw_single_dice(); 
		}
		dice_value.push_back(total_value); //adds total values of the 4 dice to a vector
		total_value = 0;
	}
	return dice_value;
}

vector<int> sort_values(vector<int> dice_value) {
	sort(dice_value.begin(), dice_value.end()); //sorts the vector from low to high
	return dice_value;
}

void output(vector<int> dice_value) {
	int eyes = 6; //Starts the histogram at the minimum throwable value
	for (int i = 0; i < 19; ++i) {
		cout << endl << eyes << ":\t"; //Outputs the amount of eyes
		for (int j = 0; j < dice_value.size(); ++j) {
			if (dice_value[j] == eyes) cout << "*"; //Outputs a asterisk if the value in the index = the current amount of eyes
		}
		++eyes;
	}
	cout << endl;
}

int main() 
try {
	int amount_throws = 0;
	vector<int> dice_value;

	cout << "This program lets you throw 4 dice for x amount of times." << endl 
	     << "Afterwards it will display the total values of the eyes in a histogram" << endl 
		 << "Please enter the amount of throws: ";
	cin >> amount_throws;
	if (amount_throws < 1) error("Amount of throws cant be zero of negative!"); //Errorhandling for negative input

	dice_value = calc_values(amount_throws); //Calls the calc_values funtion to make a vector of the total value per throw
	dice_value = sort_values(dice_value); //Calls the sort_values function to sort the vector from low to high
	output(dice_value); //Calls the function to output the histogram

	system("pause");
	return 0;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	system("pause");
	return 1;
}

catch (...) {
	cerr << "Unknown error! " << endl;
	system("pause");
	return 2;
}
