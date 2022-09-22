class Solution {
public:
    string reverseWords(string s) {
        int ct = 0;
        for(int i=0; i<=s.length(); i++){
            if(i == s.length() or s[i] == ' '){
                int end = i-1;
                while(ct < end){
                    swap(s[ct], s[end]);
                    ct++;
                    end--;
                }
                ct = i+1;
            }
        }
        
        return s;
    }
};