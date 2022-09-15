class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            if(words[i].length()!=pattern.length())
                continue;
            int j=-1,fl=0;
            map<char,char> sets;            
            while(++j<pattern.length()) {
                if(sets.find(pattern[j])!=sets.end() && sets[pattern[j]]!=words[i][j])
                    break;
                else{
                    for (auto it=sets.begin(); it!=sets.end(); it++){ 
                        if (it->second == words[i][j] && it->first!=pattern[j]){
                                fl=1;
                                break;
                            }                       
                    }
                    if(fl)
                        break;
                    
                    if(sets.find(pattern[j])==sets.end())
                        sets[pattern[j]]=words[i][j];
                }                
            }
            if(j==pattern.length())
                ans.push_back(words[i]);
             
        }
        return ans;
        
    }
};