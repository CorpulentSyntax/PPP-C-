//Dit programma voert de eerst ingevoerde operatie uit op de 2 ingevoerde double floating-point getallen
#include "std_lib_facilities.h"

int main() {
	double val1 = 0.0;
	double val2 = 0.0;
	string operation;
	cout << "Please input an operation (+, -, *, /, plus, minus, mul, div) followed by 2 values (use . when using decimals): ";	//Voer een operation (+ - * / plus minus mul div) in gevolgd door 2 double values 
	cin >> operation; 
	cin >> val1 >> val2;
	
	if (operation == "+" || operation == "plus") {																//Als de operation + of plus is dan is de output val1 + val2
		cout << "Sum = " << val1 + val2 << "\n";
	}
	else if (operation == "-" || operation == "minus") {														//Als de operation - of minus is dan is de output val1 - val2
		cout << "Minus = " << val1 - val2 << "\n";
	}
	else if (operation == "*" || operation == "mul") {															//Als de operation * of mul is dan is de output val1 * val2
		cout << "Product = " << val1 * val2 << "\n";
	}
	else if (operation == "/" || operation == "div") {															//Als de operation / of div is dan is de output val1 / val2
		cout << "Division = " << val1 / val2 << "\n";
	}
	else {
		cout << "Invalid operator input, correct syntax is +, -, *, /, plus, minus, mul or div.\nPlease restart the program and try again.\n";
	}
	
	system("pause");																							
	return 0;
}
