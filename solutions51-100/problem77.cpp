// 77. Combinations
#include <vector>
using namespace std;

class Solution 
{
private:
	void recurCombine(vector<vector<int>>& combinations, vector<int>& cur_combination, vector<int>& nums, int k, int start)
	{
		if (cur_combination.size() == k)
		{
			combinations.push_back(cur_combination);
			return;
		}

		for (int i = start; i < nums.size(); i++)
		{
			cur_combination.push_back(nums[i]);
			recurCombine(combinations, cur_combination, nums, k, i + 1);
			cur_combination.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> combinations;
		vector<int> cur_combination;
		vector<int> nums;
		for (int i = 1; i <= n; i++)
			nums.push_back(i);

		recurCombine(combinations, cur_combination, nums, k, 0);
		return combinations;
	}
};