#include "MatrixComplex.hpp"
#include<iostream>

using namespace std;

void work()
{
	//Complex c1(3, 5);
	//cout << c1 << endl;
	//Complex c2 = c1;
	//cout << c2 << endl;
	//c2 = c2 + 5;
	//Complex c3;
	//c3 = c2;
	//cout << c3 << endl;

	//Complex c4 = c1 + c2;
	//cout << c4 << endl;

	//Complex c5(4, 3);
	//Complex c6 = c5 + 4;
	//cout << c6 << endl;

	//cout << 3.2 + c6 << endl;

	//if (c1 < c2)
	//{
	//	cout << "c1<c2"<<endl;
	//}
	//else {
	//	cout << "c1>c2" << endl;
	//}

	//Complex c7(3, 5);
	//Complex c8(3, 4);

	//if (c7 == c8)
	//{
	//	cout << "c7 == c8" << endl;
	//}
	//else
	//{
	//	cout << "c7 != c8" << endl;
	//}

	//if (c7 != c8)
	//{
	//	cout << "c7 != c8" << endl;
	//}
	//else
	//{
	//	cout << "c7 == c8" << endl;
	//}

	//Complex c1(5, 3);

	//cout << "Conjugate c1" << endl;
	//Complex c2 = c1;
	//cout << *c2 << endl;

	MatrixComplex matrix;

	matrix(1, 2) = Complex(1, 2);
	cout << matrix(1, 2) << endl;
}

int main()
{
	work();
}