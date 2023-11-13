//
// Created by Adam on 2023/9/26.
//
/** 编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 **/
#include "iostream"
#include "unordered_set"
using namespace std;
class Solution {
public:
    int getSum (int n){
        int sum = 0;
        while (n!=0){
            int base = n%10;
            sum += base*base;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> hashTable ;
        while (true){
            int sum = getSum(n);
            cout<<sum<<endl;
            if (sum == 1) return true;
            else{
                auto getSumNum = hashTable.find(sum);
                if (getSumNum == hashTable.end()){
                    hashTable.insert(sum);
                    n = sum;
                } else break;
            }
        }
        return false;
    }
};
int main(){
    int n =3;
    Solution solution;
    bool result = solution.isHappy(n);
    cout<<"result:"<<result<<endl;
}