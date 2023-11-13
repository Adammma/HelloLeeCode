//
// Created by Adam on 2023/10/8.
//
/** 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**/
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, vector<int>> hashTable;
        vector<int> result;
        int max = 0;
        int min = 0;
        // check if the number is in table,if yes,put the index into vector;if no, create new vector, and
        // put the index into it.
        for (int i = 0; i < nums.size(); ++i) {
            max = nums[i] > max ? nums[i] : max;
            min = nums[i] < min ? nums[i] : min;
            if (hashTable.find(nums[i]) != hashTable.end()) {
                hashTable[nums[i]].push_back(i);
            } else {
                vector<int> indexSet;
                indexSet.push_back(i);
                hashTable.insert(pair<int, vector<int>>(nums[i], indexSet));
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = target-nums[i];
            if (tmp>max || tmp<min) continue;
            else{
                auto findPair = hashTable.find(tmp);
                if (findPair!=hashTable.end()){
                    for (int j = 0; j < findPair->second.size(); ++j) {
                        if (findPair->second[j]==i) continue;
                        else{
                            result.push_back(i);
                            result.push_back(findPair->second[j]);
                            return result;
                        }
                    }
                }
            }
        }

        return result;
    }
};



//best Solution
class bestSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};