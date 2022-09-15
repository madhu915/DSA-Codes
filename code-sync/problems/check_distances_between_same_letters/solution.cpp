class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> alph(26,-1);
        for(int i=0;i<s.size();i++){
            if(alph[s[i]-'a']==-1)
                alph[s[i]-'a']=i;
            else
                alph[s[i]-'a']=i-alph[s[i]-'a']-1;
        }
        for(int i=0;i<distance.size();i++){
            if(alph[i]!=-1 && alph[i]!=distance[i])
                return false;
        }
        return true;
    }
};