// c++_course_custom_exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
using namespace std;

void goesWrong()
{
  bool error1 = false;
  bool error2 = true;

  if (error2)
  {
    throw bad_alloc();
  }
  if (error1)
  {
    throw exception();
  }
}

class MyException : public exception
{
public:
  // const throw() means that the method cannot throw exception
  // deprecated in C++ 11. Now use noexcept
  virtual const char* what() const throw()
  {
    return "Something bad happend!";
  }
};

class Test
{
public:
  void goesWrong()
  {
    throw MyException();
  }
};

class A
{
public:
  int x;
  A() :x{ 5 } {}
  virtual void display()
  {
    cout << "display A" << endl;
  }
};

class B : public A
{
public:
  int y;

  B() :y{ 5 } { x = 10; }
  virtual void display()
  {
    cout << "display B" << endl;
  }
};

//void foo(A a)
//{
//  cout << a.x << endl;
//  a.display();
//}

void foo(A& a)
{
  cout << a.x << endl;
  a.display();

}

//void foo(A* a)
//{
//  cout << a.x << endl;
//  a.display();
//
//}

int main()
{
  //Test test;


  //try
  //{
  //  test.goesWrong();
  //}
  //catch (MyException e)
  //{
  //  cout << e.what() << endl;
  //}

  //try
  //{
  //  goesWrong();
  //}
  //catch (exception e)
  //{
  //  cout << "Catch exception" << endl;
  //  cout << e.what() << endl;
  //}
  //catch (bad_alloc e)
  //{

  //  cout << "Catch bad_alloc" << endl;
  //  cout << e.what() << endl;
  //}

  A a;
  B b;

  // it works to send b to foo
  foo(b);

  return 0;
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
