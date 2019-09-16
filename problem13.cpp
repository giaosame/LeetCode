#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> roman_map = {
	{"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5},
	{"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9},
	{"X", 10}, {"XX", 20}, {"XXX", 30}, {"XL", 40}, {"L", 50},
	{"LX", 60}, {"LXX", 70}, {"LXXX", 80}, {"XC", 90},
	{"C", 100}, {"CC", 200}, {"CCC", 300}, {"CD", 400}, {"D", 500},
	{"DC", 600}, {"DCC", 700}, {"DCCC", 800}, {"CM", 900},
	{"M", 1000}, {"MM", 2000}, {"MMM", 3000}
};

class Solution {
public:
	int romanToInt(string s) {
		int num = 0;
		int i = 0;
		int len = 1;
		while (i + len <= s.size())
		{
			if (roman_map.find(s.substr(i, len)) != roman_map.end())
				len++;
			else
			{
				num += roman_map[s.substr(i, len - 1)];
				i = i + len - 1;
				len = 1;
			}
		}

		num += roman_map[s.substr(i, len)];
		return num;
	}
};