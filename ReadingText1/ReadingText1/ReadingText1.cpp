// ReadingText1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void work()
{
    ifstream inFile;
    ofstream outFile;
    string fileName = "text.txt";


    outFile.open(fileName);

    if (outFile.is_open())
    {
        
        cout << "Opened file " << fileName << " for writing" << endl;

        for (int i = 0; i < 3; ++i)
        {
            outFile << "This is line" + to_string(i) << endl;
        }

        outFile.close();
    }

    inFile.open(fileName);

    if (inFile.is_open())
    {
        cout << "Opened file " << fileName << " for reading" << endl;

        string line;

        // Merge si sa folosesti while(inFile) deoarce operatorul "!" este supraincarcat
        // deci defapt while(inFile) ruleaza niste cod in spate.
        while (!inFile.eof())
        {
            getline(inFile, line);
            cout << line << endl;
        }

        inFile.close();
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
