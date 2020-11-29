// duplicate_zeros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "duplicate_zero.hpp"

using namespace std;

void duplicateZeros(vector<int>& arr)
{
    int num_of_zeros = 0;
    int poz = arr.size() - 1;
    int last = 0;
    int count = 0;

    for (last = 0; last < arr.size(); ++last)
    {
        if (arr[last] == 0)
        {
            count += 2;
            num_of_zeros++;

			if (count == arr.size())
			{
				break;
			}
			else if (count > arr.size())
			{
				arr[poz] = 0;
                poz--;
                last--;
                break;
			}
        }
        else
        {
            count++;
			if (count == arr.size())
			{
				break;
			}
        }
    }

    for (int j = last; j >= 0; j--)
    {
        if (arr[j] == 0)
        {
            arr[poz] = arr[j];
            poz--;
            arr[poz] = arr[j];
            poz--;
        }
        else
        {
            arr[poz] = arr[j];
            poz--;
        }
    }
}


int main()
{
    //vector<int> v{ 8,4,5,0,0,0,0,7};
    //for (int i = 0; i < v.size(); ++i)
    //{
    //    cout << v[i] << " ";
    //}
    //cout << endl;

    //duplicateZeros(v);

    //for (int i = 0; i < v.size(); ++i)
    //{
    //    cout << v[i] << " ";
    //}
    //cout << endl;
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
