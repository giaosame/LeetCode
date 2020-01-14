// 140. Word Break II
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Using DFS directly will lead to TLE.
// Uses unordered_map to save the previous results to prune duplicated branches to prevent TLE problem.
class Solution 
{
	vector<string> recurBreak(string s, unordered_set<string>& words, unordered_map<string, vector<string>>& map)
	{
		if (map.find(s) != map.end())
			return map[s];

		vector<string> broken_words;
		if (s.empty())
		{
			broken_words.push_back("");
			return broken_words;
		}

		for (string word : words)
		{
			if (s.find(word) == 0)
			{
				vector<string> next_broken_words = recurBreak(s.substr(word.size()), words, map);
				for (string& next_word : next_broken_words)
				{
					if (next_word.empty())
						broken_words.push_back(word);
					else
						broken_words.push_back(word + " " + next_word);
				}
			}
		}

		map[s] = broken_words;
		return broken_words;
	}

public:
	vector<string> wordBreak(string s, vector<string>& word_dict)
	{
		unordered_set<string> words(word_dict.begin(), word_dict.end());
		unordered_map<string, vector<string>> map;
		return recurBreak(s, words, map);
	}
};
