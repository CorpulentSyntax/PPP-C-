#include "std_lib_facilities.h"
#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private: 
	int real = 0; //Variables used in the Comples class
	int imag = 0;

public:
	Complex(void); //default constructor
	Complex(int real, int imag); //constructor for the Complex values
	
	//All functions used in the Complex class
	void setReal(int real);
	void setImag(int imag);
	int getReal(void);
	int getImag(void);
	Complex operator +(const Complex& function) const;
	Complex operator -(const Complex& function) const;
	Complex operator *(const Complex& function) const;
	Complex operator -(void); 

	friend ostream& operator<<(ostream& os, const Complex& function);
};

#endif COMPLEX_H
