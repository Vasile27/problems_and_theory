// unique_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>

using namespace std;

class Foo
{
  int x;
public:
  Foo(int x) : x{ x } { cout << "Foo constr" << endl; }
  int getX() { return x; }
  void setX(int val) {  x = val; }

  ~Foo() { cout << "Foo Dest" << endl; }
};


int main()
{
  // this is not exception safe
 // unique_ptr<Foo> p(new Foo(10));

  // cannot convert from "Foo * to unique_ptr<Foo>"
  //unique_ptr<Foo> p2 = new Foo(20);

  // make_unique is exception safe
  //unique_ptr<Foo> p3 = make_unique<Foo>(20);

  Foo* p_simple = new Foo(100);
  unique_ptr<Foo> p4(p_simple);

  // this will cause an error at the end of the program
  // it will try to delete the same object twice
  // DO NOT ASSIGN SAME OBJECT TO TWO UNIQUE POINTERS
  //unique_ptr<Foo> p6(p_simple);

  //p4->setX(500);
  //cout << p4->getX() << " " << p6->getX() << endl;

  unique_ptr<Foo> p5(new Foo(300));
  // will fail because you cannot copy ownership
  //p4 = p5;

  // p1 will become null_ptr. p6 will take ownership of the Foo object of p1.
  unique_ptr<Foo> p6 = move(p5);
  cout << p6->getX() << endl;

  // get the Foo pointer object
  Foo* p6_raw = p6.get();
  cout << p6_raw->getX() << endl;

  // release the object from p6 and gives it to p7_raw;
  // p6 becomes null pointer
  Foo* p7_raw = p6.release();
  cout << p7_raw->getX() << endl;


  unique_ptr<Foo> p8 = make_unique<Foo>(600);
  cout << p8->getX() << endl;

  // Change the ownership object. So p8 will take ownership of the object
  // pointed by p7_raw. And the former object of p8 will be deleted.
  p8.reset(p7_raw);
  cout << p8->getX() << endl;

  // swap will swap the ownership objects between pointers
  p8.swap(p4);
  cout << p8->getX() << " " << p4->getX() << endl;

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
