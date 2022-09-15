/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {{}};
        
        map<int,vector<int>> mp;    //{col,val}
        queue<pair<int,TreeNode*>> q;
        vector<vector<int>>ans;
        q.push({0,root});
        while(!q.empty()){
            multiset<pair<int,int>>sets;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                sets.insert({front.first,front.second->val});
                if(front.second->left!=NULL)
                    q.push({front.first-1,front.second->left});
                if(front.second->right!=NULL)
                    q.push({front.first+1,front.second->right});
            }
            for(auto &it:sets)
                mp[it.first].push_back(it.second);
            
        }
        for(auto &it:mp)
            ans.push_back(it.second);
        return ans;
    }
};