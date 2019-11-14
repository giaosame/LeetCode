// 32. Longest Valid Parentheses
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int max_len = 0;
		stack<int> stack;
		stack.push(-1);

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				stack.push(i);
			else
			{
				stack.pop();
				if (stack.empty())
					stack.push(i);
				else
					max_len = max(max_len, i - stack.top());
			}
		}

		return max_len;
	}
};