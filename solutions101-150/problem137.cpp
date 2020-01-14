// 137. Single Number II
#include <numeric>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// The number x which appears once: x = (3 * sum(set(nums)) - sum(nums)) / 2;
// Easy to understand, but will meet the problem of integer overflow.
class Solution1 
{
public:
	int singleNumber(vector<int>& nums) 
	{
		unordered_set<int> set(nums.begin(), nums.end());
		return (3 * accumulate(set.begin(), set.end(), 0) - accumulate(nums.begin(), nums.end(), 0)) / 2;
	}
};


// Uses map:
class Solution2
{
public:
	int singleNumber(vector<int>& nums)
	{
		unordered_map<int, int> map;
		for (int num : nums)
			map[num]++;

		for (auto e : map)
		{
			if (e.second == 1)
				return e.first;
		}

		return nums[0];
	}
};
