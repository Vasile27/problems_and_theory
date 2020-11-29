// DS_build_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
 
using namespace std;

#define VAS_ARRAY_SIZE 10000

class vasArray
{
public:
	int length;
	int *data;
	vasArray()
	{
		length = 0;
		data = new int[VAS_ARRAY_SIZE];
		for (int i = 0; i < VAS_ARRAY_SIZE; ++i)
		{
			data[i] = 0;
		}
	}

	~vasArray()
	{
		delete[] data;
	}

	// O(1)
	int get(int index)
	{
		return data[index];
	}

	// O(1)
	void push(int item)
	{
		data[length] = item;
		length++;
	}

	// O(1)
	void pop()
	{
		data[length-1] = 0;
		length--;
	}

	// O(n)
	void shiftElements(int index)
	{
		for (int i = index; i < length - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		data[length - 1] = 0;
		length--;
	}

	// O(n)
	int deleteElem(int index)
	{
		int del_item = data[index];
		shiftElements(index);
		return del_item;
	}

	// O(n)
	void printArray()
	{
		cout << "Array elements: " << " ";
		for (int i = 0; i < length; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

};

int main()
{
	vasArray vas_array;
	vas_array.push(123);
	cout << vas_array.get(0) << endl;
	vas_array.pop();
	cout << vas_array.get(0) << endl;
	vas_array.push(123);
	vas_array.push(23);
	vas_array.push(33);
	vas_array.push(533);
	vas_array.push(833);
	vas_array.printArray();
	vas_array.deleteElem(3);
	vas_array.printArray();
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
