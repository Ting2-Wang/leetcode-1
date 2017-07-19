#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		// 主要是借助堆栈思想，和进行有括号的加减法运算思路相似
		vector<char> c;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				c.push_back(s[i]);
			}
			else {
				if (c.size() == 0) {
					return false;
				}
				else {
					switch (c.back()) {
					case '(':
						if (s[i] == ')') c.pop_back();
						else return false;
						break;
					case '[':
						if (s[i] == ']') c.pop_back();
						else return false;
						break;
					case '{':
						if (s[i] == '}') c.pop_back();
						else return false;
						break;
					}
				}
			}
		}
		return c.size() == 0 ;
	}
};

int main20() {
	Solution so;
	bool isval = so.isValid("([)]");
	return 0;
}