//
// Created by Fennnnng on 2017/7/14.
//
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (unsigned int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};

int main28() {
    Solution s;
    string str1 = "abb";
    string str2 = "abaaaa";
    int pos = s.strStr(str1, str2);
    return 0;
}