// Write a function to find the longest common prefix string amongst an array of strings.
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pre="";
		// 注意为空的时候的处理！！
		if (strs.size() == 0) return pre;
		char temp;
		for (int cnt=0;cnt<strs[0].size();cnt++) {
			temp = strs[0][cnt];
			for (int j = 0; j < strs.size(); j++) {
				if (cnt >= strs[j].size())
					return pre;
				if (temp != strs[j][cnt]) {
					return pre;
				}
			}
			pre += temp;
		}
		return pre;

	}
};

int main14() {
	vector<string> strs;
	Solution s;
	strs.push_back("str1");
	strs.push_back("str11");
	strs.push_back("str2");
	s.longestCommonPrefix(strs);
	return 0;
}