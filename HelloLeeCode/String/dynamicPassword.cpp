//
// Created by Adam on 2023/11/10.
//
#include "iostream"
using namespace std;
class Solution {
public:
    string dynamicPassword(string password, int target) {
        if (target>password.length()) return nullptr;
        reverse(password.begin(),password.begin()+target);
        reverse(password.begin()+target,password.end());
        reverse(password.begin(),password.end());
        return password;
    }
};