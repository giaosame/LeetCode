// 22. Generate Parentheses
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	void recurGenerate(vector<string>& res, string parentheses, int left, int right, int n)
	{
		if (right == n)
		{
			res.push_back(parentheses);
			return;
		}

		if (left < n)
			recurGenerate(res, parentheses + '(', left + 1, right, n);
		if (right < left)
			recurGenerate(res, parentheses + ')', left, right + 1, n);
	}

public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		recurGenerate(res, "", 0, 0, n);
		return res;
	}
};
