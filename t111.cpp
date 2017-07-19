//
// Created by Fennnnng on 2017/7/19.
//
#include "tree.h"
/// 一次性AC
/// 注意NULL不算做叶子,return的时候逻辑要清晰
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int leftdepth = minDepth(root->left) + 1;
        int rightdepth = minDepth(root->right) + 1;
        // 这里的逻辑是:同时到尽头的话就视为leaf,return 1
        if (leftdepth == 1 && rightdepth == 1) return 1;
        // 如果没同时到尽头(因为前面有return),则这里不是leaf,不能直接return min,要以max为准
        if(leftdepth==1||rightdepth==1) return max(leftdepth, rightdepth);
        // 自下而上的组合是按照min组合的逻辑
        return min(leftdepth, rightdepth);
    }
};

int main111() {
    Solution s;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t21 = new TreeNode(2);
    TreeNode *t22 = new TreeNode(2);
    TreeNode *t31 = new TreeNode(3);
    TreeNode *t32 = new TreeNode(3);
    TreeNode *t33 = new TreeNode(4);
    TreeNode *t34 = new TreeNode(3);
    t1->left = t21;
    t1->right = t22;
    t21->left = t31;
    t21->right = t32;
    t22->left = t33;
    t33->right = t34;
    int r = s.minDepth(t1);
    cout<<r<<endl;
    return 0;
}