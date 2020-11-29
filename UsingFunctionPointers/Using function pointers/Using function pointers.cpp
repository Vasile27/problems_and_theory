// Using function pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool match(string& test)
{
    return size(test) == 3;
}

int count_elem(vector<string>& vect, bool (*match)(string& elem))
{
    int count = 0;
    for (vector<string>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        if (match(*it))
        {
            count++;
        }
    }
    return count;
}

void work()
{
    vector<string> elements;
    elements.push_back("one");
    elements.push_back("four");
    elements.push_back("ten");
    elements.push_back("twenty");
    elements.push_back("three");
    elements.push_back("six");
    elements.push_back("nin");
    elements.push_back("one hundred");

    cout << count_if(elements.begin(), elements.end(), match) << endl;

    cout << count_elem(elements, match);
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
