// 102. Binary Tree Level Order Traversal
#include <queue>
#include <vector>
#include "../utils.h"
using namespace std;

class Solution 
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> levels;
		if (!root)
			return levels;

		queue<TreeNode*> queue;
		queue.push(root);
		while (!queue.empty())
		{
			vector<int> level;

			int n = queue.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				level.push_back(node->val);

				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}

			levels.push_back(level);
		}

		return levels;
	}
};
