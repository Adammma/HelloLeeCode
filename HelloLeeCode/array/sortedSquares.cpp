//
// Created by Adam on 2023/9/1.
//
#include "iostream"
using namespace std;
/** 977:给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。



示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
**/

// My Solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sorted;
        int count = 0;
        int left = 0;
        int right = nums.size()-1;
        while (left<=right){
            int left_sq = nums[left]*nums[left];
            int right_sq = nums[right]*nums[right];
            sorted.insert(sorted.end()-count,left_sq>=right_sq?nums[left]*nums[left++]:nums[right]*nums[right++]);
            if (left_sq>=right_sq) left++;
            else right--;
            count++;
        }
        return sorted;
    }
};

//best Solution is My solution!
