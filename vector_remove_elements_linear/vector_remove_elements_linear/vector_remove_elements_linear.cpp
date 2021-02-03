// vector_remove_elements_linear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

void work(vector<int> &v, int elem)
{
  int len = v.size();
  bool swapMade = false;
  if (!len)
  {
    return;
  }
  int slowP = 0;
  int fastP = 0;
  for (int i = 0; i < len; ++i)
  {
    if (v[i] > elem)
    {
      slowP = i;
      break;
    }
  }

  fastP = slowP + 1;
  while (fastP < len)
  {
    if (v[slowP] > elem)
    {
      while (fastP < len - 1 && v[fastP] > elem)
      {
        fastP++;
      }
      if (fastP == len - 1 && v[fastP] > elem)
      {
        break;
      }
      swapMade = true;
      swap(v[slowP], v[fastP]);
    }
    slowP++;
    fastP++;
  }
  if (swapMade)
  {
    v.resize(slowP);
  }
}

int main()
{
  vector<int> v{ 1, 11, 21, 31 };
  work(v, 40);
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
