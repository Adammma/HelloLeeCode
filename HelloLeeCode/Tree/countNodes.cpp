//
// Created by Adam on 2023/11/21.
//
#include "iostream"
#include "Tree.h"
#include "queue"
using namespace std;
class Solution {
public:
    // 判断以root为根节点的树是否为满二叉树，若为满二叉树，返回其深度，若不是满二叉树，返回-1；
    int isFull(TreeNode* root){
        int leftDepth = 0;
        int rightDepth = 0;
        if (root == NULL) return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        while (leftNode!=NULL){
            leftDepth++;
            leftNode = leftNode->left;
        }
        while (rightNode!=NULL){
            rightDepth++;
            rightNode = rightNode->right;
        }
        if (leftDepth!= rightDepth) return -1;
        else return leftDepth;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int res = isFull(root);
        if (res>=0) return (2<<res)-1;
        return countNodes(root->left)+ countNodes(root->right)+1;

    }
};