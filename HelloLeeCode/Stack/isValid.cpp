//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "stack"
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 == 1) return false;
        stack<char> stk;
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case '(':
                    stk.push(s[i]);
                    break;
                case '[':
                    stk.push(s[i]);
                    break;
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if (stk.size()!=0&&stk.top() == '(')
                        stk.pop();
                    else return false;
                    break;
                case ']':
                    if (stk.size()!=0&&stk.top() == '[')
                        stk.pop();
                    else return false;
                    break;
                case '}':
                    if (stk.size()!=0&&stk.top() == '{')
                        stk.pop();
                    else return false;
                    break;
            }
        }
        if (stk.size()!=0) return false;
        return true;
    }
};
int main(){
    Solution solution;
    string s = "()";
    bool res = solution.isValid(s);
    cout<<res<<endl;
    return 0;
}