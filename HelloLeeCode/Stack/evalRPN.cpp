//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "stack"
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1+num2);
            } else if (tokens[i]=="-"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2-num1);
            }else if (tokens[i]=="*"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num1*num2);
            }
            else if (tokens[i]=="/"){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2/num1);
            } else{
                int num = stoi(tokens[i]);
                nums.push(num);
            }
        }
        return nums.top();
    }
};
int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    Solution solution;
    int res = solution.evalRPN(tokens);
    cout <<res<<endl;
    return 0;
}