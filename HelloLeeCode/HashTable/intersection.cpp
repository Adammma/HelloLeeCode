//
// Created by Adam on 2023/9/22.
//
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result ;
        int hashTable[1000] = {0};
        for (int i = 0; i < nums1.size(); ++i) {
            hashTable[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (hashTable[nums2[i]] ==1){
                result.push_back(nums2[i]);
                hashTable[nums2[i]]++;
            }
        }
        return result;
    }
};

int main(){
    vector<int> num1 = {1,2,2,1};
    vector<int> num2 = {2,2};
    Solution* solution = new Solution;
    vector<int> result = solution->intersection(num1,num2);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }
}