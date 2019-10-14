// 4. Median of Two Sorted Arrays
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n)
			return findMedianSortedArrays(nums2, nums1);

		int i_left = 0;
		int i_right = m;
		while (i_left <= i_right)
		{
			int i = (i_left + i_right) / 2;
			int j = (m + n + 1) / 2 - i;

			if (i < m && nums2[j - 1] > nums1[i])
				i_left = i + 1;
			else if (i > 0 && nums1[i - 1] > nums2[j])
				i_right = i - 1;
			else
			{
				int left_max;
				if (i == 0)
					left_max = nums2[j - 1];
				else if (j == 0)
					left_max = nums1[i - 1];
				else
					left_max = max(nums1[i - 1], nums2[j - 1]);

				if ((m + n) % 2 == 1)
					return left_max;

				int right_min;
				if (i == m)
					right_min = nums2[j];
				else if (j == n)
					right_min = nums1[i];
				else
					right_min = min(nums1[i], nums2[j]);

				return double(left_max + right_min) / 2;
			}
		}

		return 0.0;
	}
};