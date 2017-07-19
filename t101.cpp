//
// Created by Fennnnng on 2017/7/18.
//
#define NULL 0

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//// 下面实现BFS遍历输出
//// 由于为兼容本题目,采取两个循环,两个queue,实际上可以简化
//class Solution {
//public:
//    bool isSymmetric(TreeNode *root) {
//        queue<TreeNode *> q1;
//        TreeNode *temp;
//        q1.push(root);
//        for(;;) {
//            queue<TreeNode *> q2;
//            while (!q1.empty()) {
//                temp = q1.front();
//                cout << temp->val << endl;
//                q1.pop();
//                if(temp->left!=NULL) q2.push(temp->left);
//                if(temp->right!=NULL) q2.push(temp->right);
//            }
//            if(q2.empty()) break;
//            q1 = q2;
//        }
//
//        return false;
//    }
//};

// 自己的笨办法,基于BFS
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        if(root->left==NULL&&root->right==NULL) return true;
        if (root->left == NULL || root->right == NULL) return false;
        queue<TreeNode *> q1;
        TreeNode *temp;
        vector<int> v;
        vector<bool> loc;

        q1.push(root->left);
        q1.push(root->right);
        for (;;) {
            queue<TreeNode *> q2;
            while (!q1.empty()) {
                temp = q1.front();
                v.push_back(temp->val);
                q1.pop();
                if (temp->left != NULL){
                    q2.push(temp->left);
                    loc.push_back(true);
                }else{
                    loc.push_back(false);
                }
                if (temp->right != NULL){
                    q2.push(temp->right);
                    loc.push_back(true);
                }else{
                    loc.push_back(false);
                }
            }
            for(int i=0;i<v.size()/2;i++){
                if(v[i]!=v[v.size()-i-1]) return false;
            }
            for(int i=0;i<loc.size()/2;i++){
                if(loc[i]!=loc[loc.size()-i-1]) return false;
            }
            v.clear();
            loc.clear();
            if (q2.empty()) break;
            q1 = q2;
        }

        return true;
    }
};

int main101() {
    TreeNode t1 = TreeNode(1);
    TreeNode t21 = TreeNode(2);
    TreeNode t22 = TreeNode(2);
//    TreeNode t31 = TreeNode(3);
    TreeNode t32 = TreeNode(3);
//    TreeNode t33 = TreeNode(4);
    TreeNode t34 = TreeNode(3);
    t1.left = &t21;
    t1.right = &t22;
//    t21.left = &t31;
    t21.right = &t32;
//    t22.left = &t33;
    t22.right = &t34;

    Solution s;
//    s.isSameTree(&t1);
    bool r = s.isSymmetric(&t1);
    cout << "--------------" << endl;
    cout << r << endl;
    return 0;
}



////-------------------Discuss---------------------------
//// 网友做法很有条理: left/right两个queue同时进行!!!!!
// Method 2:
///**
// * Definition for binary tree
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    bool isSymmetric(TreeNode *root) {
//        TreeNode *left, *right;
//        if (!root)
//            return true;
//
//        queue<TreeNode*> q1, q2;
//        q1.push(root->left);
//        q2.push(root->right);
//        while (!q1.empty() && !q2.empty()){
//            left = q1.front();
//            q1.pop();
//            right = q2.front();
//            q2.pop();
//            if (NULL == left && NULL == right)
//                continue;
//            if (NULL == left || NULL == right)
//                return false;
//            if (left->val != right->val)
//                return false;
//            q1.push(left->left);
//            q1.push(left->right);
//            q2.push(right->right);
//            q2.push(right->left);
//        }
//        return true;
//    }
//};

// Method 2:
//// 采用递归方式,左右/左右/左右...
//bool isSymmetric(TreeNode *root) {
//    if (!root) return true;
//    return helper(root->left, root->right);
//}
//// helper方式建立自己递归函数(因为输入pq方式同原函数不同)
//bool helper(TreeNode* p, TreeNode* q) {
//    if (!p && !q) {
//        return true;
//    } else if (!p || !q) {
//        return false;
//    }
//
//    if (p->val != q->val) {
//        return false;
//    }
//    // return方式同时参考DFS那道题
//    return helper(p->left,q->right) && helper(p->right, q->left);
//}