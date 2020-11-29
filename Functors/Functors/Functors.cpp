// Functors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Test
{
public:
	int x;

	Test(int val) :x(val) {}

	int operator()(int val)
	{
		return x + val;
	}
};

int add(int val)
{
	return  val + 10;
}

void work()
{
	Test test1(10);
	cout << test1(5) << endl;

	Test test2(500);
	cout << test2(-300) << endl;

	int (*add_func_p)(int) = add;

	vector<int> nr{ 1, 2, 3, 4, 5 };
	transform(nr.begin(), nr.end(), nr.begin(), add_func_p);

	for (auto it = nr.begin(); it != nr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<int> nr2{ 1, 2, 3, 4, 5 };
	transform(nr2.begin(), nr2.end(), nr2.begin(), test2);

	for (auto it = nr2.begin(); it != nr2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	work();
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
