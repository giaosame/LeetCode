// 199. Binary Tree Right Side View
#include <queue>
#include <vector>
#include "../utils.h"
using namespace std;

class Solution1
{
public:
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> right_side;
		if (!root)
			return right_side;

		queue<TreeNode*> queue;
		queue.push(root);

		while (!queue.empty())
		{
			int n = queue.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* temp = queue.front();
				queue.pop();
				if (temp->left)
					queue.push(temp->left);
				if (temp->right)
					queue.push(temp->right);

				if (i == n - 1)
					right_side.push_back(temp->val);
			}
		}

		return right_side;
	}
};
