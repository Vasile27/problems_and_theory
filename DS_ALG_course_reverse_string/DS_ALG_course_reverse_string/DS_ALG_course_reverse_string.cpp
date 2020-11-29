// DS_ALG_course_reverse_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class A
{
public:
	int x;
	A() :x(100) {}
	~A() {}
	int getData() { return x; }

};

class B
{
public:
	int y;
	A objA;
	B() :y(100), objA{} {}
	~B() {}
	int getData() const { return (const_cast<A&>(objA)).getData(); }

};

void reverseString(string& s)
{
	int len = s.length();

	if (len < 2)
	{
		return;
	}

	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		++i;
		--j;
	}
}

int main()
{
	string a = "Hi my name is Andrei";
	reverseString(a);
	cout << a << endl;

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
