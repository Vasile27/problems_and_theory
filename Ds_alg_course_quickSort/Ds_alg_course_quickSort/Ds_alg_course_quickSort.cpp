// Ds_alg_course_quickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// pivot will be last element in the vector
int partition(vector<int>& v, int low, int high)
{
  int pivot = v[high];
  int smallPoz = low - 1;

  for (int j = low; j < high; ++j)
  {
    if (v[j] < pivot)
    {
      smallPoz++;
      swap(v[j], v[smallPoz]);
    }
  }

  // put pivot in correct position
  swap(v[smallPoz + 1], v[high]);

  //return new position of pivot
  return (smallPoz + 1);
}

void quickSort(vector<int>& v, int low, int high)
{
  if (low < high)
  {
    int pivotPoz = partition(v, low, high);
    quickSort(v, low, pivotPoz-1);
    quickSort(v, pivotPoz + 1, high);
  }
}


int main()
{
  vector<int> v{10, 80,30,90,40,50,70};
  quickSort(v, 0, v.size()-1);
  for (auto it : v)
  {
    cout << it << " ";
  }
  cout << endl;
  return 0;
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
