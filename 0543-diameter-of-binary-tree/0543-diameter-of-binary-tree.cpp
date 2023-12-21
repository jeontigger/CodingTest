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
    int resDia;
    int DepthAndDiameter(TreeNode* curNode){
        if(curNode == nullptr){
            return 0;
        }
        int left = 0;
        int right = 0;
        if(curNode->left){
            left = DepthAndDiameter(curNode->left);
        }
        if(curNode->right){
            right = DepthAndDiameter(curNode->right);
        }

        int depth = max(left, right);
        int dia = left + right;
        resDia = max(resDia, dia);

        return depth + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        resDia = 0;
        
        DepthAndDiameter(root);


        return resDia;
    }
};