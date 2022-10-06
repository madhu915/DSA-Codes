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
    priority_queue<int,vector<int>,greater<int>>pq;
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        // pq.push(root->val);
        while(!q.empty()){
            TreeNode* fr=q.front();
            q.pop();
            if(fr->left){
                q.push(fr->left);
            }
             if(fr->right){
                q.push(fr->right);            
            }
            pq.push(fr->val);
            
        }
        int t;
        while(k--){
            t=pq.top();
            pq.pop();
            
        }
        return t;
    }
};