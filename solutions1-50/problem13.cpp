// 13. Roman to Integer
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> big_map = {
	{"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5},
	{"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9},
	{"X", 10}, {"XX", 20}, {"XXX", 30}, {"XL", 40}, {"L", 50},
	{"LX", 60}, {"LXX", 70}, {"LXXX", 80}, {"XC", 90},
	{"C", 100}, {"CC", 200}, {"CCC", 300}, {"CD", 400}, {"D", 500},
	{"DC", 600}, {"DCC", 700}, {"DCCC", 800}, {"CM", 900},
	{"M", 1000}, {"MM", 2000}, {"MMM", 3000}
};

unordered_map<char, int> small_map = {
	{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
};


class Solution {
public:
	// function with big_map
	int romanToInt1(string s) {
		int num = 0;
		int i = 0;
		int len = 1;
		while (i + len <= s.size())
		{
			if (big_map.find(s.substr(i, len)) != big_map.end())
				len++;
			else
			{
				num += big_map[s.substr(i, len - 1)];
				i = i + len - 1;
				len = 1;
			}
		}

		num += big_map[s.substr(i, len)];
		return num;
	}

	// function with small_map, a easier one 
	int romanToInt2(string s) {
		int num = small_map[s.back()];
		for (int i = s.size() - 2; i >= 0; i--)
		{
			if (small_map[s[i]] >= small_map[s[i + 1]])
				num += small_map[s[i]];
			else
				num -= small_map[s[i]];
		}

		return num;
	}
};
