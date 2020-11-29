// StatiCast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent constructor" << endl;
	}

	void speakParent()
	{
		cout << "Speak Parent" << endl;
	}
};

class Brother : public Parent
{
public:
	string brother_name;

	Brother()
	{
		cout << "Brother constructor" << endl;
		brother_name = "James";
	}

	void speakBrother()
	{
		cout << "Speak Brother" << brother_name << endl;
	}
};

int main()
{
	Parent parent;
	Brother brother;

	Parent *pParent;
	Brother* pBrother;


	pParent = &brother;

	// cant access the brother methods
	//pParent->speakBrother();

	pBrother = static_cast<Brother *>(&parent);

	// va crapa pentru ca membrul brother_name nu exista in parent!
	// nu crapa daca metoda speakBrother() nu folosete membrii din Brother
	//pBrother->speakBrother();

	Parent&& rParent = static_cast<Parent &&>(parent);
	rParent.speakParent();
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
