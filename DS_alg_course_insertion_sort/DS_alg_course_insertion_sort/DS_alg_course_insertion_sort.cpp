// DS_alg_course_insertion_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<vector>

using namespace std;

void insertionSort(vector<int>& v)
{
  int len = v.size();
  int k = 0;

  while (k < len - 1)
  {
    for (int j = k + 1; j > 0; --j)
    {
      if (v[j] < v[j - 1])
      {
        swap(v[j], v[j - 1]);
      }
      else
      {
        break;
      }
    }
    ++k;
  }
}

int main()
{
  vector<int> v{ 6,5,3,1,8,7,2,4 };
  insertionSort(v);

  for (auto it : v)
  {
    cout << it << " ";
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
