//
// You are climbing a stair case. It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//Note: Given n will be a positive integer.
//
// 其实这就是斐波那契数列,因为当前走法,先走1还是2,分两种情况,剩下的走法种类就是之前的走法.

#include <math.h>
class Solution {
public:
    int climbStairs(int n) {
        // 方法1:
//        利用斐波那契数列公式直接求解,开销主要在math相关函数的调用上
//        if(n<2) return 1;
//        double x1 = (1-sqrt(5))/2;
//        double x2 = (1+sqrt(5))/2;
//        return int(round((-pow(x1,n+1)+pow(x2,n+1))/sqrt(5)));

        // 方法2:
        // 正常方法为递归 -----------------------
        // 实际上简单递归可以有固定次数的for循环取代
        int f=1,f1=2,f2;
        if(n<2) return f;
        for(int i=1;i<n;i++){
            f2 = f1+f;
            f=f1;
            f1=f2;
        }
        return f;
    }
};

int main70() {
    Solution s;
    int n = 5;
    int r = s.climbStairs(n);
    return 0;
}