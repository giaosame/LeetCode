// 84. Largest Rectangle in Histogram
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution 
{
public:
	int largestRectangleArea(vector<int>& heights) 
	{
		stack<int> stk;
		int max_area = 0;

		int i = 0;
		while (i < heights.size())
		{
			if (stk.empty() || heights[i] >= heights[stk.top()])
				stk.push(i++);
			else
			{
				int idx = stk.top();
				stk.pop();
				int width = stk.empty() ? i : i - 1 - stk.top();
				max_area = max(max_area, heights[idx] * width);
			}
		}

		while (!stk.empty())
		{
			int idx = stk.top();
			stk.pop();
			int width = stk.empty() ? i : i - 1 - stk.top();
			max_area = max(max_area, heights[idx] * width);
		}

		return max_area;
	}
};