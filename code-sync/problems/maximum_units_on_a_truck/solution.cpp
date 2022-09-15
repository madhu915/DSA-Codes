class Solution {
public:
    static bool sortcol(const vector<int>&b1,const vector<int>&b2){
        return b1[1]>b2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int maxx=0;
        sort(boxTypes.begin(),boxTypes.end(),sortcol);//[] (const std::vector<double> &a, const std::vector<double> &b)
        //   {
        //       return a[3] < b[3];
        //   });
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                maxx+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else{
                
                maxx+=truckSize*boxTypes[i][1];
                break;
            }
        }
        return maxx;
    }
};