//
// Created by Adam on 2023/11/16.
//
#include "iostream"
#include "Tree.h"
#include "queue"
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> res;
        while (!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                if (i == size-1) res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode;
    TreeNode* node2 = new TreeNode;
    TreeNode* node3 = new TreeNode;
    TreeNode* node4 = new TreeNode;
    TreeNode* node5 = new TreeNode;
    root->val = 1;
    node2->val=2;
    node3->val=3;
    node4->val=4;
    node5->val=5;
    root->left= node2;
    root->right = node3;
    node2->right = node5;
    node3->right = node4;


    Solution solution;

    vector<int> res = solution.rightSideView(root);
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<endl;
    }
    return 0;

}