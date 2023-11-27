//
// Created by Adam on 2023/11/14.
//
#include "iostream"
#include "stack"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void traversal(TreeNode* root,vector<int> &vec){
        if (root == nullptr)return;
        vec.push_back(root->val);
        traversal(root->left,vec);
        traversal(root->right,vec);
    }
    // 递归
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root,vec);
        return vec;
    }
    // 迭代
    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }

    class Solution1 {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;
            if (root != NULL) st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                if (node != NULL) {
                    st.pop();
                    if (node->right) st.push(node->right);  // 右
                    if (node->left) st.push(node->left);    // 左
                    st.push(node);                          // 中
                    st.push(NULL);
                } else {
                    st.pop();
                    node = st.top();
                    st.pop();
                    result.push_back(node->val);
                }
            }
            return result;
        }
    };
};

