// thread_course_sail_ship_with_work_queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <queue>
#include <chrono>

using namespace std;

enum struct Commands {noCommand = 0,
                      clean = 1,
                      fullSpead = 2,
                      stopEngine = 3,
                      stopProgram = 100 };

class CleaningCrew
{
public:
  CleaningCrew() {}

  void pushToQueue()
  {
    cleanQueue.push(Commands::clean);
  }

  Commands getCommand()
  {
    Commands returnCommand = Commands::noCommand;
    if (!cleanQueue.empty())
    { 
     returnCommand = cleanQueue.front();
     cleanQueue.pop();
    }
    return returnCommand;
  }

private:
  queue<Commands> cleanQueue;
};

class EngineCrew
{
public:
  EngineCrew() {}

  void pushToQueue(Commands val)
  {
    crewQueue.push(val);
  }

  Commands getCommand()
  {
    Commands returnCommand = Commands::noCommand;
    if (!crewQueue.empty())
    { 
     returnCommand = crewQueue.front();
     crewQueue.pop();
    }
    return returnCommand;
  }

private:
  queue<Commands> crewQueue;
};

void cleanWorker(CleaningCrew &cleanCrew)
{
  while (true)
  {
    if (cleanCrew.getCommand() != Commands::noCommand)
    {
      cout << "CleanWorker is cleaning" << endl;
      this_thread::sleep_for(chrono::milliseconds(1000));
      cout << "CleanWorker finished cleaning" << endl;
    }
    else
    {
      cout << "No clean work found...waiting 2 seconds" << endl;
      this_thread::sleep_for(chrono::milliseconds(3500));
    }
  }
}

void engineWorker(EngineCrew &engCrew)
{
  while (true)
  {
    Commands command = engCrew.getCommand();
    if (command != Commands::noCommand)
    {
      if (command == Commands::fullSpead)
      {
        cout << "Engine crew works on full spead ahead." << endl;
      }
      else if (command == Commands::stopEngine)
      {
        cout << "Engine crew works on stopping engine." << endl;
      }
      this_thread::sleep_for(chrono::milliseconds(1000));
      cout << "Engine crew finished work" << endl;
    }
    else
    {
      cout << "No engine work found...waiting 2 seconds" << endl;
      this_thread::sleep_for(chrono::milliseconds(2500));
    }
  }
}

int main()
{
  CleaningCrew cleanCrew;
  EngineCrew engineCrew;
  int command = 0;

  thread threadCleaning(cleanWorker, ref(cleanCrew));
  thread threadEngine(engineWorker, ref(engineCrew));

  threadCleaning.detach();
  threadEngine.detach();

  while (true)
  {
    cout << "Enter command: ";
    cin >> command;

    switch (static_cast<Commands>(command))
    {
    case Commands::clean:
      cleanCrew.pushToQueue();
      break;
    case Commands::fullSpead:
      engineCrew.pushToQueue(Commands::fullSpead);
      break;
    case Commands::stopEngine:
      engineCrew.pushToQueue(Commands::stopEngine);
      break;
    case Commands::stopProgram:
      cout << "Stoping program..." << endl;
      return 0;
    default:
      break;
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
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
