// AutoKeyword.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>

using namespace std;

template <class T, class S>
auto test(T value1, S value2) -> decltype(value1 + value2)
{
    return value1 + value2;
}

int get()
{
    return 99;
}

auto test2() -> decltype(get())
{
    return get();
}

template<class T, class S>
auto test3(T val1, S val2) -> decltype(val1)
{
    return val1 + val2;
}

int main()
{
    cout << test(50, 100) << endl;
    cout << test2() << endl;

    auto a = 5.5;
    a = 22.22;
    cout << a << endl;

    auto x = 10.5;
    auto y = 5;
    cout << fixed << setprecision(2) << test3(x, y) << endl;
    cout << fixed << setprecision(2) << test3(y, x) << endl;

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
