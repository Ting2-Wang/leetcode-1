//
// Created by Fennnnng on 2017/7/14.
//

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        int small = 0;
        int large = x;
        int mid, midval;
        for (;;) {
            mid = (small + large) / 2;
//            midval = mid * mid;
//            将mid*mid<x 改为mid<x/mid !!
//            在运算速度以及越界问题上,二者千差万别啊!!!
            // 按理说应该就近
//            if(mid==small) return x-mid<large*large-x?mid:large;
            if(mid==small) return mid;
            if (mid < x/mid) small = mid;
            else if (mid > x/mid) large = mid;
            else return mid;
        }
    }
};

int main69() {
    Solution s;
    int x = 311625;
    int r = s.mySqrt(x);
    return 0;
}