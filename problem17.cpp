// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const string Phone[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		queue<string> queue;
		for (int i = 0; i < digits.size(); i++)
		{
			string letters = Phone[digits[i] - '0'];
			cout << "letters: " << letters << endl;
			if (queue.empty())
			{
				for (char c : letters)
					queue.push(string(1, c));
			}
			while (queue.front().size() != i + 1)
			{
				string pre = queue.front();
				queue.pop();
				for (char c : letters)
					queue.push(pre + c);
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
