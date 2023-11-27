//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "stack"
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (stk.empty()|| stk.top()!=s[i]){
                stk.push(s[i]);
            } else if (stk.top() == s[i]){
                stk.pop();
            }
        }
        if (stk.empty()) return "";
        else{
            while (!stk.empty()){
                res = stk.top()+res;
                stk.pop();
            }
        }
        return  res;
    }
};
int main(){
    Solution solution;
    string s = "abbbabaaa";
    string res = solution.removeDuplicates(s);
    cout<<res<<endl;
    return 0;
}