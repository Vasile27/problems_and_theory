// Rvalues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Test
{
public:
    int x;

    Test(int value) : x(value) {}

    Test() : x(0) {}

    Test(const Test& other)
    {
        x = other.x;
    }

    int& get_x()
    {
        return x;
    }

    int get_x_by_value()
    {
        return x;
    }

    Test& operator++()
    {
        ++x;

        return *this;
    }

    Test operator++(int)
    {
        Test old(*this);

        ++(*this);

        return old;
    }
};

int main()
{
    Test t1(5);

    int& ref_x = t1.get_x();

    cout << ref_x << endl;

    ++t1;
    cout << t1.x << endl;

    t1++;
    cout << t1.x << endl;


    // Does NOT work because the postfix incrementation operator
    // returns a copy so an Rvalue.
    Test& p1_test = &t1++;


    // Does NOT work because we cannot bind left reference to Rvalue!
    //int& ref_x_2 = t1.get_x_by_value();
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
