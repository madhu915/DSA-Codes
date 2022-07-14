#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int j=0; j<matrix.size(); j++) {
            reverse(matrix[j].begin(), matrix[j].end());
        }
        
    }
};