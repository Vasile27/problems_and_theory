// ds_alg_course_binary_search_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
  Node* left;
  Node* right;
  int data;

  Node(int value) : data{ value }, left{ nullptr }, right{ nullptr }{}
};

struct BinarySearchTree
{
  Node* root;
  Node* parent = nullptr;

  BinarySearchTree() : root{ nullptr } {}

  bool insert(int value)
  {
    if (lookup(value, &parent))
    {
      cout<<"Value already in tree"<<endl;
      return false;
    }

    Node* newNode = new Node(value);

    if (!root)
    {
      root = newNode;
      return true;
    }
    
    Node* node = root;
    while (true)
    {
      if (node->data < newNode->data)
      {
        if (node->right)
        {
          node = node->right;
        }
        else
        {
          node->right = newNode;
          break;
        }
      }
      else
      {
        if (node->left)
        {
          node = node->left;
        }
        else
        {
          node->left = newNode;
          break;
        }
      }
    }
  }

  Node* lookup(int value, Node** parent)
  {
    *parent = nullptr;

    if (!root)
    {
      return nullptr;
    }

    Node* node = root;
    while (node)
    {
      if (node->data == value)
      {
        break;
      }
      *parent = node;
      if (node->data < value)
      {
        node = node->right;
      }
      else if (node->data > value)
      {
        node = node->left;
      }
    }

    return node;
  }

  void traverse(Node* node)
  {
    if (!node)
    {
      return;
    }
    traverse(node->left);
    traverse(node->right);
    cout << node->data << " ";
  }

  void remove(int value)
  {
    Node* delNode = nullptr;
    Node* parentDelNode = nullptr;

    delNode = lookup(value, &parentDelNode);

    if (!delNode)
    {
      cout << "node not present in tree" << endl;
      return;
    }

    Node* rightChild = delNode->right;
    Node* leftChild = delNode->left;

    // if the delete node has no children then just delete it
    if (!rightChild && !leftChild)
    {
      if (parentDelNode)
      {
        if (parentDelNode->left == delNode)
        {
          parentDelNode->left = nullptr;
        }
        else
        {
          parentDelNode->right = nullptr;
        }
      }
      else
      {
        root = nullptr;
      }
      delete delNode;
    }
    else if (rightChild && !leftChild)
    {
      if (parentDelNode)
      {
        if (parentDelNode->left == delNode)
        {
          parentDelNode->left = rightChild;
        }
        else
        {
          parentDelNode->right = rightChild;
        }
      }
      else
      {
        root = rightChild;
      }
      delete delNode;
    }
    else if (!rightChild && leftChild)
    {
      if (parentDelNode)
      {
        if (parentDelNode->left == delNode)
        {
          parentDelNode->left = leftChild;
        }
        else
        {
          parentDelNode->right = leftChild;
        }
      }
      else
      {
        root = leftChild;
      }
      delete delNode;
    }
    else
    {
      Node* succesor = rightChild;
      Node* parentSuccesor = nullptr;
      while (succesor->left)
      {
        parentSuccesor = succesor;
        succesor = succesor->left;
      }

      if (parentSuccesor)
      {
        parentSuccesor->left = succesor->right;
      }

      if (parentDelNode)
      {
        if (parentDelNode->left == delNode)
        {
          parentDelNode->left = succesor;
        }
        else
        {
          parentDelNode->right = succesor;
        }
      }
      else
      {
        root = succesor;
      }
      succesor->left = delNode->left;
      succesor->right = delNode->right;
      
      delete delNode;
    }
  }

  vector<int> breadthFirstSearch()
  {
    vector<int> values;
    queue<Node *> coada;
    if (!root)
    {
      cout << "BFS no root" << endl;
      return values;
    }
    coada.push(root);

    while (!coada.empty())
    {
      Node* node = coada.front();
      coada.pop();
      values.push_back(node->data);
      if (node->left)
      {
        coada.push(node->left);
      }
      if (node->right)
      {
        coada.push(node->right);
      }
    }
    return values;
  }

  void breadthFirstSearchRecursive(queue<Node *>& coada, vector<int>& val)
  {
    if (coada.empty())
    {
      return;
    }

    Node* node = coada.front();
    coada.pop();
    val.push_back(node->data);
    if (node->left)
    {
      coada.push(node->left);
    }
    if (node->right)
    {
      coada.push(node->right);
    }
    breadthFirstSearchRecursive(coada, val);
  }

};

int main()
{
  BinarySearchTree binTree;
  binTree.insert(41);
  binTree.insert(65);
  binTree.insert(20);
  binTree.insert(11);
  binTree.insert(29);
  binTree.insert(32);
  binTree.insert(50);
  binTree.insert(51);
  binTree.insert(91);
  binTree.insert(72);
  binTree.insert(99);
  binTree.traverse(binTree.root);
  cout << endl;
  //cout << "------------------------------" << endl;
  //cout << binTree.lookup(20)->data << endl;

  cout << endl;
  cout << "------------------------------" << endl;
  binTree.remove(41);
  binTree.traverse(binTree.root);
  cout << endl;

  vector<int> val = binTree.breadthFirstSearch();
  cout << "print BFS iterative" << endl;
  for (auto it : val)
  {
    cout << it << " ";
  }
  cout << endl;

  vector<int> val2;
  queue<Node*> coada;
  coada.push(binTree.root);
  binTree.breadthFirstSearchRecursive(coada, val2);

  cout << "print BFS recursive" << endl;
  for (auto it : val2)
  {
    cout << it << " ";
  }
  cout << endl;

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
