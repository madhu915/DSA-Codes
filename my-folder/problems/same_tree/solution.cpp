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
    bool same=true;
    void dfs(TreeNode* r1,TreeNode *r2){
        if(r1==NULL&&r2==NULL)            
            return;        
        
        if(r1==NULL&&r2!=NULL || r1!=NULL&&r2==NULL ){
          same=false;
            return;
        }
        
        if(r1->val!=r2->val){
          same=false;
            return;
        }
        
        dfs(r1->left,r2->left);
        dfs(r1->right,r2->right);        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p,q);
        return same;
    }
};