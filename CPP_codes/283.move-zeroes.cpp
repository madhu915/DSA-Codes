/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==0){            
             nums.erase(nums.begin()+i);
             zero++;
            }
            else i++;
        }
        while(zero-->0){
            nums.push_back(0);
        }
    }
};
// @lc code=end

