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
    vector<int>inor;
    int s;
    bool findTarget(TreeNode* root, int k) {
        
        inorder(root);      
        int st=0,end=inor.size()-1;
        cout<<end;
        while(st<end){
            if(k==inor[st]+inor[end])
                return true;
            if(k<inor[st]+inor[end])
                end--;
            else
                st++;
        }
        return false;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        inor.push_back(root->val);
        inorder(root->right);
    }
};