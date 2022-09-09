class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])  //edge case
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans=0;
        int msf=INT_MIN;
        sort(properties.begin(),properties.end(),comp);
        for(int i=properties.size()-1;i>=0;i--){
            // cout<<properties[i][0]<<" "<<properties[i][1]<<"\n";        
            if(properties[i][1]<msf)
                ans++;           
            msf=max(properties[i][1],msf);
        }
        // cout<<"\n";
        return ans;
    }
};