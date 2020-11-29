// threads_accumulate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<numeric>
#include<iterator>
#include <vector>
#include<algorithm>
#include<functional>

using namespace std;

template<typename Iterator, typename T>
struct accumulate_bloc
{
    void operator () (Iterator first, Iterator last, T& result)
    {
        result = accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned long const length = distance(first, last);

    if (!length)  // 1
    {
        return init;
    }

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread-1)/min_per_thread; // 2

    unsigned long const hardware_threads = thread::hardware_concurrency();

    cout << "hardware_threads: " << hardware_threads << endl;

    unsigned long const num_threads = min(hardware_threads != 0 ? hardware_threads : 2, max_threads); // 3

    cout << "num_thread: " << num_threads << endl;

    unsigned long const block_size = length / num_threads; //4

    vector<T> results(num_threads); 

    vector<thread> threads(num_threads - 1); // 5

    Iterator block_start = first;

    for (unsigned long i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        advance(block_end, block_size); // 6
        threads[i] = thread(accumulate_bloc<Iterator, T>(), block_start, block_end, ref(results[i])); // 7
        cout << "thread id: "<<threads[i].get_id() << endl;
        block_start = block_end; // 8

    }

    accumulate_bloc<Iterator, T>()(block_start, last, results[num_threads - 1]); // 9

    for_each(threads.begin(), threads.end(), mem_fn(&(thread::join))); // 10

    return accumulate(results.begin(), results.end(), init); // 11


}

int main()
{
    vector<int> v1;

    for (int i = 0; i < 10000; i++)
    {
        v1.push_back(i);
    }
    int result = 0;

   
    cout << "result is: " << parallel_accumulate(v1.begin(), v1.end(), result);
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
