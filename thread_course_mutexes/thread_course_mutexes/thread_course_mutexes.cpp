// thread_course_mutexes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <chrono>

using namespace std;

mutex m;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val{ x }, next{nullptr} {}
};

struct vasList
{
  ListNode* head;
  int length;

  vasList() :head{ nullptr }, length{ 0 } {}

  void addToListFront(int x)
  {
    lock_guard<mutex> lg(m);
    ListNode* node = new ListNode(x);
    if (!head)
    {
      head = node;
    }
    else
    {
      // we delayed the operation so that we can see if we don't use a mutex
      // we will not have all the elements inserted in the list by multiple
      // threads
      this_thread::sleep_for(chrono::milliseconds(1000));
      node->next = head;
      head = node;
    }
    length++;
  }

  void printList()
  {
    ListNode* node = head;
    while (node)
    {
      cout << node->val << " ";
      node = node->next;
    }
    cout << endl;
  }
};

void addToList(list<int> &list, int v)
{
  lock_guard<mutex> lg(m);
  list.push_back(v);
}

void printList(list<int>& list)
{
  for (auto it = list.begin(); it != list.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

int main()
{
  //list<int> lista;
  //thread thread1(addToList, ref(lista), 5);
  //thread thread2(addToList, ref(lista), 6);
  //thread1.join();
  //thread2.join();
  //printList(lista);

  vasList lista;
  lista.addToListFront(5);

  thread thread1(&vasList::addToListFront, &lista, 6);
  thread thread2(&vasList::addToListFront, &lista, 7);
  thread thread3(&vasList::addToListFront, &lista, 8);
  thread thread4(&vasList::addToListFront, &lista, 9);
  thread thread5(&vasList::addToListFront, &lista, 10);
  thread thread6(&vasList::addToListFront, &lista, 11);

  thread1.join();
  thread2.join();
  thread3.join();

  thread4.join();
  thread5.join();
  thread6.join();

  cout << "List len: " << lista.length << endl;

  lista.printList();
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
