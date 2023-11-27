//
// Created by Adam on 2023/11/17.
//
#include "iostream"
#include "Tree.h"
#include "stack"
#include "queue"
using namespace std;
class Solution {
public:
    bool compare(TreeNode* left,TreeNode* right){
        if (left == NULL&& right == NULL)return true;
        else if (left == NULL && right!= NULL) return false;
        else if (left !=NULL&& right == NULL) return false;
        else if (left->val!= right->val) return false;

        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);
        bool isSame = outside&&inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left,root->right);
    }
};