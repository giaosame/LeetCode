// 78. Subsets
#include <vector>
using namespace std;

class Solution1 {
private:
	void recurSet(vector<vector<int>>& sets, vector<int>& nums, vector<int>& subset, int k, int start)
	{
		if (subset.size() == k)
		{
			sets.push_back(subset);
			return;
		}

		for (int i = start; i < nums.size(); i++)
		{
			subset.push_back(nums[i]);
			recurSet(sets, nums, subset, k, i + 1);
			subset.pop_back();
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> power_set;
		vector<int> subset;
		for (int k = 0; k <= nums.size(); k++)
		{
			recurSet(power_set, nums, subset, k, 0);
		}

		return power_set;
	}
};

class Solution2
{
private:
	void recurSet(vector<vector<int>>& sets, vector<int>& cur_set, vector<int>& nums, int start)
	{
		sets.push_back(cur_set);
		for (int i = start; i < nums.size(); i++)
		{
			cur_set.push_back(nums[i]);
			recurSet(sets, cur_set, nums, i + 1);
			cur_set.pop_back();
		}
	}

public:
	vector<vector<int>> subsets(vector<int>& nums) 
	{
		vector<vector<int>> sets;
		vector<int> cur_set;
		recurSet(sets, cur_set, nums, 0);
		return sets;
	}
};