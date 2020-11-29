// TemplateClasses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template <class T, class K>
class Test
{

public:

    Test() : object1(), object2() {}
    Test(T obj1, K obj2)
    {
        object1 = obj1;
        object2 = obj2;
    }

    ostream& print(ostream& out) const
    {
        out << object1 << " " << object2;
        return out;
    }


    bool operator<(const Test& other)
    {
        return object2 < other.object2;
    }

    friend Test operator+<T,K>(const Test& a, const Test& b);
    //                     ^^^^ 
// This makes operator+<int, int> a friend of Test<int,int>, not a friend
// of Test<double,double>

    //friend Test<T, K> operator+(const Test<T, K>& a, const Test<T, K>& b);

private:
    T object1;

    K object2;

};

template <class T, class K>
ostream& operator<<(ostream& out, const Test<T, K>& t)
{
    return t.print(out);
}

template <class T, class K>
Test<T, K> operator+(const Test<T, K>& a, const Test<T, K>& b)
{
    return Test<T, K>(a.object1, a.object2 + b.object2);
}


void work()
{
    Test<string, int> t1("Vasile", 7);
    Test<string, int> t2("Ana", 37);
    cout << t1 << endl;

    if (t1 < t2)
    {
        cout << "t1<t2" << endl;
    }
    else
    {
		cout << "t1>t2" << endl;
    }

    cout << t1 + t2 << endl;
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
