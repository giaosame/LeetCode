// 151. Reverse Words in a String
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution1
{
public:
	string reverseWords(string s)
	{
		vector<string> words;
		stringstream ss(s);
		string token;

		while (ss >> token)
		{
			words.push_back(token);
		}

		if (words.empty())
			return "";

		string res = words.back();
		for (int i = words.size() - 2; i >= 0; i--)
			res += " " + words[i];

		return res;
	}
};


// First, reverse the whole string
// Second, reverse each of the word, and remove extra blanks in the same time		
class Solution2 
{
public:
	string reverseWords(string s) 
	{
		reverse(s.begin(), s.end());
		int idx = 0;
		int n = s.size();

		for (int i = 0; i < n; i++)
		{
			if (s[i] == ' ')
				continue;

			if (idx != 0)
				s[idx++] = ' ';
			int j = i;
			while (j < n && s[j] != ' ')
				s[idx++] = s[j++];
			reverse(s.begin() + idx - (j - i), s.begin() + idx);
			i = j;
		}

		s.erase(s.begin() + idx, s.end());
		return s;
	}
};
