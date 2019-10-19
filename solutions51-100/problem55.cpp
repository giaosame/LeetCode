// 55. Jump Game
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int farthest = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (i <= farthest)
				farthest = max(farthest, i + nums[i]);
			else
				break;
		}

		return farthest >= nums.size() - 1;
	}
};