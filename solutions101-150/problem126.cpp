// 126. Word Ladder II
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution 
{
private:
	void bfs(unordered_map<string, vector<string>>& graph, unordered_map<string, int>& dist_map, unordered_set<string>& words, string& begin_word, string& end_word)
	{
		words.insert(begin_word);
		dist_map[begin_word] = 1;
		queue<string> queue;
		queue.push(begin_word);

		while (!queue.empty())
		{
			bool found_end_word = false;

			int n = queue.size();
			for (int i = 0; i < n; i++)
			{
				string pre_word = queue.front();
				queue.pop();
				int dist = dist_map[pre_word];

				string word = pre_word;
				for (int j = 0; j < word.size(); j++)
				{
					char old_char = word[j];
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (c == old_char)
							continue;

						word[j] = c;
						if (words.find(word) != words.end())
						{
							graph[pre_word].push_back(word);
							if (dist_map.find(word) == dist_map.end())
							{
								dist_map[word] = dist + 1;
								if (word == end_word)
									found_end_word = true;
								else
									queue.push(word);
							}
						}
					}
					word[j] = old_char;
				}
			}

			if (found_end_word)
				break;
		}
	}

	void dfs(unordered_map<string, vector<string>>& graph, unordered_map<string, int>& dist_map, unordered_set<string>& words, string& cur_word, string& end_word,
			 vector<vector<string>>& ladders, vector<string>& cur_ladder)
	{
		cur_ladder.push_back(cur_word);
		if (cur_word == end_word)
		{
			ladders.push_back(cur_ladder);
		}
		else
		{
			int dist = dist_map[cur_word];
			for (string& next_word : graph[cur_word])
			{
				if (dist_map[next_word] == dist + 1)
				{
					dfs(graph, dist_map, words, next_word, end_word, ladders, cur_ladder);
				}
			}
		}
		cur_ladder.pop_back();
	}

public:
	vector<vector<string>> findLadders(string begin_word, string end_word, vector<string>& word_list)
	{
		vector<vector<string>> ladders;
		vector<string> cur_ladder;
		unordered_map<string, vector<string>> graph;
		unordered_map<string, int> dist_map;
		unordered_set<string> words(word_list.begin(), word_list.end());

		bfs(graph, dist_map, words, begin_word, end_word);
		dfs(graph, dist_map, words, begin_word, end_word, ladders, cur_ladder);
		return ladders;
	}
};
