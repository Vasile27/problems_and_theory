// Custom_objects_as_map_values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person
{

public:

	int age;
	string name;

	Person() : age(0), name(" ")
	{
		cout << "Default constr" << endl;
	}

	Person(int age, string name) : age(age), name(name)
	{
		cout << "Parameter constr" << endl;
	}

	Person& operator = (const Person& p)
	{
		cout << "Assigment operator" << endl;
		return *this;
	}

	Person(const Person& other)
	{
		cout << "Copy constructor" << endl;
		name = other.name;
		age = other.age;
	}

	void print() const
	{
		cout << name << " " << age << endl;
	}
};

void work()
{
	map<int, Person> persons;

	//Person vas(28, "Vas");
	//Person vas2;
	string line{ "--------------------------------------" };

	// Se construieste obiectul persons[0] folosind default constr
	// Apoi este folosit operator = pentru a-i da valorile obiectului care a fost construit cu constr cu parametri
	//Se apeleaza Constr cu parametri, Constr def, operator =
	persons[0] = Person(20, "John");
	cout << line << endl;

	// Se apeleaza Constr cu parametri, Constr copiere, Constr Copiere
    // La insert nu se creaza un obiect cu constr default. Este folosit constr de copiere pt a crea noul obiect.
	persons.insert(pair<int, Person>(1, Person(5, "Ana")));
	cout << line << endl;

	// Aici nu se apeleaza constr default, deci in pair nu se creaza un obiect cu def constr
	// Se apeleaza constr cu parametri si este folosit constr de copiere pentru a crea obiectul Person in pair.
	pair<int, Person> om(2, Person(10, "Ela"));

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
