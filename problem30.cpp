// 30. Substring with Concatenation of All Words
// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> idxs;
		if (words.size() == 0 || words[0].size() == 0)
			return idxs;

		unordered_map<string, int> count;
		for (string word : words)
			count[word]++;

		int word_num = words.size();
		int word_len = words[0].size();
		for (int i = 0; i < s.size() - word_len * word_num + 1; i++)
		{
			unordered_map<string, int> seen;
			int j;
			for (j = 0; j < word_num; j++)
			{
				string word = s.substr(i + j * word_len, word_len);
				if (count.find(word) == count.end())
					break;

				seen[word]++;
				if (seen[word] > count[word])
					break;
			}

			if (j == word_num)
				idxs.push_back(i);
		}

		return idxs;
	}
};