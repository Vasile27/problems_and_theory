// thread_course_thread_safe_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<memory>
#include<stack>
#include <mutex>

using namespace std;

mutex m;

template<typename T>
class threadSafeStack
{
public:
  stack<shared_ptr<T>> vasStack;

  void push(T elem)
  {
    lock_guard<mutex> lg(m);
    shared_ptr<T> newPtr = make_shared<T>(elem);
    vasStack.push(newPtr);
  }

  shared_ptr<T> pop()
  {
    lock_guard<mutex> lg(m);
    shared_ptr<T> ret;
    if (vasStack.empty())
    {
      ret = make_shared<T>(nullptr);
    }
    else
    {
      ret = vasStack.top();
      vasStack.pop();
    }
    return ret;
  }

  void pop(T* output)
  {
    lock_guard<mutex> lg(m);
    if (vasStack.empty())
    {
      output = nullptr;
    }
    else
    {
      shared_ptr<T> ret = vasStack.top();
      output = *ret;
    }
  }

  bool empty()
  {
    lock_guard<mutex> lg(m);
    return vasStack.empty();
  }

  int size()
  {
    lock_guard<mutex> lg(m);
    return vasStack.size();
  }

  void print()
  {
    while (!vasStack.empty())
    {
      cout << *(vasStack.top()) << endl;
      vasStack.pop();
    }
  }

};

int main()
{
  threadSafeStack<int> stiva;
  stiva.push(3);
  stiva.push(4);
  stiva.push(5);
  stiva.print();

  thread t1(&threadSafeStack<int>::push, &stiva, 3);
  thread t2(&threadSafeStack<int>::pop, &stiva);
  t1.join();
  stiva.print();
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
