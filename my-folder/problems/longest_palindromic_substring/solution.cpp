class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(!n)
            return "";
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        // return "";
        int max_length=0,index=0;
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                max_length = 2;
                index = i;
            }
        }
        for(int i=3;i<=n;i++){
            
            for(int k=0;k<=n-i;k++){
                int j=i+k-1;
                if(s[k]==s[j] && dp[k+1][j-1]==true){
                    dp[k][j]=true;
                    index=k;
                    max_length=max(max_length,i);
                }                    
            }
        }
        string res="";
        if(!max_length)
            return res+s[0];
        for(int i=index;i<max_length+index;i++)
            res+=s[i];
        return res;
    }
};