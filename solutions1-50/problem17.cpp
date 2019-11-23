// 17. Letter Combinations of a Phone Number
#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const static string PHONE_KEYS[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		queue<string> queue;

		for (int i = 0; i < digits.size(); i++)
		{
			string letters = PHONE_KEYS[digits[i] - '0'];
			if (queue.empty())
			{
				for (char c : letters)
					queue.push(string(1, c));
			}
			else
			{
				while (queue.front().size() != i + 1)
				{
					string pre = queue.front();
					queue.pop();
					for (char c : letters)
						queue.push(pre + c);
				}
			}
		}

		vector<string> combinations;
		while (!queue.empty())
		{
			combinations.push_back(queue.front());
			queue.pop();
		}

		return combinations;
	}
};