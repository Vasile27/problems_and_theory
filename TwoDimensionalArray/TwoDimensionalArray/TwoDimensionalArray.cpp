// TwoDimensionalArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

void work()
{
    // create a matrix 3X4 where all elements have value 7
    vector< vector <int> > grid(3, vector<int>(4, 7));

    int nr = 1;
    for (int row = 0; row < grid.size(); ++row)
    {
        for (auto it_col = grid[row].begin(); it_col != grid[row].end(); ++it_col)
        {
            *it_col = nr;
            nr++;
        }
    }

    for (int row = 0; row < grid.size(); ++row)
    {
        for (auto it_col = grid[row].begin(); it_col != grid[row].end(); ++it_col)
        {
            cout << *it_col << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (auto it = grid.begin(); it != grid.end(); ++it)
    {
        for (int col = 0; col < (*it).size(); col++)
        {
			cout << (*it)[col] << " ";
        }

        cout << endl;
    }

    cout << endl;

    for (auto it = grid.begin(); it != grid.end(); ++it)
    {
        for (auto it_col = it->begin(); it_col != it->end(); ++it_col)
        {
			cout << *it_col << " ";
        }

        cout << endl;
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
