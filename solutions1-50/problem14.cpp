// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		string prefix = strs[0];
		for (int i = 1; i < strs.size(); i++)
		{
			while (strs[i].find(prefix) != 0)
				prefix = prefix.substr(0, prefix.size() - 1);
		}

		return prefix;
	}
};