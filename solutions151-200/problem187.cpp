// 187. Repeated DNA Sequences
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 
{
public:
	vector<string> findRepeatedDnaSequences(string s) 
	{
		vector<string> seqs;
		if (s.size() < 10)
			return seqs;

		unordered_map<string, int> map;
		for (int i = 0; i < s.size() - 9; i++)
		{
			string seq = s.substr(i, 10);
			int cnt = ++map[seq];
			if (cnt == 2)
				seqs.push_back(seq);
		}

		return seqs;
	}
};
