// thread_course_transferring_ownership_of_a_thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>

using namespace std;

void foo()
{
  cout << "foo" << endl;
}

void bar()
{

  cout << "bar" << endl;
}

int main()
{
  thread thread1(foo);

  // cannot be done. Thread objects are NOT copy constructable or copy
  // assignable
  //thread thread2 = thread1;
  //we can move threads
  thread thread2 = move(thread1);

  // thread1 does not own now any objects

  // here we have a temporary objects on the right side of the assigment
  // operator. This type of assigment implies move operator.
  thread1 = thread(bar);

  thread thread3(foo);

  // will fail because thread1 already has management of an object
  //thread1 = move(thread3);

  
  thread1.join();
  thread2.join();
  thread3.join();

  cout << thread::hardware_concurrency() << endl;
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
