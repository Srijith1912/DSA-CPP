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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* tmp = new TreeNode(val);
        TreeNode* r = root;

        if(root == NULL){

            return tmp;
        }
        while(1){

            if (val <= r->val){
                if(r->left == NULL){
                    r->left = tmp;
                    break;
                }
                else{ r = r->left;}
            }
            else{
                if(r->right == NULL){r->right = tmp; break;}
                else{r = r->right;}
            }
        }

        return root;
        
    }
};