class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        // ans[0][0]=1;
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
            for(int k=1;k<i;k++){
                ans[i][k]=ans[i-1][k-1]+ans[i-1][k];
            }
        }
        return ans;
    }
};