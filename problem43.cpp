// 43. Multiply Strings
#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";

		int m = num1.size();
		int n = num2.size();
		string res(m + n, '0');

		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
				res[i + j + 1] = temp % 10 + '0';
				res[i + j] += temp / 10;
			}
		}

		int k;
		for (k = 0; res[k] == '0'; k++) {}
		return res.substr(k);
	}
};