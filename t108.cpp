//
// Created by Fennnnng on 2017/7/19.
//

///Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
#include<vector>
#include<iostream>
#include<queue>
#include <algorithm>

using namespace std;
#define NULL 0

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// - old:下列自己的方法会有些许错误,在于重复加入,可通过检验是否已经建立某个点消除
/// - new: 通过查看discuss,采用注释方式标出修改过的地方,就可以AC了!!
// 下面为参考的discuss代码
//class Solution {
//    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
//        if(end<=start) return NULL;
//        int midIdx=(end+start)/2;
//        TreeNode* root=new TreeNode(nums[midIdx]);
//        root->left=sortedArrayToBST(nums, start, midIdx);
//        root->right=sortedArrayToBST(nums, midIdx+1,end);
//        return root;
//    }
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        return sortedArrayToBST(nums, 0,nums.size());
//    }
//};
/// 下面是我的经过修改的代码
///        ### 注意small->mid和mid+1->large的艺术!!!! ###
class Solution {
public:

    TreeNode *helper(vector<int> &nums, int small, int large) {
        // 新增[1]
        if(large<=small) return NULL;
        int mid = (small + large) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        // 删除[2]
//        if (small == mid || large == mid) return root;
        root->left = helper(nums, small, mid);
        // 修改[3]:
        /// 因为int mid=../2是舍1方式,故其值总是偏向small这边,mid+1->large刚好做了平衡
        /// 另外0->1 1->2 实际上是重复的!!!!
//        root->right = helper(nums, mid, large);
        root->right = helper(nums, mid+1, large);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 0) return NULL;

        return helper(nums, 0, nums.size());
    }
};

///// 网友方法
///// - nums数组切片!!
//class Solution {
//public:
//    TreeNode *sortedArrayToBST(vector<int> &num) {
//        if(num.size() == 0) return NULL;
//        if(num.size() == 1)
//        {
//            return new TreeNode(num[0]);
//        }
//
//        int middle = num.size()/2;
//        TreeNode* root = new TreeNode(num[middle]);
//
//        vector<int> leftInts(num.begin(), num.begin()+middle);
//        vector<int> rightInts(num.begin()+middle+1, num.end());
//
//        root->left = sortedArrayToBST(leftInts);
//        root->right = sortedArrayToBST(rightInts);
//
//        return root;
//    }
//};

int main108() {
    Solution s;
    int a[] = {0, 1, 2, 3, 4};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    TreeNode *t = s.sortedArrayToBST(nums);

    return 0;
}