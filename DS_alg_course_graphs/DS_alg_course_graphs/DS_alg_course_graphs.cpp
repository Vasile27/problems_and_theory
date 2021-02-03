// DS_alg_course_graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>
#include<list>

// edge list
// graph = [[0,2], [2,3], [2, 1], [1,3]]
// ii arata muchiile grafului 0->2, 2->3, 2->1, 1->3

// adjacent list
// graph = [[2], [2,3], [0,1,3], [1, 2]]
//           0     1      2         3  nodes

// adjacent matrix
// grapf = [[0, 0, 1, 0],
//          [0, 0, 1, 1],
//          [1, 1, 0 ,1],
//          [0, 1, 1, 0]]

using namespace std;

class Graph
{
public:
  int numberOfNodes;
  unordered_map<int, list<int>> adjacentList;
  
  Graph() :numberOfNodes{ 0 }, adjacentList{} {}

  void addVertex(int node)
  {
    adjacentList[node] = list<int>();
    numberOfNodes++;
  }

  void addEdge(int node1, int node2)
  {
    //undirected graph
    adjacentList[node1].push_back(node2);
    adjacentList[node2].push_back(node1);
  }
  void showConnections()
  {
    for (auto it = adjacentList.begin(); it != adjacentList.end(); ++it)
    {
      cout << it->first << "-->";
      for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
      {
        cout << *it2 << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph myGraph;
  myGraph.addVertex(0);
  myGraph.addVertex(1);
  myGraph.addVertex(2);
  myGraph.addVertex(3);
  myGraph.addVertex(4);
  myGraph.addVertex(5);
  myGraph.addVertex(6);

  myGraph.addEdge(3, 1);
  myGraph.addEdge(3, 4);
  myGraph.addEdge(4, 2);
  myGraph.addEdge(4, 5);
  myGraph.addEdge(1, 2);
  myGraph.addEdge(1, 0);
  myGraph.addEdge(0, 2);
  myGraph.addEdge(6, 5);

  myGraph.showConnections();
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
