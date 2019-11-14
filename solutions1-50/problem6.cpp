// 6. ZigZag Conversion
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || numRows > s.size())
			return s;

		vector<string> zigzag(numRows);
		int r = 0;
		bool up_to_down = false;
		for (char c : s)
		{
			zigzag[r] += c;
			if (r == 0 || r == numRows - 1)
				up_to_down = !up_to_down;
			r += (up_to_down ? 1 : -1);
		}

		string res;
		for (string row : zigzag)
			res += row;
		return res;
	}
};