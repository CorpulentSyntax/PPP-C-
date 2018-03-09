//Dit programma geeft weer of de ingevoerde integer even of oneven is
#include "std_lib_facilities.h";

int main() {						
	int val1 = 0;
	cout << "Please input a value: ";
	cin >> val1;

	if (remainder(val1,2) == 0) {				//Als val1 / 2 = 0 dan is het getal even
		cout << "The value " << val1 << " is even.\n";
	}
	else {							//Als val1 / 2 != 0 dan is het getal oneven
		cout << "The value " << val1 << " is odd.\n";
	}

	system("pause");											
	return 0;
}
