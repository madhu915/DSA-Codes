class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(100);
        dp[0]=nums[0];
        int pick,npick,n=nums.size();
        for(int i=1;i<n;i++){
            pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            npick=dp[i-1];
            dp[i]=max(pick,npick);
        }
        return dp[n-1];
    }
};