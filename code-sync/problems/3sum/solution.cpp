class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 and nums[i]!=nums[i-1])){
                int s=i+1,e=nums.size()-1,sum=-nums[i];
                while(s<e){
                    if(nums[s]+nums[e]==sum){
                        vector<int>sub{nums[i],nums[s],nums[e]};
                        ans.push_back(sub);
                        while(s<e and nums[s]==nums[s+1])
                            s++;
                        while(s<e and nums[e]==nums[e-1])
                            e--;
                        s++;
                        e--;
                    }
                    //sum is less than target hence go forward
                    else if(nums[s]+nums[e]<sum)
                        s++;
                    //sum is more than target hence go backward
                    else
                        e--;
                    
                }
            }
        }
        return ans;
    }
};