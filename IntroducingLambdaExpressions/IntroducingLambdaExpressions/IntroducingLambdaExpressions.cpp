// IntroducingLambdaExpressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void test(void (*pFunc)())
{
	pFunc();
}

void test2(int (*pFunc)(int, int), int a, int b)
{
	cout << pFunc(a, b) << endl;
}

void runDivide(double (*pDivide)(double, double))
{
	auto val = pDivide(322, 41.2);
	cout << val << endl;
}

void f(int **p)
{
	*p = new int(1);
}

int main()
{
	//auto func = []() {cout << "Hello 1" << endl; };
	//func();

	//test(func);

	//test([]() {cout << "Hello 2" << endl; });

	//auto func2 = [](int a, int b) { return a < b ? a : b; };

	//cout << func2(3, 5) << endl;

	//test2(func2, 100, 24);

	//auto divide = [](double a, double b) -> double {
	//	if (b == 0)
	//	{
	//		return 0;
	//	}

	//	return a / b;
	//};

	//cout << divide(9.4, 3.2) << endl;
	//cout << divide(2, 0) << endl;

	//runDivide(divide);
	////runDivide()

	int* p = nullptr;

	f(&p);

	if (p == nullptr)
	{
		cout << "null pointer";
	}
	else
	{
		cout << *p << endl;
	}
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
