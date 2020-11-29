// DS_alg_course_irst_recurring_character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>

using namespace std;

// function using the hashMap -> O(n)
int findRecuringElement(vector<int> &nums)
{
  unordered_map<int, int> hashMap;

  if (nums.size() < 2)
  {
    return -1;
  }

  for (int i = 0; i < nums.size(); ++i)
  {
    if (hashMap.find(nums[i]) != hashMap.end())
    {
      return nums[i];
    }
    hashMap[nums[i]] = i;
  }
}

// function using brute force (the bonus question - resolved) - O(n^2)
int findRecuringElement2(vector<int>& nums)
{
  int len = nums.size();
  
  // save de second duplicate postion here
  int secondDupPos = INT_MAX;
  int rc = 0;

  if (len < 2)
  {
    return rc;
  }
  for (int i = 0; i < len - 1; ++i)
  {
    // if the first pointer passes the secondDupPos and the secondDupPos was
    // set i.e we have discovered a duplicate then exit because this will be
    // our first duplicate
    if (secondDupPos != INT_MAX && secondDupPos < i)
    {
      break;
    }
    for (int j = i + 1; j < len; ++j)
    {
      if (nums[i] == nums[j])
      {
        // found duplicate. Is the position at a lower index that the
        // one we found last? If it is saved it.
        if (secondDupPos > j)
        {
          secondDupPos = j;
        }
      }
    }
  }
  
  // if secondDupPos was sent i.e duplicate found return the number at
  // that position. Else return 0
  if (secondDupPos != INT_MAX)
  {
    rc = nums[secondDupPos];
  }
  else
  {
    rc = 0;
  }
  return rc;
}

int main()
{
  vector<int> nums{2,5,1,2,3,5,1,2,4};
  cout << findRecuringElement(nums) << endl;
  vector<int> nums2{2,5,1,5,2,3,5,1,2,4};
  cout << findRecuringElement(nums2) << endl;
  vector<int> nums3{2,5,3,3,5,2};
  cout << findRecuringElement2(nums3) << endl;
  vector<int> nums4{2,5,5,2,3,5,1,2,4};
  cout << findRecuringElement2(nums4) << endl;
  cout << findRecuringElement2(nums) << endl;
  cout << findRecuringElement2(nums2) << endl;
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
