// BinaryTreeInorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

void work(TreeNode* node, vector<int>& val)
{
    stack<TreeNode*> stiva;
    stiva.push(node);
    bool pop_now = false;

    if (!(node->left))
    {
		pop_now = true;
    }

    while (!stiva.empty())
    {
        while (node->left)
        {
            stiva.push(node->left);
            node = node->left;
        }

        while (!(node->right))
        {
            cout << stiva.top()->val << endl;
            val.push_back(node->val);
            stiva.pop();
            if (stiva.empty())
            {
                node = nullptr;
                break;
            }
            node = stiva.top();
        }

        if (!node)
            break;

        if (node->right)
        {
            val.push_back(node->val);
            if (pop_now)
            {
                stiva.pop();
                pop_now = false;
            }
            stiva.push(node->right);
            node = node->right;
        }

    }
};

//class Solution {
//public:
//    vector<int> val{};
//    vector<int> inorderTraversal(TreeNode* root) {
//
//        if (!root)
//        {
//            return val;
//        }
//
//        work(root, val);
//        return val;
//
//    }
//};


#include <iostream>

int main()
{
    vector<int> val{};

    TreeNode root(0, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

	work(&root, val);

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
