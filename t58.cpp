//
// Created by Fennnnng on 2017/7/14.
//
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sSize = s.size();
        if (sSize == 0) return 0;
        string strOld = "";
        for(;sSize>0;sSize--){
            if(s[sSize-1]!=' ') break;
        }
        for (int i = 0; i < sSize;i++) {
            for (int j = i; j < sSize; j++,i++) {
                if (s[j] == ' ') {
                    strOld = "";
                    break;
                }
                strOld += s[j];
            }
        }
        return strOld.size();
    }
};

int main58() {
    Solution s;
    string str="    day";
    int r = s.lengthOfLastWord(str);
    return 0;
}