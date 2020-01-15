// 150. Evaluate Reverse Polish Notation
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> stk;
		for (string& token : tokens)
		{
			if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
			{
				stk.push(stoi(token));
			}
			else
			{
				int num2 = stk.top();
				stk.pop();
				int num1 = stk.top();
				stk.pop();

				int res;
				if (token == "+")
					res = num1 + num2;
				else if (token == "-")
					res = num1 - num2;
				else if (token == "*")
					res = num1 * num2;
				else if (token == "/")
					res = num1 / num2;

				stk.push(res);
			}
		}

		return stk.top();
	}
};
