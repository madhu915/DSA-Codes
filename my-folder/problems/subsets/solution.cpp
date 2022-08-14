class Solution {
public:
    vector<vector<int>> res;
    int i,n;
    void solve(int ind, vector<int>&sub, vector<int>nums){
        if(sub.size()==i){
            res.push_back(sub);
            return;
        }
        for(int j=ind;j<n;j++){
            sub.push_back(nums[j]);
            solve(j+1,sub,nums);
            sub.pop_back();
        }
            
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int>sub;
        for(i=0;i<n+1;i++)
            solve(0,sub,nums);
        return res;
    }
};