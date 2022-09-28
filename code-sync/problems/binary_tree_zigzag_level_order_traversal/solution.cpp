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
    queue<TreeNode*>q;
    bool l2r=true;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        if(!root->left and !root->right)
            return {{root->val}};
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            int s=q.size();
            vector<int>temp(s);
            for(int i=0;i<s;i++){
                TreeNode* front=q.front();
                q.pop();
                int index=(l2r?i:s-i-1);
                temp[index]=front->val;
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                
            }
            l2r=!l2r;
            res.push_back(temp);
        }
        return res;
    }
};