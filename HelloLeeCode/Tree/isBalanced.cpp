//
// Created by Adam on 2023/11/27.
//
#include "iostream"
#include "Tree.h"
using namespace std;
class Solution {
public:
    int getHeight(TreeNode* node){
        if (node == NULL) return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        int height = abs(leftHeight-rightHeight);
        if (height>1) return -1;
        return 1+ max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)return true;
        int height = getHeight(root);
        if (height == -1)return false;
        return true;
    }
};