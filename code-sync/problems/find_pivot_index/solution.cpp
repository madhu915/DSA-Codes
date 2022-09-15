class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(sum==(prefix[n-1]-prefix[i]))
                return i;
            sum=prefix[i];            
        }
        return -1;
    }
};