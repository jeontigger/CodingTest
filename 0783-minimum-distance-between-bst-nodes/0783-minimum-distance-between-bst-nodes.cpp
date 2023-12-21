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
    vector<int> values;
    void Reculsive(TreeNode* node){
        if(node==nullptr){
            return;
        }

        Reculsive(node->left);
        values.push_back(node->val);
        Reculsive(node->right);
        
    }
    int minDiffInBST(TreeNode* root) {
        Reculsive(root);

        int res = values[1] - values[0];
        for(int i = 1 ; i<values.size() - 1 ;i++){
            int value = values[i];
            int nextValue = values[i+1];

            res = min(res, nextValue - value);
        }
        return res;
    }
};