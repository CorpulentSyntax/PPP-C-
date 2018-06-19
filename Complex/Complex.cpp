#include "Complex.h"
#include "std_lib_facilities.h"
#include <iostream>

// Default Complex constructor
Complex::Complex()
{

}

//Allows you to declare and initialize a Complex function (constructor) 
Complex::Complex( int real, int imag) 
{
	this->real = real;
	this->imag = imag;
}

//Change the real value of the Complex function
void Complex::setReal(int real)
{
	this->real = real;
}

//Change the imaginairy value of the Complex function
void Complex::setImag(int imag)
{
	this->imag = imag;
}

//Gets the real value of the Complex function to be assigned to a variable
int Complex::getReal(void)
{
	return this->real;
}

//Gets the imaginairy value of the Complex function to be assigned to a variable
int Complex::getImag(void)
{
	return this->imag;
}

//Overloads '+' operator to be used for summation of two Complex functions 
// ** example: z_3 = z_1 + z_2
Complex Complex::operator +(const Complex& function) const {
	Complex result(real + function.real, imag + function.imag);
	return result;
}

//Overloads '-' operator to be used for substraction of two Complex functions 
// ** example: z_3 = z_1 - z_2
Complex Complex::operator -(const Complex& function) const {
	Complex result(real - function.real, imag - function.imag);
	return result;
}

//Overloads '*' operator to be used for multiplication of two Complex functions following mathematical rules
// ** example: z_3 = z_1 * z_2
Complex Complex::operator *(const Complex& function) const {
	int newReal = real * function.real - imag * function.imag;
	int newImag = real * function.imag + imag * function.real;
	Complex result(newReal, newImag);
	return result;
}

//Overloads the '-' operator to be used to negate a Complex function
// ** example: z_3 = -z_1
Complex Complex::operator -(void) {
	real = -real;
	imag = -imag;
	return Complex(real, imag);
}

//Overload the ostream operator for use with Complex functions
ostream& operator<<(ostream& os, const Complex& function)
{
	if (function.real == 0 && function.imag == 0) os << "0";
	else if (function.real != 0 && function.imag == 0) os << function.real;
	else if (function.real == 0 && function.imag != 0) os << function.imag << "i";
	else if (function.real != 0 && function.imag > 0) os << function.real << "+" << function.imag << "i";
	else if (function.real != 0 && function.imag < 0) os << function.real << function.imag << "i";
	return os;
}
