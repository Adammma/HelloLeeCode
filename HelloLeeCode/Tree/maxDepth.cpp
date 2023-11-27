//
// Created by Adam on 2023/11/20.
//
#include "iostream"
#include "queue"
#include "Tree.h"
using namespace std;
class Solution {
public:
    //迭代，层序
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;
        if (root!=NULL) que.push(root);
        while (!que.empty()){
            int size = que.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = que.front();
                que.pop();
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
        }
        return depth;
    }
    // 递归,后序
    int getDepth(TreeNode* root){
        // 返回值，即退出条件
        if (root == NULL) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        int maxDepth = 1+ max(leftDepth,rightDepth);
        return maxDepth;
    }
    int maxDepth1(TreeNode* root){
        int depth = getDepth(root);
        return depth;
    }

};