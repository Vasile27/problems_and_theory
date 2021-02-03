// thread_course_ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include<chrono>

using namespace std;

void test()
{
  this_thread::sleep_for(chrono::milliseconds(200));
  cout << "Hello from test - thread id " << this_thread::get_id() << endl;
}

void functionA()
{
  thread threadC(test);
  threadC.detach();
 // threadC.join();
  //this_thread::sleep_for(chrono::milliseconds(100));
  cout << "FunctionA function thread id: " << this_thread::get_id() << endl;
}

void functionB()
{
  this_thread::sleep_for(chrono::milliseconds(400));
  cout << "FunctionB function thread id: " << this_thread::get_id() << endl;
}

void functionC()
{
  this_thread::sleep_for(chrono::milliseconds(2000));
  cout << "FunctionC function thread id: " << this_thread::get_id() << endl;
}

int main()
{
  thread threadA(functionA);
  thread threadB(functionB);

  threadA.join();
  threadB.join();
  cout << "Function MAIN function thread id: " << this_thread::get_id() << endl;

  thread threadC(functionC);
  threadC.detach();
  this_thread::sleep_for(chrono::milliseconds(2000));
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
