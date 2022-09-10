class Solution {
public:
    //constraints
    vector< vector< vector<int> > > dp=vector< vector< vector<int> > >(1001 , vector< vector<int> > (2, vector<int> (101, -1) ) );
    // vector<vector<vector<int>>>dp(1001,vector<vector<int>>(2,vector<int>(101,-1)));
    int solve(int i,int j,int k,vector<int>& prices){
        if(i>=prices.size())
            return 0;
        if(k<=0)
            return 0;
        
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        //given a stock is bought that day either sell or ignore 
        // sell - k-1 -> 1 transaction down i.e 1 buy + 1 sell // ignore - k - no change
        if(j){
            dp[i][1][k]=max(solve(i+1,1,k,prices),prices[i]+solve(i+1,0,k-1,prices));                   return dp[i][1][k];
        }
        //given a stock is not bought yet either buy or ignore
        //no change in k for both cases
        else{
            dp[i][0][k]=max(solve(i+1,0,k,prices),solve(i+1,1,k,prices)-prices[i]);                   return dp[i][0][k];
            
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
    }
};