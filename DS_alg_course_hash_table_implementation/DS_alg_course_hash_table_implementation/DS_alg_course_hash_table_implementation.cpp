// DS_alg_course_hash_table_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<list>

using namespace std;

class HashTable
{
public:
  int data_size;
  // [ [], [[key1, val1], [key2, val2]], [] ]
  // addr0  addr1: we can have colissions so we need to store multiple
  // results in the same address
  // so we will have a vector simulating the memory
  // a list of pairs to simulate the multiple entries. We need to store key
  // and value.
  vector< list< pair<string, int> > > data;
  HashTable(int _size) : data_size{ _size }, data( _size) {}

  int _hash(string key)
  {
    int hash = 0;
    for (int i = 0; i < key.size(); ++i)
    {
      hash = (hash + int(key[i]) * i) % data_size;
    }

    return hash;
  } // good implementations are very fast --> O(1)

  void set(string key, int value)
  {
    int hash_key = _hash(key);
    data[hash_key].push_back(make_pair(key, value));
  } // O(1)

  int  get(string key)
  {
    int hash_key = _hash(key);
    list<pair<string, int>> values = data[hash_key];
    int result = 0;
    for (auto it = values.begin(); it != values.end(); ++it)
    {
      if (it->first == key)
      {
        result = it->second;
        break;
      }
    }
    return result;
  } // if not collision --> O(1). Can become O(n)

  vector<string> keys()
  {
    vector<string> rtKey;
    for (auto it = data.begin(); it != data.end(); ++it)
    {
      if (!it->empty())
      {
        for (auto listIt = it->begin(); listIt != it->end(); ++listIt)
        {
          rtKey.push_back(listIt->first);
        }
      }
    }
    return rtKey;
  }
};

int main()
{
  HashTable hash_table(50);
  hash_table.set("grapes", 10000);
  hash_table.set("apples", 54);
  hash_table.set("oranges", 2);
  vector<string> keys = hash_table.keys();
  for (int i = 0; i < keys.size(); ++i)
  {
    cout << keys[i] << endl;
  }

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
