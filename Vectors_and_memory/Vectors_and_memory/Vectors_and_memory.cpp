// Vectors_and_memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;


void work()
{
    vector<int> numbers(0);

    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for (int i = 0; i < 10000; i++)
    {
        if (numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
			cout << "Size: " << numbers.size() << endl;
        }

        numbers.push_back(i);
    }

    int* p = &numbers[101];
    numbers.resize(100);
    cout << "Numbers[2]: " << numbers[2] << endl;
    cout << "Numbers[101]: " << *p<< endl;
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
