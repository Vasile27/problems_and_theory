// cache_LRU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<unordered_map>

using namespace std;

#define CACHE_MAX_SIZE 5

class CacheLRU
{
private:
  list<int> cache;
  unordered_map<int, list<int>::iterator> cacheHashMap;
  int size;

  void insert(int value)
  {
    if (size == CACHE_MAX_SIZE)
    {
      int first = cache.front();
      remove();
      cacheHashMap.erase(first);
    }
    ++size;
    cache.push_back(value);
    list<int>::iterator it = cache.end();
    it--;
    cacheHashMap[value] = it;
  }
  void remove()
  {
    cache.pop_front();
    --size;
  }
public:
  CacheLRU() : size{ 0 }, cache{}, cacheHashMap{} {}
  bool find(int value)
  {
    auto it = cacheHashMap.find(value);
    if (it != cacheHashMap.end())
    {
      list<int>::iterator listIt = it->second;
      cout << "Element " << *listIt << " is found" << endl;
      remove();
    }
    insert(value);
    return true;
  }
  void print()
  {
    for (auto it = cache.begin(); it != cache.end(); ++it)
    {
      cout << *it << " ";
    }
    cout << endl;
  }
};

int main()
{
  CacheLRU cache;
  cache.find(5);
  cache.find(6);
  cache.find(7);
  cache.find(8);
  cache.find(9);
  cache.print();
  cache.find(10);
  cache.print();

  cache.find(10);

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
