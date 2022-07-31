class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int a=1,b=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]>nums[i-1])
                a=b+1;
            else /*(nums[i]<nums[i-1])*/{
                b=a+1;
                
            }
            
        
        }
        return max(a,b);
        
    }
};