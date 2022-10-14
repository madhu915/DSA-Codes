class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0,fl=1,fl2=-1;
        int s=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++){
            if(s<=nums[i])
                fl=0;
            else{
                fl2=0;
                sum=max(sum,s+nums[i]);
            }
            s-=nums[i-2];
            s+=nums[i];
        }
        if(fl2==-1)
            return 0;
        return sum;
    }
};