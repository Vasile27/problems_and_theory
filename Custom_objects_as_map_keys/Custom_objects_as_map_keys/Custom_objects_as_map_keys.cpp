// Custom_objects_as_map_keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>
#include<string>

using namespace std;

class Person
{
public:
    string name;
    int age;

    Person() : name(""), age(0)
    {
        cout << "Default constr" << endl;
    }

    Person(string name, int age) : name(name), age(age)
    {
        
        cout << "Constr parametri" << endl;
    }

    Person(const Person& other)
    {
        name = other.name;
        age = other.age;
    }

    Person & operator = (const Person& other)
    {
        name = other.name;
        age = other.age;

        return *this;
    }

    void print() const
    {
        cout << name << " " << age << endl;
    }

    bool operator < (const Person& other) const
    {
        if (name == other.name)
        {
            return name < other.name;
        }
        
        return name < other.name;
    }
};

void work()
{
    map<Person, int>people;

    people[Person("Vas", 27)] = 27;

    for (map<Person, int>::iterator it = people.begin(); it != people.end(); ++it)
    {
        cout << it->second << ": " << flush;

        // Function print must be const function because the object which are keys in the map
        // are actually const objects. They cannot be changed because they are keys.
        // We cannot call a non-const function from a const object.
        it->first.print();
    }

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
