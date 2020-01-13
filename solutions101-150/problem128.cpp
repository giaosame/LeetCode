// 128. Longest Consecutive Sequence
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums) 
	{
		unordered_map<int, int> map;
		int max_len = 0;

		for (int num : nums)
		{
			if (map.find(num) == map.end())
			{
				int left_len = map.find(num - 1) != map.end() ? map[num - 1] : 0;
				int right_len = map.find(num + 1) != map.end() ? map[num + 1] : 0;
				int len = 1 + left_len + right_len;

				map[num] = map[num - left_len] = map[num + right_len] = len;
				max_len = max(max_len, len);
			}
		}

		return max_len;
	}
};
