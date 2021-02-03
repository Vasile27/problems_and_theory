// thread_course_ship_ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void doCleaning()
{
  cout << "Doing cleaning" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "Cleaning finished" << endl;
}

void fullSpeadAhead()
{
  cout << "Go full spead ahead" << endl;
  this_thread::sleep_for(chrono::microseconds(300));
  cout << "Full spead ahead reached" << endl;
}

void fullStop()
{
  cout << "Stoping ship" << endl;
  this_thread::sleep_for(chrono::microseconds(100));
  cout << "Ship stopped" << endl;
}

int main()
{
  int order;
  while (true)
  {
    cout << "Enter order: " << endl;
    cin >> order;

    if (order == 1)
    {
      thread threadCleaner(doCleaning);
      threadCleaner.detach();
    }
    else if(order == 2)
    {
      thread threadCrew(fullSpeadAhead);
      threadCrew.join();
    }
    else if(order == 3)
    {
      thread threadCrew(fullStop);
      threadCrew.join();
    }
    else if(order == 100)
    {
      cout << "Exiting..." << endl;
      return 0;
    }
    else
    {
      cout << "Command not supported" << endl;
    }
  }
  return 0;
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
