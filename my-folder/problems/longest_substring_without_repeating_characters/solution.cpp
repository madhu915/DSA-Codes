class Solution {
public:
    // int subs(int l,string s) {
    //     map<char,int>maps;
    //     int r=l;
    //     for(;l<s.size();l++){
    //         if(maps.find(s[l])!=maps.end())
    //             return l-r;
    //         maps[s[l]]=1;
    //     }
    //     return l-r;
    // }
    int lengthOfLongestSubstring(string s) {                
        int n=s.length();
        if(n==0)
            return 0;
        set<char> st;
        int maxsize=0;
        int i=0,j=0;
        while(j<n)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                maxsize=max(maxsize,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxsize;
    }
};