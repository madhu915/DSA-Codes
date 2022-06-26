class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int index=0,i;
        if(nums.size()==1)
            return index;
        
        if(nums.size()==2){
            return nums[0]>nums[1]?0:1;
        }
        
        for(i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                index=i;
        }
        
        if(nums[nums.size()-1]>nums[nums.size()-2])
            index=i;
        return index;
        
    }
};