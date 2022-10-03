class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        set<char>cols(begin(colors),end(colors));
        //no duplicates
        if(cols.size()==colors.size())
            return 0;
        // return 1;
        
        int t=0,prev=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[prev]){
                if(neededTime[prev]<neededTime[i]){
                    t+=neededTime[prev];
                    prev=i;
                }
                else
                    t+=neededTime[i];
            }
            else{
                //update prev
                prev=i;                
            }
            
        }
        return t;
    }
};