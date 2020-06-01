// 159. Longest Substring with At Most Two Distinct Characters
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


// Extends the original one to the problem with most k distinct characters
class Solution 
{
public:
	int lengthOfLongestSubstringKDistinct(string &s, int k) 
	{
		// write your code here]
		unordered_map<char, int> map;
		int left = 0;
		int right = 0;
		int max_len = 0;
		int cnt = 0;

		while (right < s.size())
		{
			int temp_cnt = map[s[right]]++;
			if (temp_cnt == 0)
				cnt++;
			right++;

			while (cnt > k)
			{
				if (--map[s[left]] == 0)
					cnt--;
				left++;
			}

			max_len = max(max_len, right - left);
		}

		return max_len;
	}
};
