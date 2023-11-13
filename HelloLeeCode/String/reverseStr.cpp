//
// Created by Adam on 2023/10/31.
//
#include "iostream"
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int left_num = s.length()% (k*2);
        int reverse_num = (s.length()-left_num)/(k*2);
        int all_left = 0;
        int all_right = k-1;
        for (int i = 0; i < reverse_num; ++i) {
            int left = all_left;
            int right = all_right;
            while (left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            all_left += k*2;
            all_right += k*2;
        }
        all_right = s.length()-1;

        if (left_num == 0 ||left_num == 1){
            return s;
        }
        if (left_num<k){
            int left = all_left;
            int right = all_right;
            while (left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        } else if (k<=left_num<k*2){
            int left = all_left;
            int right = left + k -1;
            while (left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;

    }
};