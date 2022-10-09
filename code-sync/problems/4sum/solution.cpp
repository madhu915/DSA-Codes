class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            long t1=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                long t2=t1-nums[j];
                int f=j+1,r=nums.size()-1;
                while(f<r){
                    if(nums[f]+nums[r]==t2){
                        vector<int>q={nums[i],nums[j],nums[f],nums[r]};
                        ans.push_back(q);
                        //handle duplicates
                        while(f<r and nums[f]==q[2])
                            f++;
                        while(f<r and nums[r]==q[3])
                            r--;
                        
                    }
                    else if(nums[f]+nums[r]<t2)
                        f++;
                    else
                        r--;
                }
                
                while(j+1<nums.size() and nums[j]==nums[j+1])
                            j++;
                        
            }
            
            while(i+1<nums.size() and nums[i]==nums[i+1])
                            i++;
                        
        }
        return ans;
    }
};