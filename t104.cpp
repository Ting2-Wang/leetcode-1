//
// Created by Fennnnng on 2017/7/18.
//

//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include<iostream>
#include<queue>

using namespace std;
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my BFS solution
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        int maxdepth = 0;
        queue<TreeNode *> q1, q2, tempq;
        TreeNode *temp;
        q1.push(root);
        for (;;) {
            maxdepth++;
            while (!q1.empty()) {
                temp = q1.front();
                if (temp->left) q2.push(temp->left);
                if (temp->right) q2.push(temp->right);
                q1.pop();
            }
            q1 = q2;
            q2 = tempq;
            if (q1.empty()) break;
        }
        return maxdepth;
    }
};
//-----------------------Discuss------------------------
// 网友queue只有一个,借助q.size实行的内部循环!!!
// 思路同我的BFS一致,只不过更简洁!!!
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();

            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }

    return res;
}

int main104() {
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
    int r = s.maxDepth(&t1);
    cout << "--------------" << endl;
    cout << r << endl;
    return 0;
}

