//
// Created by Fennnnng on 2017/7/14.
//
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int m = 0;
        // 二进制
        int scale = 2;
        int asize = a.size();
        int bsize = b.size();
        if (asize < bsize) a.insert(0, bsize - asize, '0');
        else b.insert(0, asize - bsize, '0');
        for (int i = a.size() - 1; i > -1; i--) {
            m = carry + a[i] + b[i] - 2 * '0';
            carry = m / scale;
            a[i] = (char)(m % scale + '0');
        }
        if(carry) a.insert(0,1,'1');
        return a;
    }
};

int main67() {
    Solution s;
    string a = "1";
    string b = "11";
    string r = s.addBinary(a, b);

    return 0;
}