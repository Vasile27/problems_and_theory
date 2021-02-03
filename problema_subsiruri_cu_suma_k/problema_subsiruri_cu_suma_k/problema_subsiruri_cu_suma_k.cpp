// problema_subsiruri_cu_suma_k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <unordered_map>

using namespace std;

void work(vector<int> &v, int sum)
{
  unordered_map<int, int> umap;
  int partialSum = 0;
  for (int i = 0; i < v.size(); ++i)
  {
    partialSum += v[i];
    if (partialSum == sum)
    {
      cout << "Found subarray between " << 0 << " " << i << endl;
      return;
    }
    if (umap.find(partialSum - sum) != umap.end())
    {
      cout << "Found subarray between " << umap[partialSum - sum] + 1 << " " << i << endl;
      return;
    }
    umap[partialSum] = i;
  }
  cout << "Did not found subarray" << endl;
}
int main()
{
  vector<int> v{1, 4, 20, 3, 10, 5};
  int sum = 33;
  work(v, sum);
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
