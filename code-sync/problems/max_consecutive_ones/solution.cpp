class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int msf=0,m=0;
        for(int i:nums){
            if(i==1)
                m++;
            else{
                msf=max(msf,m);
                m=0;
            }
        }
        msf=max(msf,m);        
        return msf;
    }
};