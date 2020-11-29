// Stack_and_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<queue>

using namespace std;

class Person
{
public:
	string name;
	static int destroy_counter;

	Person() :name("")
	{
		cout << "Default constr" << endl;
	}

	Person(string name) :name(name)
	{
		cout << "Parameter constr" << endl;
	}

	~Person()
	{
		destroy_counter++;
		cout << "Destructor called" << " "<<destroy_counter<< endl;
	}

	Person(const Person& other)
	{
		cout << "Copy constr" << endl;
		name = other.name;
	}

	Person& operator =(const Person& other)
	{
		cout << "Operator =" << endl;
		name = other.name;
		return *this;
	}

	void print()
	{
		cout << name << endl;
	}
	
};

int Person::destroy_counter = 0;

void work()
{
	string line = "---------------------------------";
	Person per1("Ana");
	// Copy constructor
	Person per2 = per1;

	// Per1 is Ana. Per2 is Ana.
	per1.print();
	per2.print();

	cout << line << endl;
	per1.name = "Elena";

	// Per1 is Elena.
	// Per2 is Ana.
	per1.print();
	per2.print();

	cout << line << endl;
	// Default constructor.
	Person per3;
	per3.print();
	// Assigment operator.
	per3 = per2;
	// Prints Ana.
	per3.print();

	cout << line << endl;

	stack<Person> stiva;

	// Apeluri:
	//		1. Constructor cu parametri pentru a crea obiectul temporar
	//		2. Constructorul de copiere pentru a crea obiectul in stiva
	//		3. Destructorul care sterge obiectul temporar.
	stiva.push(Person("Ionela"));
	cout << line << endl;
	stiva.push(Person("Alina"));
	cout << line << endl;
	stiva.push(Person("Diana"));

	cout << line << endl;

	// top return reference to Person object
	// Copy constructor is used to create per object from the reference returned
	Person per = stiva.top();

	cout << line << endl;

	// Destructor called
	stiva.pop();

	cout << line << endl;

	// Copy constructor not called because we declared person2 as reference.
	// No copy is done.
	Person& person2 = stiva.top();
	person2.print();
	cout << line << endl;
	// Destructor called
	stiva.pop();

	// Undefined behaviour!!! 
	// person2 is now a reference to a memory area which has been freed.
	// BAD CODE.
	//person2.print();

	cout << line << endl;
	stiva.push(Person("Alina"));
	cout << line << endl;
	stiva.push(Person("Diana"));
	
	cout << line << endl;

	while (stiva.size() > 0)
	{
		Person& person_aux = stiva.top();
		person_aux.print();
		stiva.pop();
		cout << line << endl;
	}

	cout << line << endl;

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
