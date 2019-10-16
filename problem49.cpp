// 49. Group Anagrams
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> groups;
		unordered_map<string, int> map;
		for (string str : strs)
		{
			string temp = str;
			sort(temp.begin(), temp.end());
			if (map.find(temp) == map.end())
			{
				map[temp] = groups.size();
				vector<string> g = { str };
				groups.push_back(g);
			}
			else
			{
				groups[map[temp]].push_back(str);
			}
		}

		return groups;
	}
};