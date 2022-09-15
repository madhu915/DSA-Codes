class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string f=strs[0],l=strs[strs.size()-1],res="";
        for(int i=0;i<f.size();i++){
            if(f[i]!=l[i])
                break;
            else
                res+=f[i];
        }
        return res;
    }
};