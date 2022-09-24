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
    bool sum=false;
    void helper(TreeNode* root, int targetSum) {
        if(targetSum-root->val==0 and !(root->left) and !(root->right)){
            sum=true;
            return;
        }
            
        // if(targetSum!=0 and !(root->left) and !(root->right))
        //     return;
        if(root->left)
            hasPathSum(root->left,targetSum-root->val);
        if(root->right)
            hasPathSum(root->right,targetSum-root->val);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;      
        helper(root,targetSum);
        return sum;
    }
};