// Complex_number_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Complex.hpp"

using namespace std;

int Complex::destroy_counter = 0;

Complex::Complex(const Complex& other)
{
	cout << "Copy constructor" << endl;
	real = other.real;
	imaginary = other.imaginary;
}

Complex::~Complex()
{
	destroy_counter++;
	cout << "Destructor called " << destroy_counter<<" times"<< endl;
}

Complex& Complex::operator=(const Complex& other)
{
	if (this == &other)
	{
		return *this;
	}
	cout << "Assigment operator" << endl;
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

ostream& Complex::print(ostream& out) const
{
	out << real << " + " << imaginary << "i";
	return out;
}

//Complex operator+(const Complex& a)
//{
//	cout << "Plus operator" << endl;
//	Complex res;
//	res.real = real + a.real;
//	res.imaginary = imaginary + a.imaginary;
//	return res;
//}

double Complex::get_real() const
{
	return real;
}


double Complex::get_imaginary() const
{
	return imaginary;
}

bool Complex::operator<(const Complex& a)
{
	if (real == a.real)
	{
		return imaginary < a.imaginary;
	}

	return real < a.real;
}

bool Complex::operator==(const Complex& other)
{
	cout << "== operator" << endl;
	return ((real == other.real) && (imaginary == other.imaginary));
}

bool Complex::operator!=(const Complex& other)
{
	cout << "!= operator" << endl;
	return !(*this == other);
}

Complex Complex::operator*()
{
	return Complex(real, -imaginary);
}

ostream& operator<<(ostream& out, const Complex& c)
{
	return c.print(out);
}

Complex operator+(const Complex& a, const Complex &b)
{
	cout << "plus operator" << endl;
	return Complex(a.get_real() + b.get_real(), a.get_imaginary()+b.get_imaginary());
}

Complex operator+(const Complex& a, double d)
{

	cout << "plus operator 2" << endl;
	return Complex(a.get_real() + d, a.get_imaginary());
}

Complex operator+(double d, const Complex& a)
{

	cout << "plus operator 3" << endl;
	return Complex(d+ a.get_real(), a.get_imaginary());
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
