class Solution {
public:
    int findLength(vector<int>& X, vector<int>& Y) {
        // int ct,res=0,tmp1,tmp2,n=nums1.size(),m=nums2.size();
        // for(int i=0;i<n;i++){
        //     ct=0;
        //     for(int j=0;j<m;j++){
        //         ct=0;
        //         tmp1=i,tmp2=j;               
        //         while(i<n and j<m and nums1[i++]==nums2[j++])
        //             ct++;                  
        //         i=tmp1,j=tmp2;
        //         res=max(res,ct);                
        //     }            
        // }
        // return res;
        // ~BF
        int result = 0,m=X.size(),n=Y.size(); 
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // The first row and first column
                // entries have no logical meaning,
                // they are used only for simplicity
                // of program
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                else if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return result;
    }
};