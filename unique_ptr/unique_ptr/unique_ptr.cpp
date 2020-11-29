// unique_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>

using namespace std;

class Foo
{
public:
	int x;

	Foo(int data) : x(data) {}
	~Foo() { cout << "Foo destrc " << "x:" << x << endl; }
	int getX() { return x; }
};

int main()
{
	//unique_ptr<Foo> p1(new Foo(10));
	//cout << p1->getX() << endl;
	//Foo* p2 = p1.release();
	//cout<<p2->getX()<<endl;
	//delete p2;
	unique_ptr<Foo> p3(new Foo(20));
	Foo* p4 = new Foo(40);
	cout << p3->getX() << endl;
	p3.reset(p4);
	cout << p3->getX() << endl;
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
