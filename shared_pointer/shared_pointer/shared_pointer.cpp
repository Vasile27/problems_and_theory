// shared_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>
#include<thread>

using namespace std;

class Foo
{
  int x;
public:
  Foo(int x) : x{ x } { cout << "Foo constr" << endl; }
  int getX() { return x; }
  void setX(int val) { x = val; }

  ~Foo() { cout << "Foo Dest for X: " << x << endl; }
};

void fun(shared_ptr<Foo> sp, int sleepSeconds, string name)
{
  this_thread::sleep_for(chrono::seconds(sleepSeconds));
  cout << "fun: " << name << " " << sp.use_count() << endl;
}

int main()
{
  shared_ptr<Foo> sharedPtr1(new Foo(10));
  cout << sharedPtr1->getX() << endl;
  // use_count() -> how many places the management object is used
  cout << sharedPtr1.use_count() << endl;

  Foo* rawPtr = new Foo(30);
  shared_ptr<Foo> sharedPtr2(rawPtr);
  // still fail after program ends
 // shared_ptr<Foo> sharedPtr3(rawPtr);
  shared_ptr<Foo> sharedPtr3 = sharedPtr2;
  cout << sharedPtr2->getX() << endl;
  cout << sharedPtr2.use_count() << endl;
  cout << sharedPtr3.use_count() << endl;

  // using reference or pointer to shared pointers does not increase the
  // reference count
  shared_ptr<Foo> sharedPtr4(new Foo(50));
  shared_ptr<Foo> &sharedPtr5 = sharedPtr4;
  cout << sharedPtr4.use_count() << endl;
  cout << sharedPtr5.use_count() << endl;

  shared_ptr<Foo> sharedPtr6(new Foo(100));
  thread t1(fun, sharedPtr6, 0, "t1");
  thread t2(fun, sharedPtr6, 2, "t2");
  thread t3(fun, sharedPtr6, 1, "t3");
  cout << "main: " << sharedPtr6.use_count() << endl;
  t1.join();
  t2.join();
  t3.join();
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
