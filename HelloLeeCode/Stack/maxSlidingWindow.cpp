//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "queue"
using namespace std;
class Solution {
public:
    class MyQueue{
    public:
        deque<int> que;
        void pop(int value){
            //如果滑动窗口中，要出去的值刚好是窗口中最大值，那么就要比一下，把que中最大值也就是出口弹出去，如果不是最大值，那说明
            //最大值还在窗口內，就不用管了
            if (!que.empty() && value == que.front()){
                que.pop_front();
            }
        }
        void push(int value){
            //如果入口值比value大，那就直接push进去，小的话就pop掉，一直到没有比value小的
            while (!que.empty()&& value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};