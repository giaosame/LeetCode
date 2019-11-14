// 11. Container With Most Water
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
			return 0;

		int mostWater = 0;
		int left = 0;
		int right = height.size() - 1;
		while (left < right)
		{
			int h = min(height[left], height[right]);
			int w = right - left;
			mostWater = max(mostWater, h * w);

			if (height[left] > height[right])
				right--;
			else if (height[left] < height[right])
				left++;
			else {
				if (height[left + 1] < height[right - 1])
					right--;
				else
					left++;
			}
		}

		return mostWater;
	}
};