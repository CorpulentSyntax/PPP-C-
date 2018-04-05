#include "std_lib_facilities.h"

string read_text(void) {
	string s;
	cout << "Please input a sentence to encrypt. End the sentence with the letter 'q':" << endl;

	for (string input; cin >> input;) {
		if (input == "q") break; //If the input is 'q' the loop stops
		s += input; //Removes whitespaces and concatenates string
	}
	return s;
}

string string_to_upper(string s) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] > 96 && s[i] < 123) s[i] -= 32; //If the char is lowercase change it to uppercase
		if (s[i] > 64 && s[i] < 91) ; //Do nothing if char is already uppercase
		else s[i] = 69; //All other chars become 'E'
	}

	return s;
}

string ceasar_code(string s, int offset) {
	cout << endl << "Please enter the desired offset [0-26]: " << endl;
	cin >> offset;

	if (offset < 0) error("Offset can't be negative!");
	if (offset > 26) error("Offset too large!"); //Offset > 26 doesnt make sense, alphabet only has 26 letter and thus only 26 offsets make sense
	for (int i = 0; i < s.length(); ++i) {
		s[i] += offset; //Offsets each letter by the desired amount
		if (s[i] > 90) s[i] -= 26; //If the offset passes the char 'Z' it continues at char 'A'
	}
	
	return s;
}

void output_text(string s, int block_size, char delimeter) {
	cout << endl << "Please enter the desired block size folowed by the delimiter: " << endl;
	cin >> block_size >> delimeter;
	if (block_size <= 0) error("Block size can't be negative or zero");
	
	vector<string> split_in_block;
	for (int i = 0; i < s.length();  i += block_size) {
		split_in_block.push_back(s.substr(i, block_size)); //Makes a vector containing 1 block per index
	}
	
	cout << endl << "Your super secret spy code is: " << endl;

	int total_del = split_in_block.size() - 1;
	for (int i = 0; i < split_in_block.size(); ++i) { //Posts a block followed by a delimeter
		cout << split_in_block[i]; 
		if (total_del > 0) {
			cout << delimeter;
			total_del -= 1; //Makes sure the last block isn't followed by a delimeter
		}
	}

	cout << endl;
}

int main()
try {
	int offset = 0;
	int block_size = 0;
	char delimeter = ' ';

	string text = read_text();
	text = string_to_upper(text);
	text = ceasar_code(text, offset);
	output_text(text, block_size, delimeter);

	system("pause");
	return 0;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl << endl;
	system("pause");
	return 1;
}
catch (...) {
	cerr << "Unknown exception!\n"; \
		system("pause");
	return 2;
}
