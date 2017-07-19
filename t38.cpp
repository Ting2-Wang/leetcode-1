//
// Created by Fennnnng on 2017/7/14.
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//Example 1:
//
//Input: 1
//Output: "1"
//Example 2:
//
//Input: 4
//Output: "1211"
//
#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string startStr = "1";
        if (n < 2) return startStr;
        string newStr;
        for (int times = 2; times <= n; times++) {
            newStr = "";
            int cnt = 1;
            int i;
            char cnt_str[256];
            for (i = 1; i < startStr.size(); i++) {
                if (startStr[i - 1] == startStr[i]) {
                    cnt++;
                } else {
                    // int向char数组转换！！ 格式化控制输出
                    sprintf(cnt_str, "%d", cnt);
                    newStr = newStr + cnt_str + startStr[i - 1];
                    cnt = 1;
                }
            }
            sprintf(cnt_str, "%d", cnt);
            newStr = newStr + cnt_str + startStr[i - 1];
            startStr = newStr;
        }
        return startStr;
    }
};

int main38() {

    Solution s;
    int n = 2;
    s.countAndSay(n);
    return 0;
}