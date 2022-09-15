class Solution {
public:    
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int,int>maps;
        // for(int n:nums){
        //     if(maps.find(n)!=maps.end())
        //         return true;
        //     maps[n]++;
        // }
        // return false;
        unordered_set<int> sets(nums.begin(),nums.end());
        return sets.size()!=nums.size();
        
    }
};