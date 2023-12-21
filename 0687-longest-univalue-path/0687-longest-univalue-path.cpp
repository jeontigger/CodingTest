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
    int maxSame;
    int sameValue(TreeNode* curNode){
        if(curNode == nullptr){
            return 0;
        }

        int left = 0;
        int right = 0;

        if(curNode->left){
            left = sameValue(curNode->left);
            if(curNode->left->val != curNode->val){
                left = 0;
            }
        }

        if(curNode->right){
            right = sameValue(curNode->right);
            if(curNode->right->val != curNode->val){
                right = 0;
            }
        }

        if(maxSame < left + right){
            maxSame = left + right;
        }

        return max(left, right) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        maxSame = 0;
        sameValue(root);

        return maxSame;
    }
};