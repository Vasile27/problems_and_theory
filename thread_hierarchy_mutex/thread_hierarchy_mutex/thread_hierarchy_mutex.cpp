// thread_hierarchy_mutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// page 51 - C concurrency in Action
#include <iostream>
#include<thread>
#include <mutex>

using namespace std;

class hierarchical_mutex
{
    mutex internal_mutex;

    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_tread_hierarchy_value; //B.1

    void check_for_hierarchy_violation()
    {
        if (this_tread_hierarchy_value <= hierarchy_value) //B.2
        {
            throw logic_error("mutex hierarchy violated");
        }
    }

    void update_hierarchy_value()
    {
        previous_hierarchy_value = this_tread_hierarchy_value; // B.3
        this_tread_hierarchy_value = hierarchy_value;
    }

public:
    hierarchical_mutex(int value) : hierarchy_value(value), previous_hierarchy_value(0) {}

    void lock()
    {
        try
        {
			check_for_hierarchy_violation();
            cout << "lock internal mutex" << endl;
            internal_mutex.lock(); //B.4
            update_hierarchy_value(); // B.5
        }
        catch (logic_error s)
        {
            cout << "Exception: " << s.what() << endl;
        }

    }

    void unlock()
    {
        this_tread_hierarchy_value = previous_hierarchy_value; // B.6
        internal_mutex.unlock();
    }

    bool try_unlock()
    {
        check_for_hierarchy_violation();
        if (!internal_mutex.try_lock())
        {
            return false;
        }

        update_hierarchy_value();
        return true;
    }
};

thread_local unsigned long hierarchical_mutex::this_tread_hierarchy_value(ULONG_MAX);


hierarchical_mutex high_level_mutex(10000); //1
hierarchical_mutex low_level_mutex(5000);  // 2

int do_low_level_stuff()
{
    cout << "do_low_level_stuffl" << endl;
    return 1;
}

int low_level_func()
{
    lock_guard<hierarchical_mutex> guard_low_mutex(low_level_mutex); // 3
    return do_low_level_stuff();
}

void high_level_stuff(int some_parm)
{
    cout << "high_level_stuff" << endl;
}

void high_level_func()
{
    lock_guard<hierarchical_mutex> guard_high_mutex(high_level_mutex); // 4
    high_level_stuff(low_level_func()); // 5
}

void thread_a() // 6
{
    high_level_func();
}

hierarchical_mutex other_mutex(100); // 7
void do_other_stuff()
{
    cout << "do_other_stuff()" << endl;
}

void other_stuff()
{
    high_level_func(); // 8
    do_other_stuff();
}

void thread_b() // 9
{
    lock_guard<hierarchical_mutex> guard_mutex(other_mutex); // 10
    other_stuff();
}

int main()
{
    //thread_a();
    //thread_b();
    int a[256] = { 1, 2, 3 };

    int* b = nullptr;

    b = a;
    cout << b[2] << endl;
    cout << a << endl;
    cout << &a << endl;
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
