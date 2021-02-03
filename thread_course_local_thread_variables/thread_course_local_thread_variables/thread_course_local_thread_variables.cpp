// thread_course_local_thread_variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include<thread>
#include<atomic>

using namespace std;

// if thread_local is used then each thread
// will have a "personal" x
//thread_local atomic<int> x = 0;
thread_local int x;

void foo()
{
  ++x;
  cout << x << endl;
}

int main()
{
  thread thread1(foo);
  thread thread2(foo);
  thread thread3(foo);
  thread1.join();
  thread2.join();
  thread3.join();
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
