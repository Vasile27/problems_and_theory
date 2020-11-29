// Overloading_assigment_operator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    int id;
    char* name;
    int name_size;

    Test() :id(0), name(nullptr), name_size(0) {}

    Test(int id, string name_s):id(id)
    {
        name_size = name_s.size();

        //name = new char(name_size); allocates on char initialized to name_size.
        // allocate an array of chars of size name_size.
        name = new char[name_size];
        for (int i = 0; i < name_size; ++i)
        {
            name[i] = name_s[i];
        }
    }

    ~Test()
    {
        delete[] name;
    }

    Test(const Test& other)
    {
        delete[] name;

        name = new char[other.name_size];

        memcpy(name, other.name, other.name_size);

        id = other.id;
        name_size = other.name_size;
    }

    void print()
    {
        cout << id << " ";
        for (int i = 0; i < name_size; ++i)
        {
            cout << name[i];
        }
        cout << endl;
		string line = "-----------------------";
        cout << line << endl;
    }

    void change_name(string new_name)
    {
        delete[] name;
        name_size = new_name.size();
        name = new char[name_size];
        for (int i = 0; i < name_size; ++i)
        {
            name[i] = new_name[i];
        }
    }

    Test& operator=(const Test& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] name;

        name = new char[other.name_size];

        memcpy(name, other.name, other.name_size);

        id = other.id;
        name_size = other.name_size;
    }

};

void work()
{
    Test test1(10, "Vasile");
    test1.print();

    Test test2 = test1;
    test2.print();

    test1.change_name("Alina");
    test1.print();
    test2.print();

    Test test3;
    test3 = test1;
    test3.print();
    test1.change_name("Georgiana");
    test1.print();
    test3.print();
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
