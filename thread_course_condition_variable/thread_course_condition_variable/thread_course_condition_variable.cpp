// thread_course_condition_variable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<chrono>
#include<condition_variable>

using namespace std;

bool iHaveArrived = false;
int totalDistance = 10;
int distanceCovered = 0;
condition_variable cv;
mutex m;

void keepMoving()
{
  while (true)
  {
    this_thread::sleep_for(chrono::milliseconds(1000));
    distanceCovered++;
    if (distanceCovered == totalDistance)
    {
      cv.notify_one();
    }
  }
}

void askDriverToWakeMeUpAtRightTime()
{
  unique_lock<mutex> ul(m);
  cv.wait(ul, [] {return distanceCovered == totalDistance});
  cout << "finally I am here, distance_covered: " << distanceCovered << endl;
}

void runCode()
{
  thread driverThread(keepMoving);
  thread passangerThread(askDriverToWakeMeUpAtRightTime);
  passangerThread.join();
  driverThread.join();
}


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
