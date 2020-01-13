// 127. Word LadderendWord
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// BFS by using queue
class Solution1
{
public:
	int ladderLength(string begin_word, string end_word, vector<string>& word_list)
	{
		unordered_set<string> words(word_list.begin(), word_list.end());
		if (words.find(end_word) == words.end())
			return 0;

		unordered_set<string> visited;
		queue<string> queue;
		queue.push(begin_word);

		int len = 1;
		while (!queue.empty())
		{
			int n = queue.size();
			for (int i = 0; i < n; i++)
			{
				string word = queue.front();
				queue.pop();

				for (int i = 0; i < word.size(); i++)
				{
					char old_char = word[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						word[i] = c;
						if (word == end_word)
							return len + 1;
						if (words.find(word) != words.end() && visited.find(word) == visited.end())
						{// only considers the word which is in the given word set
							visited.insert(word);
							queue.push(word);
						}
					}
					word[i] = old_char;
				}
			}

			len++;  // jumps to the next level of BFS 
		}

		return 0;
	}
};


// A better solution: 2-end BFS
class Solution
{
public:
	int ladderLength(string begin_word, string end_word, vector<string>& word_list) 
	{
		unordered_set<string> words(word_list.begin(), word_list.end());
		if (words.find(end_word) == words.end())
			return 0;

		unordered_set<string> begin_set = { begin_word };
		unordered_set<string> end_set = { end_word };
		unordered_set<string> visited_set;

		int len = 1;
		while (!begin_set.empty() && !end_set.empty())
		{
			unordered_set<string> new_set;
			for (string word : begin_set)
			{
				for (int i = 0; i < word.size(); i++)
				{
					char old_char = word[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == old_char)
							continue;

						word[i] = c;
						if (end_set.find(word) != end_set.end())
							return len + 1;
						if (words.find(word) != words.end() && visited_set.find(word) == visited_set.end())
						{
							visited_set.insert(word);
							new_set.insert(word);
						}

					}
					word[i] = old_char;
				}
			}

			begin_set = new_set;
			if (begin_set.size() > end_set.size())
			{
				unordered_set<string> temp = begin_set;
				begin_set = end_set;
				end_set = temp;
			}

			len++;
		}

		return 0;
	}
};
