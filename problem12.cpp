// 12. Integer to Roman
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
#include <string>
using namespace std;

const string units[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string thousands[] = { "", "M", "MM", "MMM" };

class Solution {
public:
	string intToRoman(int num) {
		return thousands[num / 1000]
			+ hundreds[(num % 1000) / 100]
			+ tens[(num % 100) / 10]
			+ units[num % 10];
	}
};