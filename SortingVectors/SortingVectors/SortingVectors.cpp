// SortingVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Test
{
	int id;
	string name;
	int age;
	float height;
	//int *grades;

public:
	Test() :id(0), name(""), age(0), height(0) {}

	Test(int id, string name, int age, float height) : id(id), name(name), age(age), height(height) {}
	
	Test(const Test& other)
	{
		id = other.id;
		name = other.name;
		age = other.age;
		height = other.height;
	}

	~Test() {}

	Test& operator = (const Test& other)
	{
		id = other.id;
		name = other.name;
		age = other.age;
		height = other.height;

		return *this;
	}

	bool operator < (const Test& other)
	{
		if (id != other.id)
		{
			return id < other.id;
		}
		else
		{
			if (name != other.name)
			{
				return name < other.name;
			}
			else
			{
				if (age != other.age)
				{
					return age < other.age;
				}
				else
				{
					return height < other.height;
				}
			}
		}
	}

	void print()
	{
		cout << id << " " << name << " " << age << " " << height << endl;
	}

	friend bool compare(const Test& a, const Test& b);

};

bool compare(const Test& a, const Test& b)
{

	if (a.name != b.name)
	{
		return a.name < b.name;
	}
	else
	{
		if (a.age != b.age)
		{
			return a.age < b.age;
		}
		else
		{
			return a.height < b.height;
		}
	}
}

void work()
{
	vector<Test> test;

	test.push_back(Test(1, "John", 30, 1.60));
	test.push_back(Test(23, "Marie", 30, 1.90));
	test.push_back(Test(2, "Ken", 40, 1.80));
	test.push_back(Test(1, "Alice", 10, 1.60));
	test.push_back(Test(53, "Bob", 15, 1.60));

	sort(test.begin(), test.end());

	for (auto it = test.begin(); it != test.end(); ++it)
	{
		it->print();
	}

	cout << "---------------------------------" << endl;

	sort(test.begin(), test.end(), compare);

	for (auto it = test.begin(); it != test.end(); ++it)
	{
		it->print();
	}

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
