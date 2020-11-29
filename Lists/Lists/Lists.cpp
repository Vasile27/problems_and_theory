// Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<fstream>

using namespace std;

void work()
{
    list<int> lista;

    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);
    lista.push_back(5);

    int option = 0;
	string file_name = "save.bin";

    string cont{ "YES" };

	while (cont == "YES")
	{
		cout << "Insert element: 1" << endl;
		cout << "Delete element: 2" << endl;
		cout << "Print list: 3" << endl;
		cout << "Save list: 4" << endl;
		cout << "Load list: 5" << endl;
		cout << "Waiting for user input... ";
		cin >> option;

		if (option == 1)
		{
			cout << "Insert element..." ;
			int element;
			cin >> element;
			lista.push_back(element);
		}
		else if (option == 2)
		{
			cout << "Delete element...";
			int del_elem = 0;
			cin >> del_elem;

			list<int> ::iterator it = find(lista.begin(), lista.end(), del_elem);
			if (it == lista.end())
			{
				cout << "Elem for deletion not found!" << endl;
			}
			else
			{
				lista.erase(it);
			}
		}
		else if (option == 3)
		{
			for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
		else if (option == 4)
		{

			// save list contents to binary file

			ofstream output;
			output.open(file_name, ios::binary);
			if (!output.is_open())
			{
				cout << "Fail to open file " << file_name;
			}
			else
			{
				for (auto it = lista.begin(); it != lista.end(); ++it)
				{
					int nr = *it;
					output.write(reinterpret_cast<char *>(&nr), sizeof(nr));
				}
				output.close();
			}


		}
		else if (option == 5)
		{
			//load saved list into new list and display it
			ifstream input;
			input.open(file_name, ios::binary);

			if (!input.is_open())
			{
				cout << "Failed to load file " << file_name << endl;
			}
			else
			{
				
				list<int> lista_load;
				while (true)
				{

				int nr;
				input.read(reinterpret_cast<char *>(&nr), sizeof(nr));
				if (input.eof())
				{
					break;
				}
				lista_load.push_back(nr);
				}

				for (auto it = lista_load.begin(); it != lista_load.end(); ++it)
				{
					cout << *it << " ";
				}
				cout << endl;

				input.close();
			}
		}

		cout << "Contiue...";
		cin >> cont;
	}
}


int work_2(int a, int b)
{
	//int max = ((a * (b / a) + (b % a)) + (b * (a / b) + (a % b)) + abs(a-b)) / 2;

	int max = (a + b + abs(a - b)) / 2;

	//int x1 = a * (b / a) + (b % a);
	//int x2 = b * (a / b) + (a % b);

	//cout << "x1 " << x1 << endl;
	//cout << "x2 " << x2 << endl;

	return max;
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
