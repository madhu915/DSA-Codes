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
    // vector<int>trav;
    // void inorder(TreeNode* root){
        // if(root==NULL)
        //     return;
        // inorder(root->left);
        // trav.push_back(root->val);
        // inorder(root->right);
    // }
    bool isValidBST(TreeNode* root) {
    //     inorder(root);
    //     for(int i=0;i<trav.size()-1;i++){            
    //         if(trav[i]>=trav[i+1])
    //             return false;
    //     }
    //     return true;
        
        return isValidBST(root,LONG_MIN,LONG_MAX);        
    }
    bool isValidBST(TreeNode* root,long long min,long long max){
        if(root==NULL)
            return true;
        if(root->val>=max || root->val<=min)
            return false;
        return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);
    }
};