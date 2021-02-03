// thread_course_dead_locks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

mutex m1;
mutex m2;

void f1()
{
  lock_guard<mutex> lg1(m1);
  cout << "Thread id: " << this_thread::get_id() << " acquaired m1" << endl;
  this_thread::sleep_for(chrono::milliseconds(1000));
  cout << "Thread id: " << this_thread::get_id() << " trying to acquaire m2" << endl;
  lock_guard<mutex> lg2(m2);
}

void f2()
{
  lock_guard<mutex> lg1(m2);
  cout << "Thread id: " << this_thread::get_id() << " acquaired m2" << endl;
  this_thread::sleep_for(chrono::milliseconds(1500));
  cout << "Thread id: " << this_thread::get_id() << " trying to acquaire m1" << endl;
  lock_guard<mutex> lg2(m1);
}

void f3()
{
  unique_lock<mutex> ul1(m1, defer_lock);
  unique_lock<mutex> ul2(m2, defer_lock);
  lock(ul1, ul2);
  cout << "Thread id: " << this_thread::get_id() << " acquaired m1 and m2" << endl;
}

void f4()
{
  unique_lock<mutex> ul1(m2, defer_lock);
  unique_lock<mutex> ul2(m1, defer_lock);
  lock(ul1, ul2);
  cout << "Thread id: " << this_thread::get_id() << " acquaired m1 and m2" << endl;
}

int main()
{
  // deadlock scenario
  //thread thread1(f1);
  //thread thread2(f2);

  thread thread1(f3);
  thread thread2(f4);
  thread1.join();
  thread2.join();
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
