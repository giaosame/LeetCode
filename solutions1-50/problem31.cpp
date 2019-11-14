// 31. Next Permutation
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

	void reverse(vector<int>& nums, int left, int right)
	{
		int mid = left + (right - left) / 2;
		for (int i = left; i <= mid; i++)
			swap(nums, i, left + right - i);
	}

public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 1;
		for (; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
				break;
		}

		if (i == 0)
		{
			reverse(nums, 0, n - 1);
			return;
		}

		int j = n - 1;
		for (; j > i; j--)
		{
			if (nums[j] > nums[i - 1])
				break;
		}

		swap(nums, i - 1, j);
		reverse(nums, i, n - 1);
	}
};