//
// Created by Adam on 2023/11/7.
//
#include "iostream"
using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    void removeExtraSpaces(string& s){
        int slowIndex = 0,fastIndex = 0;
        //将fastIndex放置到第一个单词的第一个字母
        //若非特殊情况将s[fastIndex]的值不断赋给s[slowIndex]，若连续空格，只增fastIndex的值，跳过该空格
        while (s.size()>0&&fastIndex<s.size() && s[fastIndex]==' '){
            fastIndex++;
        }
        for(;fastIndex<s.size();fastIndex++){
            if (fastIndex-1>0&&s[fastIndex-1]==s[fastIndex]&&s[fastIndex]==' '){
                continue;
            } else{
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex-1>0&&s[slowIndex-1] == ' '){
            s.resize(slowIndex-1);
        } else s.resize(slowIndex);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size()|| s[i]==' '){
                reverse(s,start,i-1);
                start = i+1;
            }
        }
        return s;

    }
};