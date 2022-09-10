class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int msf=INT_MIN; //naive
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         msf=max(msf,prices[j]-prices[i]);
        //     }
        // }
        // return msf<0?0:msf;
       
        // kadane's
        int msf=0,maxCur=0;
        for(int i=1;i<prices.size();i++){   
            maxCur=max(0,maxCur+=(prices[i]-prices[i-1]));
            msf=max(msf,maxCur);
        }
        return msf;
       
    }
};