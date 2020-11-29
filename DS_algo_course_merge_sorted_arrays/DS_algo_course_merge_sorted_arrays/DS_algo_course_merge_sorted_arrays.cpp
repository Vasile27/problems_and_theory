// DS_algo_course_merge_sorted_arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

vector<int> mergeSortedArrays(vector<int> a, vector<int> b)
{
    int aLen = a.size();
    int bLen = b.size();
    int cLen = aLen + bLen;
    vector<int>c(cLen, 0);

    int i = 0;
    int j = 0;
    int k = 0;

    if (aLen == 0)
    {
        return b;
    }
    
    if (bLen == 0)
    {
        return a;
    }

    while (i < aLen && j < bLen)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            ++i;
        }
        else
        {
            c[k] = b[j];
            ++j;
        }
        ++k;
    }

    while (i < aLen)
    {
        c[k] = a[i];
        ++k;
        ++i;
    }

    while (j < bLen)
    {
        c[k] = b[j];
        ++k;
        ++j;
    }

    return c;
}

int main()
{
    vector<int> a{ 0, 3, 4, 31 };
    vector<int> b{ 4,6,30 };
    vector<int> c = mergeSortedArrays(a, b);

    for (vector<int>::iterator it = c.begin(); it != c.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
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
