/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > solution;
    void combsum(vector<int>& candidates,int index,vector<int> curr,int target){
        if(target<0)
            return;
        if(target==0)
            solution.push_back(curr);
        for(int i=index; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            combsum(candidates,i,curr,target-candidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        if(candidates.size()==0 || target<0)
            return solution;
        sort(candidates.begin(),candidates.end());
        combsum(candidates,0,curr,target);
        return solution;
    }
};
// @lc code=end

