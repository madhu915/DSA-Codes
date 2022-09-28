class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int j=0,i=0;//++i j++
        vector<vector<int>>ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        
        while(++i<intervals.size()){
            if(ans[j][1]>=intervals[i][0]){
                ans[j][0]=min(ans[j][0],intervals[i][0]);
                ans[j][1]=max(ans[j][1],intervals[i][1]);
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
                j++;
            }
        }
        return ans;
            
    }
};