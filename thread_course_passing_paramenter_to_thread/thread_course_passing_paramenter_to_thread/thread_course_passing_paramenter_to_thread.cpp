// thread_course_passing_paramenter_to_thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void func_2(int &x)
{
  while (true)
  {
    cout << "Thread 1 valuef of X - " << x << endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main()
{
  int x = 9;
  cout << "Main thread value of X - " << x << endl;

  // the thread object itself take its argument by value
  // so if we want to pass a reference we must use std::ref(x)
  //thread thread_1(func_2, x);
  thread thread_1(func_2, ref(x));
  this_thread::sleep_for(std::chrono::milliseconds(5000));
  x = 15;
  cout << "Main thread value of X has been changed to - " << x << endl;
  thread_1.join();

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
