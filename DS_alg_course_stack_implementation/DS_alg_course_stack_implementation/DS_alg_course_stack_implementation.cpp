// DS_alg_course_stack_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
  string val;
  Node* next;
  Node(string val) : val{ val }, next{ nullptr } {}
};

struct Stack
{
  Node* top;
  Node* bottom;
  int length;

  Stack() :top(nullptr), bottom{ nullptr }, length{ 0 } {}

  Node *peek()
  {
    return top;
  }

  void push(string value)
  {
    Node* newNode = new Node(value);
    newNode->next = top;
    if (!bottom)
    {
      bottom = newNode;
    }
    top = newNode;
    length++;
  }

  void pop()
  {
    if (!length)
    {
      return;
    }
    Node* delNode = top;
    if (bottom == top)
    {
      bottom = nullptr;
    }
    top = top->next;
    delete delNode;
  }
  void printStack()
  {
    Node* node = top;
    while (node)
    {
      cout << node->val << endl;
      node = node->next;
    }
  }
};

int main()
{
  Stack vasStack;
  vasStack.push("Google");
  vasStack.push("StackOverFlow");
  vasStack.push("Amazon");
  vasStack.printStack();
  cout << "----------------" << endl;
  cout << vasStack.peek()->val << endl;
  cout << "----------------" << endl;
  vasStack.pop();
  cout << vasStack.peek()->val << endl;
  cout << "----------------" << endl;
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
