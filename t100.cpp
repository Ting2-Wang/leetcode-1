//
// Created by Fennnnng on 2017/7/18.
//
//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NULL 0

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 参考Discuss内容
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // return p==q巧妙的将分类描述转为一句话描述
        if(p==NULL||q==NULL) return (p==q);
        // 实际上第二个return也可以融入第三个return!
        if(p->val!=q->val) return false;
        return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};


// 下面程序是DFS遍历demo
// 注意递归的遍历<=>自己设计stack
// DFS->stack   BFS->queue
class Bianli {
public:
    void bianli(TreeNode *p) {
        if(!p) return;
        cout<<p->val<<endl;
        bianli(p->left);
        bianli(p->right);
    }
};
int main100(){
    TreeNode t1 = TreeNode(1);
    TreeNode t2 = TreeNode(2);
    TreeNode t3 = TreeNode(3);
    TreeNode l1 = TreeNode(1);
    TreeNode l2 = TreeNode(2);
    TreeNode l3 = TreeNode(3);
    t1.left = &t2;
    t1.right = &t3;
    l1.left = &l2;
    l1.right = &l3;
    Solution s;
//    s.isSameTree(&t1);
    bool r = s.isSameTree(&t1,&l1);
    cout<<r<<endl;
    return 0;
}