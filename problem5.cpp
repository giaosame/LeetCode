// 5. Longest Palindromic Substring
// Given a string s, find the longest palindromic substring in s. 
// You may assume that the maximum length of s is 1000.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int expandAroundCenter(string s, int left, int right)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}

		return right - left - 1;
	}

public:
	// expand around center
	string longestPalindrome1(string s)
	{
		string max_palind = "";
		for (int i = 0; i < s.size(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int max_len = max(len1, len2);
			if (max_len > max_palind.size())
			{
				int start = i - (max_len - 1) / 2;
				max_palind = s.substr(start, max_len);
			}
		}
		
		return max_palind;
	}

	// dp:
	string longestPalindrome2(string s) {
		if (s.size() <= 1)
			return s;

		int n = s.size();
		string max_palind = "";
		vector<vector<int>> dp(n, vector<int>(n));
		for (int j = 0; j < n; j++)
		{
			for (int i = j; i >= 0; i--)
			{
				if (s[i] == s[j])
				{
					if (i + 3 > j)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];
				}

				if (dp[i][j] && j - i + 1 > max_palind.size())
					max_palind = s.substr(i, j - i + 1);
			}
		}

		return max_palind;
	}
};