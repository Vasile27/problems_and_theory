// thread_course_problem_when_passing_reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include<chrono>

using namespace std;

void func2(int &x)
{
  while (true)
  {
    try
    {
      // will get error of reading invalid memory after thread1(func1)
      // finishes to execute. (x is passed as reference)
      cout << x << endl;
      this_thread::sleep_for(chrono::milliseconds(1000));
    }
    catch (...)
    {
      throw runtime_error("this is a runtime error");
    }
  }
}

void func1()
{
  int x = 5;
  thread thread2(func2, ref(x));
  thread2.detach();
  this_thread::sleep_for(chrono::milliseconds(5000));
  cout << "thread 1 finished executing" << endl;

}

int main()
{
  thread thread1(func1);
  thread1.join();
  this_thread::sleep_for(chrono::milliseconds(1000));
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
