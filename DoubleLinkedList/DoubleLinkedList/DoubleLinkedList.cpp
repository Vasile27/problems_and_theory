// DS_alg_course_double_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node* next;
  Node* previous;
  Node(int value) : value{ value }, next{ nullptr }, previous{nullptr} {}
};
struct LinkedList
{
  int length;
  Node* head;
  Node* tail;
  LinkedList(int x) : length{1}
  {
    // at first head will be this
    // tail will be head because we will have only one element
    head = new Node(x);
    tail = head;
  }

  void append(int value)
  {
    Node* newItem = new Node(value);
    tail->next = newItem;
    newItem->previous = tail;
    tail = tail->next;
    length++;
  }

  void prepend(int value)
  {
    Node* newItem = new Node(value);
    newItem->next = head;
    head->previous = newItem;
    head = newItem;
    length++;
  }

  Node* getNodeByPos(int index)
  {
    Node* node = head;
    int counter = 0;
    while (counter < index)
    {
      node = node->next;
      counter++;
      if (node == nullptr)
      {
        break;
      }
    }
    return node;
  }

  void insert(int pos, int value)
  {
    if (pos == 0)
    {
      prepend(value);
    }
    // if position is >= length then insert as tail
    else if (pos >= length)
    {
      append(value);
    }
    else
    {
      Node* beforeNode = getNodeByPos(pos - 1);
      Node* afterNode = beforeNode->next;
      Node* newItem = new Node(value);
      beforeNode->next = newItem;
      afterNode->previous = newItem;
      newItem->next = afterNode;
      newItem->previous = beforeNode;
      length++;
    }
  }

  void popHead()
  {
    Node* temp = head;
    head = head->next;
    head->previous = nullptr;
    delete temp;
    length--;
  }

  void popTail()
  {
    Node* temp = tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete temp;
    length--;
  }

  void remove(int pos)
  {
    if (pos == 0)
    {
      popHead();
    }
    else if (pos >= length)
    {
      popTail();
    }
    else
    {
      Node* beforeNode = getNodeByPos(pos - 1);
      Node* removeNode = beforeNode->next;
      Node* afterNode = removeNode->next;
      beforeNode->next = afterNode;
      afterNode->previous = beforeNode;
      delete removeNode;
      length--;
    }
  }

  void printList()
  {
    Node* node = head;
    while (node)
    {
      cout << node->value << " ";
      node = node->next;
    }
    cout << endl;
    cout << "List length: " << length << endl;
  }
 
  void printListReverse()
  {
    Node* node = tail;
    while (node)
    {
      cout << node->value << " ";
      node = node->previous;
    }
    cout << endl;
    cout << "List length: " << length << endl;
  }

};

int main()
{
  LinkedList* myLinkedList = new LinkedList(10);
  myLinkedList->append(5);
  myLinkedList->append(16);
  myLinkedList->prepend(30);
  myLinkedList->prepend(45);
  myLinkedList->insert(2, 500);
  myLinkedList->insert(myLinkedList->length, 501);
  myLinkedList->insert(0, 502);
  myLinkedList->insert(4, 540);
  myLinkedList->printList();
  myLinkedList->printListReverse();
  
  myLinkedList->popTail();
  myLinkedList->printList();
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
