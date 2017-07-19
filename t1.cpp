/**
* Note: The returned array must be malloced, assume caller calls free().
*/
# include<malloc.h>
int* twoSum(int* nums, int numsSize, int target) {
	int* index = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i<numsSize - 1; i++) {
		index[0] = i;
		for (int j = i + 1; j<numsSize; j++) {
			index[1] = j;
			if (nums[i] + nums[j] == target) {
				return index;
			}
		}
	}
	return index;
}
int main1() {
	int nums[] = { -1,-2,-3,-4,-5 };
	int numsSize = 5;
	int target = -8;
	int* index = twoSum(nums, numsSize, target);
	free(index);
	return 0;
}