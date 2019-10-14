// 3. Longest Substring Without Repeating Characters
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int max_len = 0;
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (map.find(s[i]) != map.end())
				j = max(j, map[s[i]] + 1);
			max_len = max(max_len, i - j + 1);
			map[s[i]] = i;
		}

		return max_len;
	}
};