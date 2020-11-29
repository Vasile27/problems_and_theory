// FunctionalTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<functional>


using namespace std;

class Check
{
public:
	int size;
	Check() :size{ 0 } {}
	Check(int size_arg) :size{ size_arg } {}
	bool operator()(string& test)
	{
		return test.size() == size;
	}
};


void run(function<bool(string&)> check)
{
	string test = "starts";
	cout << check(test) << endl;
}

int main()
{
	vector<string> v1{"one", "two", "three"};
	int size = 3;

	int count = count_if(v1.begin(), v1.end(), [size](string& test) { return test.size() == size; });

	cout << count << endl;

	Check check1(5);

	count = count_if(v1.begin(), v1.end(), check1);
	cout << count << endl;

	Check check2(6);
	run(check2);

	function<int(int, int)> add = [](int one, int two) {return one + two; };
	cout << add(3, 7) << endl;

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
