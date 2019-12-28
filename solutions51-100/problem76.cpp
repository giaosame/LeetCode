// 76. Minimum Window Substring
#include <string>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
	string minWindow(string s, string t) 
	{
		unordered_map<char, int> map;
		for (char c : t)
			map[c]++;

		int left = 0;
		int right = 0;
		int cnt = 0;
		int min_left = 0;
		int min_len = INT_MAX;

		while (right < s.size())
		{
			if (map.find(s[right]) != map.end())
			{
				if (--map[s[right]] >= 0)
					cnt++;
			}
			right++;

			while (cnt == t.size())
			{
				if (right - left < min_len)
				{
					min_left = left;
					min_len = right - left;
				}

				if (map.find(s[left]) != map.end())
				{
					if (++map[s[left]] > 0)
						cnt--;
				}
				left++;
			}
		}

		if (min_len > s.size())
			return "";
		return s.substr(min_left, min_len);
	}
};