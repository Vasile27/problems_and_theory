// c++_course_static.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

class B
{
public:
  B() { cout << "B constructor" << endl; }
  B(int x) { cout << "B parm constructor" << endl; }
};
class A
{
public:
  //static int x;
  // for const variables we must initialize them like this
  //static const int MAX = 99;
  int y;
  A() : y(5) { cout << "A def constructor" << endl; }
  A(const A& a)
  {
    cout << "A copy constructor" << endl;
    y = a.y;
  }
  void operator = (const A& a)
  {
    cout << "= operator" << endl;
    y = a.y;
  }
  ~A() { cout << "A destructor" << endl; }
  //void printX() { cout << x << endl; }

  // not working because y is object  depended
 // static void printX() { cout << y << endl; }
};

//int A::x = 7;

int main()
{
  A a;
  vector<A> vectA;
  // copy constructor will be used
  vectA.push_back(a);

  // copy constructor
  A a3 = vectA[0];

  // destructor for A will be called
  vectA.pop_back();

  //// copy constructor
  //A a1 = a;
  //// operaor =
  //A a2;
  //a2 = a;
  
  //a.printX();
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
