class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // if(changed.size()%2!=0)
        //     return {};
        // vector<int>ans;
        // sort(changed.begin(),changed.end());
        // // int n=changed.size();
        // for(int i=0;i<changed.size();i++){
        //     auto it=find(changed.begin()+i+1,changed.end(),2*changed[i]);
        //     if(it==changed.end())
        //         return {};
        //     else{
        //         // ans.push_back(changed[i]);
        //         // changed.erase(changed.begin()+i);
        //         changed.erase(it);
        //         // n--;
        //         // i++;
        //     }
        // }
        // return changed;  ~TLE
        int n=changed.size();
        if(n%2!=0)
            return {};
        unordered_map<int,int> mp;
        vector<int>ans;
        sort(changed.begin(),changed.end());
        for(auto i:changed)
            mp[i]++;
        for(auto i:changed){
            if(mp[i]==0)
                continue;

            if(mp[i*2]==0)
                return {};
            ans.push_back(i);
            mp[i*2]--;
            mp[i]--;
        }
        return ans;
    }
};