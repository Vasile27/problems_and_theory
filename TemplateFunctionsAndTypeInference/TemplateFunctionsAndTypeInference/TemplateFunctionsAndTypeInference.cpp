// TemplateFunctionsAndTypeInference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// sau template <typename T>
template <class T>
void print(T obj)
{
    cout << obj << endl;
}

int main()
{
    print<int>(1);

    // in modul in care este definita functia print(T obj) nu trebuie
    // sa specificam intre <> tipul. Se numeste Type Inference.
    // C++ looks at the arguments and infers what type you need.
    print<>(2);
    print(3);

    print<string>("Hello");

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
