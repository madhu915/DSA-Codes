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
    int ans=0;
    vector<int>nos=vector<int>(10,0);
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return ans;
    }
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        nos[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int ct=0;
            for(int c:nos){
                if(c%2!=0)
                    ct++;
            }
            if(ct<=1)
                ans++;
        }
        solve(root->left);
        solve(root->right);
        nos[root->val]--;
    }
};