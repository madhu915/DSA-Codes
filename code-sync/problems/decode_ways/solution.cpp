class Solution {
public:
    vector<int>dp=vector<int>(101,0);
    int numDecodings(string s) {
        return solve(0,s);
    }
    int solve(int i,string& s){
        //reached end
        if(s.size()==i)
            return 1;
        if(dp[i]!=0)
            return dp[i];
        int ways=0;
        //single digit
        if(s[i]!='0')
            ways+=solve(i+1,s);
        //2-digit
        if(i+1<s.size() and( (s[i]=='1' and s[i+1]<='9') or (s[i]=='2' and s[i+1]<='6') ) )
            ways+=solve(i+2,s);
        dp[i]=ways;
        return dp[i];
    }
};