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
    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        find(root,path,targetSum);
        return paths;
    }
    void find(TreeNode* root,vector<int>&path, int sum){
        if(!root)
            return;
        path.push_back(root->val);
        if(!(root->left) and !(root->right) and sum==root->val)
            paths.push_back(path);
        find(root->left,path,sum-root->val);
        find(root->right,path,sum-root->val);
        path.pop_back();
    }
};