class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int first = 0 ; first < nums.size()-2 ; ++first) {
            
            if(first==0 || (first > 0 && nums[first] != nums[first-1])){
                int second = first+1;
                int third = nums.size()-1;            
                while(second < third) {
                    int Sum = nums[first]+nums[second]+nums[third];
                    //closest equals sum 
                    if(Sum == target) return Sum;
                    if(abs(target-Sum)<abs(target-closest)) {
                        closest = Sum;
                    }
                    if(Sum > target) {
                        --third;
                    } else {
                        ++second;
                    }
                }
            }
            
        }
        return closest;
        
    }
};