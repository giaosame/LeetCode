// 8. String to Integer (atoi)
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		int i = 0;
		// 1. remove blanks
		while (s[i] == ' ')
			i++;

		// 2. judge the sign
		int sign = 1;
		if (s[i] == '+')
			i++;
		else if (s[i] == '-')
		{
			sign = -1;
			i++;
		}

		// 3. calculate the integer
		long num = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			num = 10 * num + (s[i] - '0');
			if (sign * num > INT_MAX)
				return INT_MAX;
			else if (sign * num < INT_MIN)
				return INT_MIN;
			i++;
		}

		return sign * num;
	}
};