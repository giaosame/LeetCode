// 29. Divide Two Integers
// Given two integers dividend and divisor, 
// divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.
#include <cmath>

class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = 1;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
			sign = -1;

		long dvd = labs(dividend);
		long dvs = labs(divisor);
		if (dvd == 0 || dvd < dvs)
			return 0;

		long quotient = 0;
		while (dvd >= dvs)
		{
			long t = dvs;
			long p = 1;
			while (dvd >= (t << 1))
			{
				t <<= 1;
				p <<= 1;
			}

			dvd -= t;
			quotient += p;
		}

		quotient *= sign;
		if (quotient > INT_MAX)
			return INT_MAX;
		return quotient;
	}
};