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
    unsigned long long value;
    TreeNode* bstToGst(TreeNode* root) {
        if(root == nullptr){
            return root;
        }

        bstToGst(root->right);
        value += root->val;
        root->val = value;
        bstToGst(root->left);


        return root;
    }
};