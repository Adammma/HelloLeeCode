//
// Created by Adam on 2023/11/21.
//
#include "iostream"
#include "Tree.h"
using namespace std;
class Solution {
public:
    int getMinDepth(TreeNode* root){
        int minDepth;
        if (root == NULL) return 0;
        int leftDepth = getMinDepth(root->left);
        int rightDepth = getMinDepth(root->right);
        if (leftDepth==0||rightDepth==0) minDepth = 1+max(leftDepth,rightDepth);
        else minDepth = 1+min(leftDepth,rightDepth);
        return minDepth;
    }
    int minDepth(TreeNode* root) {
        int res ;
        res = getMinDepth(root);
        return res;
    }
};