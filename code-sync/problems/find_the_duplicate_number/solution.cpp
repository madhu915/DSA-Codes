class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int d,sum=0;
        unordered_set<int>num;
        for(int i:nums){
            if(num.find(i)==num.end()){
                num.insert(i);                
            }
            else{
                d=i;
                break;
            }
        }
        return d;
    }
};