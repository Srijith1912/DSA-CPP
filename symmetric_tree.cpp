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

    bool sym(TreeNode* p, TreeNode* q){

        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return sym(p->left, q->right) && sym(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {

        if (!root) return true;
        if (root->left == nullptr && root->right == nullptr) return true;

        return sym(root->left, root->right);

    }
};