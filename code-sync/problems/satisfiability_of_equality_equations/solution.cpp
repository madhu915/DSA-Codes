class Solution {
public:
    int parents[26]; //for a-z
    int parent(int x){
        return parents[x]=parents[x]==x?x:parent(parents[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(),equations.end());
        for(int i=0;i<26;i++)
            parents[i]=i;
        
        // equalities taken care of
        for(auto es:equations){
            cout<<es<<" ";
            if(es[1]=='=')
                parents[parent(es[0]-'a')]=parent(es[3]-'a');
        }
        // inequalities
        
        for(auto es:equations){
            if(es[1]=='!' && parent(es[0]-'a')==parent(es[3]-'a') )
                return false;
        }
        return true;
    }    
};