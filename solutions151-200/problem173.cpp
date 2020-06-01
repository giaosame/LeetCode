#include <stack>
#include "../utils.h"
using namespace std;

class BSTIterator 
{
	stack<TreeNode*> stk;

public:
	BSTIterator(TreeNode* root) 
	{
		pushAll(root);
	}

	/** @return the next smallest number */
	int next() 
	{
		TreeNode* next = stk.top();
		stk.pop();
		if (next->right)
		{
			pushAll(next->right);
		}

		return next->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !stk.empty();
	}

	void pushAll(TreeNode* node)
	{
		while (node)
		{
			stk.push(node);
			node = node->left;
		}
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
