class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> smap;
        for(auto it:magazine){
            if(smap.find(it)!=smap.end()){
                smap[it]++;
            }
            else{
                smap[it]=1;
            }
        }
        for(auto it:ransomNote){
            if(smap.find(it)==smap.end())
                return false;
            if(smap[it]==0)
                return false;
            smap[it]--;
        }
        return true;
    }
};