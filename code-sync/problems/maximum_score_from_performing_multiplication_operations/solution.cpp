class Solution {
public:
    vector<int>dp;
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(multipliers.size()+1);
        for(int i=multipliers.size()-1;i>=0;i--){
            for(int in=0;in<=i;in++)
                dp[in]=max(dp[in+1]+nums[in]*multipliers[i],dp[in]+nums[nums.size()-1+in-i]*multipliers[i]);
        }
   
        return dp[0];
    }
};
