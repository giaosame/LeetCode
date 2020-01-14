// 145. Binary Tree Postorder Traversal
#include <stack>
#include <vector>
#include "../utils.h"
using namespace std;

// Recursion:
class Solution1
{
private:
	void recurTraverse(TreeNode* node, vector<int>& postorder)
	{
		if (!node)
			return;

		recurTraverse(node->left, postorder);
		recurTraverse(node->right, postorder);
		postorder.push_back(node->val);
	}

public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> postorder;
		recurTraverse(root, postorder);
		return postorder;
	}
};


// An easy Iteration:
// Traverses the node as the sequence mid->right->left, then reverses the sequence to get left->right->mid.
// A little problem: ignores topological dependencies.
class Solution2
{
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> postorder;
		stack<TreeNode*> stk;
		TreeNode* cur = root;

		while (!stk.empty() || cur)
		{
			while (cur)
			{
				postorder.insert(postorder.begin(), cur->val);
				stk.push(cur);
				cur = cur->right;
			}

			cur = stk.top();
			stk.pop();
			cur = cur->left;
		}

		return postorder;
	}
};


// The better iteration with topological dependencies:
class Solution 
{
public:
	vector<int> postorderTraversal(TreeNode* root) 
	{
		vector<int> postorder;
		stack<TreeNode*> stk;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;

		while (!stk.empty() || cur)
		{
			while (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}

			TreeNode* temp = stk.top();
			if (temp->right && pre != temp->right)
				cur = temp->right;
			else
			{
				postorder.push_back(temp->val);
				pre = temp;
				stk.pop();
			}
		}

		return postorder;
	}
};
