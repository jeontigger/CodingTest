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
    int BinarySearch(TreeNode* root){
        if(root == nullptr) return 0;

        int sum = 1;
        sum += BinarySearch(root->left);
        sum += BinarySearch(root->right);
        return sum;
    }
    int countNodes(TreeNode* root) {
        return BinarySearch(root);
    }
};