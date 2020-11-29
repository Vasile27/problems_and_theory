// ObjectSlicingAndPolymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Parent
{
    int one;
public:

    Parent() :one(1)
    {
        cout << "parent def constr" << endl;
    }

    Parent(const Parent& other)
    {
        cout << "copy parent" << endl;
        one = other.one;
    }

    virtual void print()
    {
        cout << "print parent" << endl;
    }

    virtual ~Parent()
    {
        cout << "Destr parent" << endl;
    }
};

class Child : public Parent
{
    int two;
public:
    Child() : two(2)
    {
        cout << "Child def constr" << endl;
    }

    Child(const Child& other)
    {
        cout << "Child copy constr" << endl;
        two = other.two;
    }

    void print()
    {
        cout << "print child" << endl;
    }

    ~Child()
    {
        cout << "Child destructor" << endl;
    }

};

int main()
{
    string line = "--------------------------";
    // parent def constr
    // child def constr
    Child c1;
    Parent& p1 = c1;
    // print child
    p1.print();

    cout << line << endl;

    // Uses copy constructor
    // parent def constr
    // child def constr
    // parent copy constr
    //Parent p2 = Child();
    // child destructor 
    // parent destructor 
    // print parent
    //p2.print();
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
