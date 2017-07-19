//
// Created by Fennnnng on 2017/7/19.
//
//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


#include "tree.h"


/// 下列程序计算深度[可简单修改变为每个节点深度]
/// - flag是在有子树不满足对称情况下,变为false,但程序未因此终止(因为不会终止),故耗时上稍久!!
/// - 上述缺陷通过查看下下面网友方法解决
class Solution {
    int depth(TreeNode *root, bool *flag) {
        if (root == NULL) return 0;
        int leftlevel = depth(root->left, flag) + 1;
        int rightlevel = depth(root->right, flag) + 1;
        if (leftlevel - rightlevel > 1 || rightlevel - leftlevel > 1) *flag = false;
        return leftlevel > rightlevel ? leftlevel : rightlevel;
    }

public:

    bool isBalanced(TreeNode *root) {
        bool flag = true;
        depth(root, &flag);
        return flag;
    }
};

/// ------------------------Discuss 1-------------------------------
/// 下面是discuss网友方法,和我的思路基本一致,但是利用判断-1提前return
/// 只要子树depth==-1,就提前return直到最后
//class solution {
//public:
//    int dfsHeight (TreeNode *root) {
//        if (root == NULL) return 0;
//
//        int leftHeight = dfsHeight (root -> left);
//        if (leftHeight == -1) return -1;
//        int rightHeight = dfsHeight (root -> right);
//        if (rightHeight == -1) return -1;
//
//        if (abs(leftHeight - rightHeight) > 1)  return -1;
//        return max (leftHeight, rightHeight) + 1;
//    }
//    bool isBalanced(TreeNode *root) {
//        return dfsHeight (root) != -1;
//    }
//};
/// -----------------------Discuss 2------------------------------
/// - 下面是计算深度的简洁代码
/// - 因为判断了NULL,所以尽管上(root->left/right),不必事先if判断是否为空!!
int dp(TreeNode *root) {
    if (root == NULL) return 0;
    return max(dp(root->left), dp(root->right)) + 1;
}
/// ----------------------------------------------------------------



int main110() {
    TreeNode t1 = TreeNode(1);
    TreeNode t21 = TreeNode(2);
    TreeNode t22 = TreeNode(2);
    TreeNode t31 = TreeNode(3);
    TreeNode t32 = TreeNode(3);
    TreeNode t33 = TreeNode(4);
    TreeNode t34 = TreeNode(3);
    t1.left = &t21;
    t1.right = &t22;
    t21.left = &t31;
    t21.right = &t32;
    t22.left = &t33;
    t22.right = &t34;
    Solution s;
    bool r = s.isBalanced(&t1);
//    int r=s.dp(&t1);
    cout << "--------------" << endl;
    cout << r << endl;
    return 0;
}