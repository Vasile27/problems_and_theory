// FunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string test(int a, string& b, float c)
{
    stringstream stream;

    // fixed: sets the floatfield format flag for the str stream to fixed.
    // when floatfield is set to fixed, floating-point values are written using fixed-point notation.
    // the value is represented with exactly as many digits in the decimal part as specified
    // by the precision field (precision) and with no exponent part.
    stream << fixed << setprecision(2) << c;
    return (b + " " + to_string(a) + " " + stream.str());
}

int main()
{
    string name = "Vasile";
    cout << test(27, name, 1.2) << endl;

    // declare pointer to the function test
    string(* p_test)(int, string&, float) = test;
    string name_2 = "Maria";

    // sunt la fel.
    cout << (*p_test)(26, name_2, 1.5) << endl;
    cout << p_test(26, name_2, 1.5) << endl;


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
