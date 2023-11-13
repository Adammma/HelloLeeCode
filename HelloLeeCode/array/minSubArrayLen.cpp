//
// Created by Adam on 2023/9/1.
//
#include "iostream"
using namespace std;
/* 给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 */

// my solution
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slowIndex =0;
        int fastIndex = 0;
        int minLength = nums.size();
        int current_sum = nums[0];
        while (fastIndex<nums.size()){
            if (slowIndex == 0 && fastIndex == nums.size()-1 && current_sum<target){
                minLength = 0;
                break;
            }
            if (slowIndex>fastIndex)return 1;
            if (current_sum<target){
                if(fastIndex == nums.size()-1) break;
                fastIndex++;
                current_sum += nums[fastIndex];
            } else {
                minLength = fastIndex-slowIndex+1 > minLength ? minLength : (fastIndex-slowIndex+1);
                current_sum -= nums[slowIndex++];
            }

        }
        return  minLength;
    }
};




int main(){
    vector<int> nums = {1,1,1,1,1,1,1,1};
    int target = 11;
    Solution solution;
    int ret = solution.minSubArrayLen(target,nums);
    cout << "ret:"<<ret<<endl;
}