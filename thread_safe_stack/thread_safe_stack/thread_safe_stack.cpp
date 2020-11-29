// thread_safe_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<exception>
#include <memory> // for shared_ptr<>
#include <mutex>
#include <stack>

using namespace std;

struct empty_stack : exception
{
    const char* what() const throw();
};

template <typename T>
class  threadsafe_stack
{
private:
    stack<T> data;
    mutable mutex m;
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack& other)
    {
        lock_guard<mutex> lock(other.m);
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        lock_guard<mutex> lock(m);
        data.push(new_value);
    }
    shared_ptr<T> pop()
    {
        lock_guard<mutex> lock(m);
        if (data.empty())
        {
            throw empty_stack();
        }
        shared_ptr<T> const res(make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value)
    {
        lock_guard<mutex> lock(m);
        if (data.empty())
        {
            throw empty_stack();
        }

        value = data.top();
        data.pop();
    }
    bool empty() const
    {
        lock_guard<mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    std::cout << "Hello World!\n";
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
