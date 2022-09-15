class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {       
        int n=tokens.size();
         if(n==0)
            return 0;
        sort(tokens.begin(),tokens.end());
        int ans=0,f=0,r=n-1,sco=0;        
        if(n==1)
            return power>=tokens[0];
        //two pointers
        do{
            while(power>=tokens[f]){
                power-=tokens[f++];
                sco++;
            }
            ans=max(ans,sco);
           //trade score for more power
            while(sco>=1 && power<tokens[r]){
                power+=tokens[r--];
                sco--;
            }
            
        }while(f<r && (f!=0 && r!=n-1));
        return ans;
    }
};