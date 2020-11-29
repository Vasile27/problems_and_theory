// Overloading_the_left_bitwise_operator_for_printing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Test
{
	int id;
	string name;

public:
	Test(int id, string name) :id(id), name(name) {}

	Test(const Test& other)
	{
		id = other.id;
		name = other.name;
	}

	Test& operator=(const Test& other)
	{
		id = other.id;
		name = other.name;
		return *this;
	}

	// method that handles the printing.
	ostream& print(ostream& out) const
	{
		out << id << ": " << name;
		return out;
	}

};

// overload << operator for Test class.
// all operations will be performed by t's print method.

ostream& operator<<(ostream& out, const Test& t)
{
	return t.print(out);
}

class Test2
{
	int id;
	string name;
	int age;

public:
	Test2(int id, string name, int age) :id(id), name(name), age(age) {}

	Test2(const Test2& other)
	{
		id = other.id;
		name = other.name;
		age = other.age;
	}

	Test2& operator=(const Test2& other)
	{
		id = other.id;
		name = other.name;
		age = other.age;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Test2& t2);

};

ostream& operator<<(ostream& out, const Test2& t2)
{
	out << t2.id << " " << t2.name << " " << t2.age;
	return out;
}

void work()
{
	Test t1(10, "Vasile");

	// operator<<(operator<<(cout, t1), endl) <- operator << seen as function call.
	// because its first argument is not of the type of our class we can't just declare the operator
	// as a member function.
	// Other solution involve defining getters for the private members and using them in the operator function
	// or declaring the operator function as a friend of Test to be able to use the private members.
	// See class T2 implementation.
	cout << t1 << endl;

	Test2 t2(20, "Vasile", 27);
	cout << t2 << endl;
}

int main()
{
	work();
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
