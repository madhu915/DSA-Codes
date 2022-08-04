class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        if(k==num.length())
            return "0";
        for(auto c:num){
            // cout<<res.back()<<endl;
            while(res.length()>0 && res.back()>c && k){
                res.pop_back();
                k--;
            }
            // cout<<res<<"\n";
            if(res.length()>0 || c!='0'){ //leading zeroes
                res+=c;
            }
            // cout<<res<<"\n";
        }
        while(res.length()>0 && k){
            res.pop_back();
            k--;
        }
        return res.length()?res:"0";
    }
};