//
// Created by Fennnnng on 2017/7/14.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> sum(nums.size());
//        vector<int> a(10,-1);
        int maxsum = nums[0];
        sum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum[i-1]>0){
                sum[i]=sum[i-1]+nums[i];
            }else{
                sum[i]=nums[i];
            }
            maxsum = sum[i]>maxsum?sum[i]:maxsum;
        }
        return maxsum;
    }
};

int main53() {
    Solution s;
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    int r = s.maxSubArray(nums);
    return 0;
}