/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;

        if(root->left == nullptr && root->right == nullptr){
            return {to_string(root->val)};
        }

        if (root->left != nullptr)
            ret = binaryTreePaths(root->left);

        if (root->right != nullptr){
            auto vec = binaryTreePaths(root->right);
            ret.insert(ret.end(), vec.begin(), vec.end());
        }

        for(int i = 0 ; i < ret.size(); i++){
            ret[i] = to_string(root->val) + "->" + ret[i];
        }

        return ret;
    }
};