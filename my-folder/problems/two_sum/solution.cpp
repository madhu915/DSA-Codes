class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>pair;
        for(int i=0;i<nums.size();i++){
            if(pair.count(target-nums[i])){
                ans.push_back(i);
                ans.push_back(pair[target-nums[i]]);
            }
            else
                pair[nums[i]]=i;
        }
        return ans;
    }
};