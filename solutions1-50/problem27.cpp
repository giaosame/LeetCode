// 27. Remove Element
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[cnt++] = nums[i];
		}

		return cnt;
	}
};