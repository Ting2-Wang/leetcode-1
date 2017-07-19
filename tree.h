//
// Created by Fennnnng on 2017/7/19.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#endif //LEETCODE_TREE_H
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
