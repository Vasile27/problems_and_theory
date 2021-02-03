// DS_alg_course_merge_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

void merge(vector<int>& v, int left, int middle, int right)
{
  int n1 = middle - left + 1;
  int n2 = right - middle;

  vector<int> v1(n1, 0);
  vector<int> v2(n2, 0);

  for (int i = 0; i < n1; ++i)
  {
    v1[i] = v[left + i];
  }

  for (int i = 0; i < n2; ++i)
  {
    v2[i] = v[middle + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2)
  {
    if (v1[i] < v2[j])
    {
      v[k] = v1[i];
      ++i;
    }
    else
    {
      v[k] = v2[j];
      ++j;
    }
    ++k;
  }

  while (i < n1)
  {
    v[k] = v1[i];
    ++i;
    ++k;
  }

  while (j < n2)
  {
    v[k] = v2[j];
    ++j;
    ++k;
  }
}

void mergeSort(vector<int>& v, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  int m = (left + right) / 2;

  mergeSort(v, left, m);
  mergeSort(v, m+1, right);
  merge(v, left, m, right);
}

int main()
{
  vector<int> v{ 5,4,3,2,1,0, -400, 222, 41, 42 };
  mergeSort(v, 0, v.size() - 1);
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
