#include "std_lib_facilities.h"
#include "Complex.h"
#include <iostream>

int real1 = 0;
int real2 = 0;
int imag1 = 0;
int imag2 = 0;

void input_function1() {//input function for the first Complex function
	cout << "Please input the first real value: ";
	cin >> real1;
	cout << "Please input the first imaginairy value: ";
	cin >> imag1;
}

void input_function2() {//input function for the second Complex function
	cout << endl << "Please input the second real value: ";
	cin >> real2;
	cout << "Please input the second imaginairy value: ";
	cin >> imag2;
}

int main() {
	
	input_function1();
	Complex z_1(real1, imag1); //initializes the first Complex function
	cout << "z_1 = " << z_1;

	input_function2();
	Complex z_2(real2, imag2);//initializes the second Complex function
	cout << "z_2 = " << z_2;

	Complex z_3;

	z_3 = z_1 + z_2;  //Uses operand '+' to sum z_1 and z_2
	cout << endl << endl << "z_1 + z_2 = " << z_3;

	z_3 = z_1 - z_2; //Uses operand '-' to substract z_1 and z_2
	cout << endl << "z_1 - z_2 = " << z_3;
	
	z_3 = z_1 * z_2; //Uses operand '*' to multiply z_1 and z_2
	cout << endl << "z_1 * z_2 = " << z_3;

	z_3 = -z_1; //Uses operand '-' to negate z_1
	cout << endl << "-z_1 = " << z_3;

	z_3 = -z_2; //Uses operand '-' to negate z_2
	cout << endl << "-z_2 = " << z_3 << endl;

	system("pause");
	return 0;
}
