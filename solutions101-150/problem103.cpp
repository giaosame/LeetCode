// 103. Binary Tree Zigzag Level Order Traversal
#include <queue>
#include <vector>
#include "../utils.h"
using namespace std;

// Uses queue to do the level order traversal
// Uses a flag left_to_right to determine the traversed node's value should be
// pushed into the back or front of the vector. 
class Solution 
{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
	{
		vector<vector<int>> levels;
		if (!root)
			return levels;

		queue<TreeNode*> queue;
		queue.push(root);
		bool left_to_right = true;

		while (!queue.empty())
		{
			int n = queue.size();
			vector<int> zigzag(n);

			for (int i = 0; i < n; i++)
			{
				TreeNode* node = queue.front();
				queue.pop();
				int idx = left_to_right ? i : n - 1 - i;
				zigzag[idx] = node->val;

				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}

			levels.push_back(zigzag);
			left_to_right = !left_to_right;
		}

		return levels;
	}
};
