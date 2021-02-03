// Ds_alg_course_dynamic_programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>

using namespace std;

unsigned long fiboDP(int n)
{
  static unordered_map<int, int> umap;
  static int count = 0;

  count++;
  cout << "FiboDB count " << count << endl;
  if (umap.find(n) != umap.end())
  {
    return umap[n];
  }
  else
  {
    if (n < 2)
    {
      return n;
    }
    umap[n] = fiboDP(n - 1) + fiboDP(n - 2);
    return umap[n];
  }
}

int main()
{
  cout << fiboDP(100) << endl;
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
