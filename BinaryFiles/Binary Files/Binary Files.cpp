// Binary Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>

using namespace std;

#pragma pack(push, 1)
struct Person
{
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int work() {
    Person someone = { "Frodo", 220, 0.8 };

    ofstream output;
    string fileName = "test.bin";
    ifstream input;

    output.open(fileName, ios::binary);

    if (output.is_open())
    {
        output.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        output.close();
    }
    else
    {
        cout << "Could not open file for writing " << fileName << endl;
        return 1;
    }

    input.open(fileName, ios::binary);

    if (input.is_open())
    {
        Person someoneElse;
        input.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        input.close();

        cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;
    }
    else
    {
        cout << "Could not open file for reading " << fileName << endl;
        return 1;
    }

    return 0;

 }

int main()
{
    return work();
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
