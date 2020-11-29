// LambdaCaptureExpressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void f(int* p)
{
	*p = 1;
}
int main()
{
	int a = 3;
	int b = 10;
	int c = 222;

	// capture "a" by value
	[a](){cout << a << endl; }();

	//capture a by reference. We can modify its value.
	[&a]() { a = 33; cout << a << endl; }();

	
	// default capture all local variables by value.
	[=]() { cout << a <<" "<< b <<endl; }();

	// default capture all local variables by value, but capture "c" by reference
	[=, &c]() { cout << a << " " << b << endl; c = 4000; cout << c << endl; }();

	// default capture all local variables by reference.
	[&]() {a = 1000; b = 2000; c = -222; cout << a << " " << b << c << endl; }();

	// default capture all local variables by reference, but capture "a" by value
	[&, a]() { b = 2000; c = -222; cout << a << " " << b << c << endl; }();

	int* p;
	p = nullptr;

	int* p2 = nullptr;
	int* p3 = new int(44);

	bool x = (((p) && (*p2 == 0)) || p3);

	return 0;
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
