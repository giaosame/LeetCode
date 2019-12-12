// 75. Sort Colors
#include <vector>
using namespace std;

class Solution {
private:
	void swap(vector<int>& nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

public:
	void sortColors(vector<int>& nums) {
		int zero_idx = 0;
		int two_idx = nums.size() - 1;

		for (int i = zero_idx; i <= two_idx; i++)
		{
			while (nums[i] == 2 && i < two_idx)
			{
				swap(nums, i, two_idx);
				two_idx--;
			}
			while (nums[i] == 0 && i > zero_idx)
			{
				swap(nums, i, zero_idx);
				zero_idx++;
			}
		}
	}
};