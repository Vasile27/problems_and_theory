// DS_alg_fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int fibonacciIterative(int n)
{
  if (n == 0)
  {
    return 0;
  }

  int fibo = 0;
  int s1 = 0;
  int s2 = 1;

  while (n - 1 >= 1)
  {
    fibo = s1 + s2;
    s1 = s2;
    s2 = fibo;
    --n;
  }
  return fibo;
}

int calc = 0;
int fibonacciRecursive(int n)
{
  calc++;
  cout << calc << endl;
  if (n == 0)
  {
    return 0;
  }
  if (n == 1)
  {
    return 1;
  }
  return (fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2));

}

int main()
{
  cout << fibonacciRecursive(7) << endl;
  cout << fibonacciIterative(11) << endl;
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
