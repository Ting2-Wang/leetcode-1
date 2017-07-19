//
// Created by Fennnnng on 2017/7/18.
//
//
//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//  [15,7],
//  [9,20],
//  [3]
//]
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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> seq;
        queue<TreeNode *> q;
        TreeNode *temp;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0, n = q.size(); i < n; i++) {
                temp = q.front();
                seq.push_back(temp->val);
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            res.push_back(seq);
            seq.clear();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main107() {
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
    t33.right = &t34;
    Solution s;
    vector<vector<int>> r = s.levelOrderBottom(&t1);
    cout << "--------------" << endl;
    return 0;
}


//------------------------------Discuss--------------------------------------
/// 下面是网友解法 DFS
///level用于标记所在层数,这就是可以用DFS的原因!!!

vector<vector<int> > res;
// 注意这里DFS的第二个参数!!
void DFS(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == res.size()) // The level does not exist in output
    {
        res.push_back(vector<int>()); // Create a new level
    }

    res[level].push_back(root->val); // Add the current value to its level
    /// 注意level+1而非level++,因为不做改变level值,否则left遍历/right遍历之后,level会一直增大!!!
    DFS(root->left, level+1); // Go to the next level
    DFS(root->right,level+1);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    DFS(root, 0);
    return vector<vector<int> > (res.rbegin(), res.rend());
}