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
    bool res;
    int checkDepth(TreeNode* _node){
        if(_node == nullptr){
            return 0;
        }
        int left = 0;
        int right = 0;
        if(_node->left){
            left = checkDepth(_node->left);
        }
        if(_node->right){
            right = checkDepth(_node->right);
        }
        if(right - left < -1 || 1 < right - left){
            // cout << _node->val << " " <<  left << " " << right << endl;
            res = false;
        }

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        res = true;
        
        checkDepth(root);

        return res;
    }
};