// 68. Text Justification
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> justified_lines;
		int n = words.size();
		int idx = 0;

		while (idx < n)
		{
			int line_len = words[idx].size();
			int temp_idx = idx + 1;
			while (temp_idx < n)
			{
				if (line_len + 1 + words[temp_idx].size() > maxWidth)
					break;
				line_len += 1 + words[temp_idx].size();
				temp_idx++;
			}

			string line = words[idx];
			int diff = temp_idx - 1 - idx;

			if (temp_idx == n || diff == 0)
			{
				for (int i = idx + 1; i < temp_idx; i++)
					line += ' ' + words[i];
				for (int i = line_len; i < maxWidth; i++)
					line += ' ';
			}
			else
			{
				int spaces = (maxWidth - line_len) / diff;
				int remain = (maxWidth - line_len) % diff;
				for (int i = idx + 1; i < temp_idx; i++)
				{
					for (int j = 0; j < spaces; j++)
						line += ' ';
					if (remain > 0)
					{
						line += ' ';
						remain--;
					}

					line += ' ' + words[i];
				}
			}

			justified_lines.push_back(line);
			idx = temp_idx;
		}

		return justified_lines;
	}
};