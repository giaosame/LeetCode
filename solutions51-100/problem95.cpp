// 95. Unique Binary Search Trees II
#include <vector>
#include "../utils.h"
using namespace std;

class Solution 
{
private:
	vector<TreeNode*> recurGenerate(int start, int end)
	{
		vector<TreeNode*> trees;
		if (start > end)
		{
			trees.push_back(nullptr);
			return trees;
		}

		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> left_trees = recurGenerate(start, i - 1);
			vector<TreeNode*> right_trees = recurGenerate(i + 1, end);

			for (TreeNode* ltree : left_trees)
			{
				for (TreeNode* rtree : right_trees)
				{
					TreeNode* cur_tree = new TreeNode(i);
					cur_tree->left = ltree;
					cur_tree->right = rtree;
					trees.push_back(cur_tree);
				}
			}
		}

		return trees;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0)
			return vector<TreeNode*>();
		return recurGenerate(1, n);
	}
};
