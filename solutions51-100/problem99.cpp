// 99. Recover Binary Search Tree
#include <algorithm>
#include <stack>
#include <vector>
#include "../utils.h"
using namespace std;

// Just does the inorder traversal twice.
class Solution1
{
public:
	void recoverTree(TreeNode* root)
	{
		vector<int> inorder;
		stack<TreeNode*> stk;
		TreeNode* node = root;

		while (!stk.empty() || node)
		{
			while (node)
			{
				stk.push(node);
				node = node->left;
			}

			node = stk.top();
			stk.pop();
			inorder.push_back(node->val);
			node = node->right;
		}

		sort(inorder.begin(), inorder.end());
		int i = 0;
		while (!stk.empty() || root)
		{
			while (root)
			{
				stk.push(root);
				root = root->left;
			}

			root = stk.top();
			stk.pop();
			root->val = inorder[i++];
			root = root->right;
		}
	}
};


// Declares two TreeNode pointers first_node and second_node
// To represents those 2 nodes swapped by mistake.
// Uses stack to do the inorder traversal to locate those 2 nodes.
class Solution2 
{
public:
	void recoverTree(TreeNode* root) 
	{
		TreeNode* first_node = nullptr;
		TreeNode* second_node = nullptr;
		TreeNode* pre = nullptr;
		TreeNode* cur = root;

		stack<TreeNode*> stk;
		while (!stk.empty() || cur)
		{
			while (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}

			cur = stk.top();
			stk.pop();

			if (!first_node && pre && pre->val >= cur->val)
				first_node = pre;
			if (first_node && pre && pre->val >= cur->val)
				second_node = cur;

			pre = cur;
			cur = cur->right;
		}

		int temp = first_node->val;
		first_node->val = second_node->val;
		second_node->val = temp;
	}
};
