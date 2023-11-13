//
// Created by Adam on 2023/10/9.
//
/** 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

**/
#include "iostream"
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int ,int> hashMap;
        for(int a:nums1){
            for(int b:nums2){
                auto abSum = hashMap.find(a+b);
                if (abSum != hashMap.end()) abSum->second++;
                else hashMap.insert(pair<int,int>(a+b,1));
            }
        }
        for(int c:nums3){
            for(int d:nums4){
                if (hashMap.find(0-(c+d))!=hashMap.end())
                    count += hashMap.find(0-(c+d))->second;
            }
        }
        return count;
    }
};