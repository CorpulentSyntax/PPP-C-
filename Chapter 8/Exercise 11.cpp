#include "std_lib_facilities.h"

void calculations(int& min, int& max, int& mean, int& median, vector<int> v)
{
	int sum = 0;
	
	min = v[0];
	max = v[v.size() - 1];
	for (int i = 0; i < v.size(); ++i) sum += v[i];
	mean = sum / v.size();
	median = v[v.size() / 2];
}

void print(int& min, int& max, int& mean, int& median) {
	cout << "The min value of the vector is: " << min << endl
		<< "The max value of the vector is: " << max << endl
		<< "The mean of the vector is: " << mean << endl
		<< "The median of the vector is " << median << endl;
}

int main() 
try {
	int nmbr;
	int min = 0;
	int max = 0;
	int mean = 0;
	int median = 0;
	vector<int> v_number;
	vector<int> props;

	cout << "Please enter a series of integers separated by a white-space, end the series with 'q': " << endl;
	while (cin >> nmbr) {
		if (nmbr < 0) error("Negative value entered!"); //Negative values cant be entered
		v_number.push_back(nmbr); //Creates vector of integers
	}
	sort(v_number.begin(), v_number.end()); //Sorts vector from low to high

	calculations(min, max, mean, median, v_number);
	print(min, max, mean, median); //Calls the print function for output

	system("pause");
	return 0;
}

catch (exception& e) {
	cerr << "Error: " << e.what() << endl;
	system("pause");
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	system("pause");
	return 2;
}
