// 67. Add Binary
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int m = a.size();
		int n = b.size();
		int carry = 0;

		string res;
		for (int i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
		{
			if (i >= 0)
				carry += a[i] - '0';
			if (j >= 0)
				carry += b[j] - '0';

			res = char(carry % 2 + '0') + res;
			carry /= 2;
		}

		if (carry == 1)
			res = '1' + res;
		return res;
	}
};