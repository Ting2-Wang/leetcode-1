//
// Created by Fennnnng on 2017/7/14.
//
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//        You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int cnt = 0;
        int i = 0, j = 0;
        // 注意这里,因为erase之后vector变化,size变化,元素位置也变化
        // 故不可同普通int[]一样用for(int k=0;;) .. 之类的方式
        // 这里应该处理的是nums1.erase(nums1.begin() + m);  注意这个m!!!
        int eraseLoop1 = nums1.size() - m;
        int eraseLoop2 = nums2.size() - n;
        while (eraseLoop1--) {
            nums1.erase(nums1.begin() + m);
        }
        while (eraseLoop2--) {
            nums2.erase(nums2.begin() + n);
        }
        for (; i < m; i++) {
            for (; j < n;) {
                if (i == m) break;
                if (j == n) break;
                if (nums1[i + j] < nums2[j]) {
                    i++;
                } else {
                    nums1.insert(nums1.begin() + i + j, nums2[j]);
                    j++;
                }
            }

        }
        // i/j必有一个是完全的
        // - 如果i没完,不用管,因为输出的是nums1
        // - 如果j没完,就需要进行copy
        for (int k = j; k < n; k++) {
            nums1.push_back(nums2[k]);
        }


    }
};

int main88() {
    Solution s;
    int a[] = {1, 2, 3, 0, 0, 0};
    int b[] = {1};
    vector<int> nums1(a, a + 6);
    vector<int> nums2(b, b + 1);
    s.merge(nums1, 3, nums2, 1);
    return 0;
}