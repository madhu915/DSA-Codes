class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
            return true;
        string org=s;
        s=s.substr(1)+s[0];
        while(s!=goal && s!=org){
            cout<<s<<"\n";
            if(s==goal)
                return true;
            s=s.substr(1)+s[0];
        }
        if(s==goal)
            return true;
        return false;
    }
};