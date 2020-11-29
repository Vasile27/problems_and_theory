// weak_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<memory>

using namespace std;

struct Son;
struct Daughter;

struct Mother
{
  Mother() { cout << "Mother constr" << endl; }
  ~Mother() { cout << "Mother destr" << endl; }
  void setSon(shared_ptr<Son> s)
  {
    // assigment works if s is shared_ptr
    cout << "setSon shared ptr" << endl;
    son = s;
  }

  void setSon(weak_ptr<Son> s)
  {
    cout << "setSon weak_ptr" << endl;
    son = s.lock();
  }

  void setDaughter(shared_ptr<Daughter> d)
  {
    cout << "setDaughter shared_ptr by value. daughter count: " << d.use_count() << endl;
    daughter = d;
  }

  void setDaughterRef(shared_ptr<Daughter> &d)
  {
    cout << "setDaughter shared_ptr by reference. daughter count: " << d.use_count() << endl;
    daughter = d;
  }

  // this will cause a cyclic dependency
  // mother has a shared_pointer son pointing to son object
  // and son object has a shared pointer mom poiting to mom object
  // Son cannot be destroyed because mom cannot be destroyed and vice-versa
  // To fix this we will declare the son and daughter to be weak_pointers
  //shared_ptr<Son> son;
  //shared_ptr<Daughter> daughter;

  weak_ptr<Daughter> daughter;
  weak_ptr<Son> son;
};

struct Son
{
  shared_ptr<Mother> mother;
  Son(shared_ptr<Mother> m) : mother{m}
  {
    cout << "Son constr " << endl;
  }
  ~Son() { cout << "Son destructor " << endl; }

};

struct Daughter
{
  shared_ptr<Mother> mother;
  Daughter(shared_ptr<Mother> m) : mother{m}
  {
    cout << "Daughter constr " << endl;
  }
  ~Daughter() { cout << "Daughter destructor " << endl; }

};

int main()
{
  shared_ptr<int> sharedPtr1 = make_shared<int>(100);
  weak_ptr<int> weakPtr1(sharedPtr1);

  cout << "SharedPtr1 use_count " << sharedPtr1.use_count() << endl;
  cout << "SharedPtr1: "<< *sharedPtr1 << endl;
  // cant access the managed object via the weak pointer
  // it must be converted to shared_ptr in order to access the refereced
  // object
 // cout << *weakPtr1 << endl;
  cout << "Weak pointer - shared ptr expired " << weakPtr1.expired() << endl;

  // converting the weak pointer to shared pointer
  if (auto sharedPtr2 = weakPtr1.lock())
  {
    cout << "object was been locked" << endl;
    cout << "SharedPtr1 use_count " << sharedPtr1.use_count() << endl;
  }
  else
  {
    cout << "Could not lock object" << endl;
  }

    cout << "SharedPtr1 use_count " << sharedPtr1.use_count() << endl;
  
    // release the ownership of the mananaged object
    weakPtr1.reset();

  if (auto sharedPtr2 = weakPtr1.lock())
  {
    cout << "object was been locked" << endl;
    cout << "SharedPtr1 use_count " << sharedPtr1.use_count() << endl;
  }
  else
  {
    cout << "Could not lock object" << endl;
  }

  cout << "---------------------------------------------------" << endl;

  shared_ptr<Mother> mom = make_shared<Mother>();
  shared_ptr<Son> son = make_shared<Son>(mom);
  weak_ptr<Son> weakSon(son);
  shared_ptr<Daughter> daughter = make_shared<Daughter>(mom);

  mom->setSon(weakSon);
  mom->setDaughter(daughter);


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
