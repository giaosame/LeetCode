// 172. Factorial Trailing Zeroes

// In fact, just calculate the number of 5 as the divisor of the factorial.
class Solution 
{
public:
	int trailingZeroes(int n) 
	{
		return n < 5 ? 0 : trailingZeroes(n / 5) + n / 5;
	}
};
