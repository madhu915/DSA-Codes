class Solution {
public:
    string breakPalindrome(string pal) {
        if(pal.size()<2)
            return "";
        int st=0,end=pal.size();
        while(st<end/2){
            if(pal[st]!='a'){
                pal[st]='a';
                return pal;
            }
            
            st++;
            
        }
        pal[pal.size()-1]='b';
        return pal;
    }
};