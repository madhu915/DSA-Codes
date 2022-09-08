/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
       
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> ans;        
//         if(root==NULL)
//             return ans;
//         queue<Node*> s;
//         s.push(root);
//         ans.push_back({root->val});
//         while(!s.empty()){
//             int size=s.size();
//             vector<int> lvl; 
            
//             for(int i=0;i<size;i++){
//                 Node* node=s.front();
//                 s.pop();
//                 vector<Node*> child=node->children;
//                 if(!child.empty()){
//                      for(auto i:child){
//                         s.push(i);
//                         lvl.push_back(i->val);
//                     }
//                 }
               
                    
//             }
//             if(!lvl.empty())
//                 ans.push_back(lvl);
            
//         }
//         return ans;
//     }
    vector<vector<int>>ans;
    
    void dfs(Node* root, int level){
        if(root == NULL){
            return;
        }
        if(level == ans.size())
            ans.emplace_back();
        
        ans[level].push_back(root->val);
        vector<Node*>child = root->children;
        for(auto c: child){
            dfs(c, level+1);
        }
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        dfs(root, 0);
        
        return ans;
    }
};