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
    int minDepth(TreeNode* root) {

        if(!root) return 0;
        if (!root->left && !root->right) return 1;

        int l = minDepth(root->left);
        int r = minDepth(root->right);

        if (!root->left) return 1+r;
        if (!root->right) return 1+l;

        return min(l, r)+1;
        
    }
};