// 45. Jump Game II
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int farthest = 0;
		int cur_end = 0;
		int cnt = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			farthest = max(farthest, i + nums[i]);
			if (i == cur_end)
			{
				cur_end = farthest;
				cnt++;
			}
		}

		return cnt;
	}
};