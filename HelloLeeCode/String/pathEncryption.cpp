//
// Created by Adam on 2023/11/2.
//
#include "iostream"
using namespace std;
class Solution {
public:
    string pathEncryption(string path) {
        for (int i = 0; i < path.length(); ++i) {
            path[i] = path[i] == '.' ? ' ': path[i];
        }
        return path;
    }
};