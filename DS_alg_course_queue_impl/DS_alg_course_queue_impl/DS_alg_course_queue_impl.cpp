// DS_alg_course_queue_impl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<typename T>
struct Node
{
  T val;
  Node* next;

  Node(T value) : val{ value }, next{ nullptr } {}
};

template<typename T>
struct Queue
{
  Node<T>* top;
  Node<T>* bottom;
  int length;

  Queue() : top{ nullptr }, bottom{ nullptr }, length{ 0 } {}

  Node<T>* peek()
  {
    return top;
  }

  void enque(T value)
  {
    Node<T>* newNode = new Node<T>(value);
    if (!length)
    {
      top = newNode;
      bottom = newNode;
    }
    else
    {
      bottom->next = newNode;
      bottom = newNode;
    }
    ++length;
  }

  void deque()
  {
    if (!length)
    {
      return;
    }
    if (length == 1)
    {
      bottom = nullptr;
    }
    Node<T>* delNode = top;
    top = top->next;
    delete delNode;
    --length;
  }

  void print()
  {
    Node<T>* node = top;
    for (int i = 0; i < length; ++i)
    {
      cout << node->val << " ";
      node = node->next;
    }
    cout << endl;
  }
};

int main()
{
  Queue<string> vasQueue;
  vasQueue.enque("Ana1");
  vasQueue.enque("Ana2");
  vasQueue.enque("Ana3");
  vasQueue.print();
  vasQueue.deque();
  cout << "--------------------------" << endl;
  cout << vasQueue.peek()->val << endl;
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
