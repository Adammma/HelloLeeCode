//
// Created by Adam on 2023/11/14.
//
#include "iostream"
#include "Tree.h"
#include "stack"
using namespace std;
class Solution {
public:

    void traversal(TreeNode* root,vector<int> &vec){
        if (root == nullptr)return;
        traversal(root->left,vec);
        traversal(root->right,vec);
        vec.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        traversal(root,vec);
        return vec;
    }
    vector<int> postorderTraversal1(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right) st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
    class Solution1 {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            stack<TreeNode*> st;
            if (root != NULL) st.push(root);
            while (!st.empty()) {
                TreeNode* node = st.top();
                if (node != NULL) {
                    st.pop();
                    st.push(node);                          // 中
                    st.push(NULL);

                    if (node->right) st.push(node->right);  // 右
                    if (node->left) st.push(node->left);    // 左

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