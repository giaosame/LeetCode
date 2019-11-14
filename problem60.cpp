// 60. Permutation Sequence
#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		int* factorials = new int[n + 1];
		factorials[0] = 1;
		string number;
		for (int i = 1; i <= n; i++)
		{
			factorials[i] = factorials[i - 1] * i;
			number += i + '0';
		}

		k--;
		string permutation;
		for (int i = 1; i <= n; i++)
		{
			int index = k / factorials[n - i];
			permutation += number[index];
			number = number.erase(index, 1);  // number = number.substr(0, index) + number.substr(index + 1);
			k -= index * factorials[n - i];
		}

		return permutation;
	}
};