//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "queue"
using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    // curNum = 1: 当前栈底在1
    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int res = 0;
        int length = que1.size();
        for (int i = 0; i < length-1; ++i) {
            int tmp = que1.front();
            que1.pop();
            que2.push(tmp);
        }
        res = que1.front();
        que1.pop();
        que1 = que2;
        while (que2.size()!= 0){
            que2.pop();
        }
        return res;
    }

    int top() {

        return que1.back();
    }

    bool empty() {
        bool res = (que1.size()==0)&&(que2.size()==0);
        return res;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */