#pragma once
#ifndef  _COMPLEX_HEADER
#define _COMPLEX_HEADER

#include<iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imaginary;

public:

	static int  destroy_counter;

	Complex() :real(0), imaginary(0) {}

	Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

	Complex(const Complex& other);

	~Complex();

	Complex& operator=(const Complex& other);

	ostream& print(ostream& out) const;

	//Complex operator+(const Complex& a)
	//{
	//	cout << "Plus operator" << endl;
	//	Complex res;
	//	res.real = real + a.real;
	//	res.imaginary = imaginary + a.imaginary;
	//	return res;
	//}

	double get_real() const;


	double get_imaginary() const;

	bool operator<(const Complex& a);

	bool operator ==(const Complex& other);

	bool operator !=(const Complex& other);

	Complex operator*();

};

ostream& operator<<(ostream& out, const Complex& c);

Complex operator+(const Complex& a, const Complex& b);

Complex operator+(const Complex& a, double d);

Complex operator+(double d, const Complex& a);

#endif // ! _COMPLEX_HEADER

