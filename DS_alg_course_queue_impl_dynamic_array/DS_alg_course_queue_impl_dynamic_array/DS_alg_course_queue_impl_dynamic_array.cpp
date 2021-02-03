// DS_alg_course_queue_impl_dynamic_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;

struct vasQueue
{
  int startPos;
  vector<int> memory;
  vasQueue() :startPos{0} {}

  void enQueue(int val)
  {
    memory.push_back(val);
  }

  bool deQueue()
  {
    if (isEmpty())
    {
      return false;
    }
    startPos++;
    return true;
  }

  int front()
  {
    return memory[startPos];
  }

  bool isEmpty()
  {
    return startPos >= memory.size();
  }

};

int main()
{
  vasQueue coada;
  coada.enQueue(33);
  coada.enQueue(34);
  if (!coada.isEmpty())
  {
    cout << coada.front() << endl;
  }
  coada.deQueue();
  if (!coada.isEmpty())
  {
    cout << coada.front() << endl;
  }
  coada.deQueue();
  if (!coada.isEmpty())
  {
    cout << coada.front() << endl;
  }
  else
  {
    cout << "empty queue" << endl;
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
