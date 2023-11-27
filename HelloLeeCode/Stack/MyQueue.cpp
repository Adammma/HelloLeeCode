//
// Created by Adam on 2023/11/13.
//
#include "iostream"
#include "stack"
using namespace std;
class MyQueue {
public:

    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);
    }
    //  将stIn中元素取出，放入stOut中，前提是stIn非空且stOut为空
    void inToOut(){
        int len = stIn.size();
        for (int i = 0; i < len; ++i) {
            int tmp = stIn.top();
            stIn.pop();
            stOut.push(tmp);
        }
    }
    int pop() {
        int tmp=0;
        if (stOut.size()!=0){
            tmp = stOut.top();
            stOut.pop();
        } else if (stIn.size()!= 0 && stOut.size() == 0){
            inToOut();
            tmp = stOut.top();
            stOut.pop();
        } else return -1;
        return tmp;
    }

    int peek() {
        int tmp = 0;
        if (stOut.size() != 0 ){
            tmp = stOut.top();
        } else if (stIn.size()!=0 && stOut.size() == 0){
            inToOut();
            tmp = stOut.top();
        } else return -1;
        return  tmp;
    }

    bool empty() {
        bool res = (stIn.size()==0)&&(stOut.size()==0);
        return res;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */