class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> mset;
        for(int i=0;i<paths.size();i++){
            mset[paths[i][0]]=paths[i][1];
        }
        for(int i=0;i<paths.size();i++)
            if(mset.find(paths[i][1])==mset.end())
                return paths[i][1];
        return "";
    }
};