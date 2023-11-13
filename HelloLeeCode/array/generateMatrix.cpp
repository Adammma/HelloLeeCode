//
// Created by Adam on 2023/9/5.
//
/* 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]

 */
#include "iostream"
using namespace std;
// 思路很好，但边界条件太多，不适合这道题
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> resultMatrix (n,vector<int>(n));
        if (n ==1){
            resultMatrix[0][0]= 1;
            return resultMatrix;
        }
        int i = 0 ;
        int j = 0 ;
        int direction = 0;
        int counter = 1;
        int path = n-1;
        int step = 1;
        int rotate_Time = -1;
        while (path>=0){
            resultMatrix[i][j]=counter;

            counter++;
            if (step > path){
                step = 1;
                direction = (direction+1)%4;
                rotate_Time++;
                if (rotate_Time >=2){
                    rotate_Time =1;
                    path -= 1;
                }
            }
            step += 1;
            switch (direction) {
                case 0:
                    j++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    j--;
                    break;
                case 3:
                    i--;
                    break;
            }
        }
        return  resultMatrix;
    }
};
// best solution
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;      // top
        int b = n-1;    // bottom
        int l = 0;      // left
        int r = n-1;    // right
        vector<vector<int>> ans(n,vector<int>(n));
        int k=1;
        while(k<=n*n){
            for(int i=l;i<=r;++i,++k) ans[t][i] = k;
            ++t;
            for(int i=t;i<=b;++i,++k) ans[i][r] = k;
            --r;
            for(int i=r;i>=l;--i,++k) ans[b][i] = k;
            --b;
            for(int i=b;i>=t;--i,++k) ans[i][l] = k;
            ++l;
        }
        return ans;
    }
};
int main(){
    Solution solution;
    int n=1;
    vector<vector<int>> matrix = solution.generateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<matrix[i][j]<<endl;
        }
    }
}