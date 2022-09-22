class Solution {
    public String reverseWords(String s) {
        String[]tokens=s.split(" ");
        String res="";
        StringBuilder ans_=new StringBuilder();
        ans_.append(tokens[0]);
        ans_.reverse();
        res+=ans_;
        for(int i=1;i<tokens.length;i++){
            res+=" ";
            StringBuilder ans=new StringBuilder();
            ans.append(tokens[i]);
            ans.reverse();
            res+=ans;
        }
        return res;
    }
}