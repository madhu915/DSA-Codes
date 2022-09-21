class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),r=queries.size(),sum=0;
        vector<int>ans(r);
        for(auto k:nums){
            if(!(k&1))
                sum+=k;
        }
        
        for(int i=0;i<r;i++){
            //even num
            if(!(nums[queries[i][1]]&1)){
                sum-=nums[queries[i][1]];
            }
            //odd num
            nums[queries[i][1]]+=queries[i][0];
            if(!(nums[queries[i][1]]&1))
                sum+=nums[queries[i][1]];
            ans[i]=sum;
        }
        return ans;
    }
};