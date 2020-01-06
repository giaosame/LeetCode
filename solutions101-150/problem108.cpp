// 108. Convert Sorted Array to Binary Search Tree
#include <vector>
#include "../utils.h"
using namespace std;

class Solution
{
private:
	TreeNode* recurSort(vector<int>& nums, int start, int end)
	{
		if (start > end)
			return nullptr;

		int mid = start + (end - start) / 2;
		TreeNode* cur_tree = new TreeNode(nums[mid]);
		cur_tree->left = recurSort(nums, start, mid - 1);
		cur_tree->right = recurSort(nums, mid + 1, end);

		return cur_tree;
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		return recurSort(nums, 0, nums.size() - 1);
	}
};
