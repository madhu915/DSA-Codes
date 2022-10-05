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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *node=new TreeNode(val,root,NULL);
            return node;
        }
        
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            auto tmp=st.top();
            st.pop();
            if(tmp.first==NULL)
                continue;
            if(tmp.second==depth-1){
                TreeNode* t=tmp.first->left;
                tmp.first->left=new TreeNode(val);
                tmp.first->left->left=t;
                t=tmp.first->right;
                tmp.first->right=new TreeNode(val);
                tmp.first->right->right=t;
                
            }
            else{
                st.push({tmp.first->left,tmp.second+1});
                st.push({tmp.first->right,tmp.second+1});
            }
        }
        return root;
            
    }
};