// thread_deadlock1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include <functional>


using namespace std;

void Thread1(thread &&t)
{
    cout << "Thread1" << endl;
    t = thread(Thread2, move(t));
    t.join();
}

void Thread2(thread &&t)
{
    cout << "Thread2" << endl;
    t.join();
}

int main()
{
    thread t1;
    thread t2;

    t1 = thread(Thread1, move(t2));
    t2 = thread(Thread2, move(t1));

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
