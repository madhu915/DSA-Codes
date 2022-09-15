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
    int y=0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL) { return 0; }
        int sum = 0;
        if (root->val > L) { sum += rangeSumBST(root->left, L, R); } // left child is a possible candidate.
        if (root->val < R) { sum += rangeSumBST(root->right, L, R); } // right child is a possible candidate.
        if (root->val >= L && root->val <= R) { sum += root->val; } // count root in.
        return sum;
    }
};