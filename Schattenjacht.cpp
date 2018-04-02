#include "std_lib_facilities.h"
#include <windows.h>

int split_column(int current_cd) {
	int cd_column;
	cd_column = current_cd % 10; //Splits the last digit from the value
	cd_column -= 1; //Substracts 1 because of how vectors work
	if (cd_column < 0) error("Coordinate cant be negative!");
	return cd_column;
}

int split_row(int current_cd) {
	int cd_row;
	cd_row = current_cd / 10; //Splits the first digit from the value
	cd_row -= 1; //Substracts 1 because of how vectors work
	if (cd_row < 0) error("Coordinate cant be negative!");
	return cd_row;
}

int main() 
try {
	const vector<vector<int>> treasure_map{ {34,21,32,41,25},
											{14,42,43,14,31},
											{54,45,52,42,23},
											{33,15,51,31,35},
											{21,52,33,13,23} };
	bool found = false;
	int current_cd = treasure_map[0][0]; //Start searching at row 1, column 1 of the treasure map
	int cd_column = 0; //The column part of the coordinate
	int cd_row = 0; //The row part of the coordinate
	int previous_cd = 0;
	
	cout << "YARGHH! Try to find me treasure ye scobberwolly! I'll give ye me map YARGH!" << endl;
	for (int i = 0; i < treasure_map.size(); ++i) { //Prints the treasure_map in the console
		for (int j = 0; j < treasure_map.size(); ++j) {
			cout << treasure_map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	while (found == false) {
		cout << "The value found at this location is: " << "[" << current_cd << "]" << endl;

		cd_row = split_row(current_cd);
		cd_column = split_column(current_cd); //Uses the function to split the current coordinate
		current_cd = treasure_map[cd_row][cd_column]; //current coordinate becomes the value located at the position determined by the previous value
		if (current_cd == previous_cd) found = true;
		previous_cd = current_cd;

		cout << "Treasure not found! Now relocating to row " << cd_row + 1
			<< " and column " << cd_column + 1 << endl << endl; //Adds one to the row and column value to correspond with the traditional way of reading rows and columns
		Sleep(2000 +rand() % 1000);
	}

	cout << "Treasure found! It was located at [" << cd_row + 1 << "," << cd_column + 1 << "] all along! You better start digging!" << endl;
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
