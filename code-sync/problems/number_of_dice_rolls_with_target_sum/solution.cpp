class Solution {
public:
    //recursion    
    const long mod=1e9+7;
    vector<vector<int>> dp=vector<vector<int>>(31,vector<int>(1001,-1));
    int numRollsToTarget(int n, int k, int target) {
        //target is true
        if(target==0 and n==0)
            return 1;
        
        //n rolls done or target not true
        if(n==0 or target<=0)
            return 0;
        
        //value in dp exists
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int ans=0;
        // for all possible face values
        for(int i=1;i<=k;i++)
            ans=ans%mod+(numRollsToTarget(n-1,k,target-i))%mod;
        dp[n][target]=ans%mod;
        return dp[n][target];        
    }
};