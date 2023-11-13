//
// Created by Adam on 2023/10/12.
//
/** 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 **/
#include "iostream"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //双指针为left/right，i不变，指针收缩
        for (int i = 0; i < nums.size(); i++) {
            //如果排序后第一个元素就>0，则直接返回
            if (nums[i] > 0) return result;
            //去重
            if (i > 0 && nums[i] == nums[i - 1])continue;
            int left = i +1;
            int right = nums.size()-1;
            while (right>left){
                if (nums[i]+nums[left]+nums[right]>0) right--;
                else if (nums[i]+nums[left]+nums[right]<0) left++;
                else{
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    //去重
                    while (right>left&&nums[right] == nums[right-1]) right--;
                    while (right>left&&nums[left] == nums[left+1]) left++;
                    //收缩双指针
                    right--;
                    left++;

                }
            }
        }
        return result;
    }
};