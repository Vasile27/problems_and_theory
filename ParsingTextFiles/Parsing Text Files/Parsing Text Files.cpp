// Parsing Text Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int work()
{
    ifstream input;
    //string filename = "C:\Users\Vasi\source\repos\Parsing Text Files\stats.txt";
    string filename = "stats.txt";

    input.open(filename);

    if (!input.is_open())
    {
        cout << "Could not open file...exit" << endl;
        return 1;
    }

    while (input)
    {
        string line;

        getline(input, line, ':');

        int population;
        input >> population;

        // used to remove the new line character
        // 'Population UK' -- '6400000'
        //    '
        //    Population France' -- '6640000'
        //    '
        //input.get();

        //read white spaces.
        input >> ws;

        //if (!input)
        //{
        //    break;
        //}

        cout << "'" << line << "'" << " -- '" << population<< "'" << endl;
    }

    input.close();

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
