#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		// ��Ҫ�ǽ�����ջ˼�룬�ͽ��������ŵļӼ�������˼·����
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