// thread_course_condition_variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<mutex>
#include <chrono>

using namespace std;

bool haveIArraived = false;
int distanceToMyDest = 10;
int distanceCovered = 0;

bool keepDriving()
{
  while (true)
  {
    this_thread::sleep_for(chrono::milliseconds(1000));
    //cout << "distance covered: " << distanceCovered << endl;
    distanceCovered++;
  }
  return false;
}

void keepAwakeAllNight()
{
  while (distanceCovered < distanceToMyDest)
  {
    cout << "kepp check, whether I am there" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
  cout << "keepAwakeAllNight finally I am here, distanceCovered: " << distanceCovered << endl;
}

void setTheAlarmAndTakeANap()
{
  if (distanceCovered < distanceToMyDest)
  {
    cout << "let me take a nap" << endl;
    this_thread::sleep_for(chrono::milliseconds(10000));
  }
  cout << "setTheAlarmAndTakeANap finally I am here, distanceCovered: " << distanceCovered << endl;

}

void runCode()
{
  thread driverThread(keepDriving);
  thread keepAwakeAllNightThread(keepAwakeAllNight);
  thread setTheAlarmAndTakeANapThread(setTheAlarmAndTakeANap);

  driverThread.join();
  keepAwakeAllNightThread.join();
  setTheAlarmAndTakeANapThread.join();
}

int main()
{
  runCode();
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
