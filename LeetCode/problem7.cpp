// 7. Reverse Integer
// Given a 32-bit signed integer, reverse digits of an integer.
class Solution {
public:
	int reverse(int x) {
		long reversed_int = 0;
		while (x != 0)
		{
			int temp = 10 * reversed_int + x % 10;
			if (temp / 10 != reversed_int)
				return 0;
			x /= 10;
			reversed_int = temp;
		}

		return reversed_int;
	}
};