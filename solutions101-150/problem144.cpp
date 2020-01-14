// 144. Binary Tree Preorder Traversal
#include <stack>
#include <vector>
#include "../utils.h"
using namespace std;

// Recursion:
class Solution1 {
private:
	void recurTraverse(TreeNode* node, vector<int>& preorder)
	{
		if (!node)
			return;

		preorder.push_back(node->val);
		recurTraverse(node->left, preorder);
		recurTraverse(node->right, preorder);
	}

public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> preorder;
		recurTraverse(root, preorder);
		return preorder;
	}
};


// Iteration:
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> preorder;
		stack<TreeNode*> stk;
		TreeNode* cur = root;

		while (!stk.empty() || cur)
		{
			while (cur)
			{
				preorder.push_back(cur->val);
				stk.push(cur);
				cur = cur->left;
			}

			cur = stk.top();
			stk.pop();
			cur = cur->right;
		}

		return preorder;
	}
};