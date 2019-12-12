// 71. Simplify Path
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> stk;
		stringstream ss(path);
		string token;

		while (getline(ss, token, '/'))
		{
			if (token == "" || token == ".")
				continue;
			else if (token == "..")
			{
				if (!stk.empty())
					stk.pop_back();
			}
			else
				stk.push_back(token);
		}

		string canonical_path;
		for (string str : stk)
			canonical_path += '/' + str;

		if (canonical_path.empty())
			return "/";
		return canonical_path;
	}
};