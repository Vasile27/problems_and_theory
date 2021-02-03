// problema_perechi_suma_k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool work(vector<int> &v, int sum)
{
  unordered_map<int, int> umap;
  bool found = false;
  for (int i = 0; i < v.size(); ++i)
  {
    umap.insert(make_pair(sum-v[i], i));
  }
  for (int i = 0; i < v.size(); ++i)
  {
    if (umap.find(v[i]) != umap.end())
    {
      cout << "Found pair on position " << i << " " << umap[v[i]] << endl;
      // to not show pair a b and b a
      umap.erase(sum-v[i]);
      found = true;
    }
  }

  return found;
}

int main()
{
  vector<int> v{ 13,5,9,4,-2,8,-7,10,-12 };
  int sum = 3;
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
