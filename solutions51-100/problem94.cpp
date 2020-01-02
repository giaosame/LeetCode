// 94. Binary Tree Inorder Traversal
#include <stack>
#include <vector>
#include "../utils.h"
using namespace std;

class Solution1 
{
private:
	void traverse(TreeNode* node, vector<int>& inorder)
	{
		if (node == nullptr)
			return;

		traverse(node->left, inorder);
		inorder.push_back(node->val);
		traverse(node->right, inorder);
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> inorder;
		traverse(root, inorder);
		return inorder;
	}
};

class Solution 
{
public:
	vector<int> inorderTraversal(TreeNode* root) 
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

		return inorder;
	}
};
