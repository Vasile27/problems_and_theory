// thread_course_paralel_accumulate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include<vector>
#include<numeric>
#include <algorithm>
#include<functional>
#include<stdlib.h>

using namespace std;

#define MIN_BLOCK_SIZE 1000

template<typename iterator, typename T>
void AcumulateRef(iterator start, iterator end, T& result)
{
  result = accumulate(start, end, 0);
}

template<typename iterator, typename T>
T parallelAcumulate(iterator start, iterator end, T& result)
{
  // get the number of elements between start iterator and end iterator
  int input_size = distance(start, end);

  // calculate the number of threads needed based on how many elements
  // we have and our MIN_BLOCK_SIZE
  int allowed_threads_by_elements = input_size / MIN_BLOCK_SIZE;

  // get the hardware capabilities for threads
  int num_cores = thread::hardware_concurrency();

  // the actual number of threads will be the minimum bettwen the
  // hardware capabilites and num_of_threads_by_elements
  int number_of_threads = min(allowed_threads_by_elements, num_cores);

  // calculate the block size that will be given for each thread
  int block_size_per_thread = input_size / number_of_threads;

  vector<T> results(number_of_threads);
  // number_of_threads - 1 because the last chunk will be processed by
  // the main thread
  vector<thread> thread_vector(number_of_threads-1);

  // will be the last element of each data block
  iterator last = start;

  for (int i = 0; i < number_of_threads-1; ++i)
  {
    // advance last by the number of block size 
    advance(last, block_size_per_thread);
    
    // result will go in results vector
    // create the threads to do the calculation
    thread_vector[i] = thread(AcumulateRef<iterator, T>,
                        start,
                        last,
                        ref(results[i]));

    start = last;

  }

  results[number_of_threads - 1] = accumulate(start, end, 0);

   //join all the threads
  for_each(thread_vector.begin(),
           thread_vector.end(),
           mem_fn(&thread::join));

  return accumulate(results.begin(), results.end(), result);

}

void run()
{
  const int size = 8000000;
  vector<int> numbers(size);
  int ref = 0;
  
  srand(0);

  for (int i = 0; i < size; ++i)
  {
    numbers[i] = rand() % 10;
  }

  int sum = parallelAcumulate<vector<int>::iterator, int>(numbers.begin(),
                                                          numbers.end(),
                                                          ref);

  //int sum = accumulate(numbers.begin(), numbers.end(), ref);

  cout << "Accumulated value: " << sum << endl;

}
int main()
{
  run();
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
