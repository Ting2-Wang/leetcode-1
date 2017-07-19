//
// Created by Fennnnng on 2017/7/14.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        unsigned digitsSize = digits.size();
        // 看了人家的结果，实际上只需要一个carry,不需要p这么多
        vector<int> p(digitsSize + 1, 0);
        //plus one
        p[digitsSize] = 1;
        for (int i = digitsSize; i > 0; i--) {
            digits[i - 1] += p[i];
            p[i - 1] = digits[i - 1] / 10;
            // 与其新建vector不如就用p
            // i-1用作进位，i用作存储新值
            p[i] = digits[i - 1] % 10;
        }
        if(p[0]==0) p.erase(p.begin());
        return p;
    }
};


int main66() {
    vector<int> digits;
    digits.push_back(2);
    digits.push_back(9);
    Solution s;
    vector<int> r = s.plusOne(digits);

    return 0;
}