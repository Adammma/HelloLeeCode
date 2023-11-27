//
// Created by Adam on 2023/11/16.
//
#include "iostream"
#include "Tree.h"
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }
};