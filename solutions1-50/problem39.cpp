// 39. Combination Sum
#include <vector>
using namespace std;

class Solution {
private:
	void recurCombinate(vector<int>& candidates, vector<vector<int>>& combinations, vector<int>& cur_combination, int target, int start)
	{
		if (target < 0)
			return;
		if (target == 0)
		{
			combinations.push_back(cur_combination);
			return;
		}

		for (int i = start; i < candidates.size(); i++)
		{
			cur_combination.push_back(candidates[i]);
			recurCombinate(candidates, combinations, cur_combination, target - candidates[i], i);
			cur_combination.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> combinations;
		vector<int> cur_combination;
		recurCombinate(candidates, combinations, cur_combination, target, 0);
		return combinations;
	}
};