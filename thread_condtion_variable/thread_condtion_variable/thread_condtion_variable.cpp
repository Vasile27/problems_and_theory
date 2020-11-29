// thread_condtion_variable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<mutex>
#include<condition_variable>
#include<queue>

using namespace std;

struct data_chunk
{
    data_chunk() : info(0) {}
    data_chunk(int value) : info(value) {}

    int info;
};

mutex mut;
queue<data_chunk> data_queue; //1
condition_variable data_cond;
int number_of_data = 100;


bool more_data_to_prepare()
{
    if (number_of_data > 0)
    {
        return true;
    }

    return false;
}

data_chunk prepare_data()
{
    data_chunk data_info(number_of_data);
    number_of_data--;
    return data_info;
}

void process(data_chunk data)
{
    cout << "Process data " << data.info << endl;
}

bool is_last_chunk(data_chunk data)
{
    if (data.info == 1)
    {
        return true;
    }

    return false;
}

// function declaration
void data_preparation_thread();

void data_processing_thread()
{
    thread prepare_thread(data_preparation_thread);

    while (true)
    {
        unique_lock<mutex> lk(mut); // 4
        data_cond.wait(lk, [] {return !data_queue.empty(); }); // 5
        data_chunk data = data_queue.front();
        data_queue.pop();
        lk.unlock(); // 6
        process(data);
        if (is_last_chunk(data))
            break;
    }

    prepare_thread.join();
}

void data_preparation_thread()
{
    //thread process_thread(data_processing_thread);
    //process_thread.join();

    while (more_data_to_prepare())
    {
        data_chunk const data = prepare_data();
        lock_guard<mutex> lk(mut);
        data_queue.push(data); // 2
        data_cond.notify_one(); // 3

    }
}


int main()
{
    //thread prepare_thread(data_preparation_thread);
    //prepare_thread.join();

    thread process_thread(data_processing_thread);
    process_thread.join();

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
