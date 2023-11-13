//
// Created by Adam on 2023/10/11.
//
/** 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。


**/
#include "iostream"
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hashTable[26] = {0};
        for(auto i : magazine){
            hashTable[i - 'a']++;
        }
        for(auto i : ransomNote){
            if (hashTable[i-'a']>0){
                hashTable[i-'a']--;
            } else return false;
        }
        return true;
    }
};