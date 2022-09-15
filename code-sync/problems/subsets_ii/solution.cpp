#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void genSubset(int i,vector<int>& nums,vector<int>& subset,vector<vector<int> >& result) {
        if(i>=nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        genSubset(i+1,nums,subset,result);
        subset.pop_back();
        int val=nums[i];
        while(i!=nums.size() && nums[i]==val) {
            i++;
        }
        genSubset(i,nums,subset,result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        genSubset(0, nums,subset,result);
        return result;
    }
};