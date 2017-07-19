/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1, 1, 2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the new length.
*/
#include<vector>
using namespace std;
// 下面方法可用于非排序序列去重复
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i=0;
		bool flag;
		for (int j = 1; j < nums.size(); j++) {
			flag = false;
			for (int k = 0; k <= i; k++) {
				if (nums[k] == nums[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) 	nums[++i] = nums[j];
		}
		return ++i;
	}
};

int main26() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	//nums.push_back(1);
	nums.push_back(2);
	int cnt = s.removeDuplicates(nums);
	return 0;
}