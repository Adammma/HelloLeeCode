//
// Created by Adam on 2023/11/13.
//
#include "iostream"
using namespace std;
class Solution {
public:
    void getNext(int* next,string& s){
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i) {
            while (j>=0&&s[i]!= s[j+1]){ //前后缀不同，回退j
                j = next[j];
            }
            if (s[i] == s[j+1]){  //此时的j包含前面的信息，即此时要么：j回退到-1了，还不相等那就是-1；若没回退到根，那就说明有前后缀匹配上了（因为next[j]是包含前面元素的匹配信息的，所以只需要比对回退后的那个元素和当前指向元素。
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int j = -1;
        int next[needle.size()];
        getNext(next,needle);
        for (int i = 0; i < haystack.size(); ++i) {
            while (j >=0 && haystack[i] != needle[j+1]){
                j = next[j];
            }
            if (haystack[i]==needle[j+1]){
                j++;
            }
            if (j == needle.size()-1){
                return i-needle.size()+1;
            }
        }
        return -1;

    }
    bool repeatedSubstringPattern(string s) {
        int next[s.length()];
        getNext(next,s);

        if (next[s.length()-1] != -1 &&s.length() % (s.length()-(next[s.length()-1]+1)) == 0)
            return true;
        return false;
    }

};