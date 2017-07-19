//
// Created by Fennnnng on 2017/7/14.
//

#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int small = 0;
        int big = nums.size() - 1;
        if (target <= nums[small]) return small;
        if (target > nums[big]) return big + 1;
        int mid;
        for (;;) {
            mid = (small + big) / 2;
            if (mid == small) return small+1;
            if (nums[mid] < target) small = mid;
            else if (nums[mid] > target) big = mid;
            else return mid;
        }
    }
};

int main35() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 7;
    int r = s.searchInsert(nums, target);
    return 0;
}