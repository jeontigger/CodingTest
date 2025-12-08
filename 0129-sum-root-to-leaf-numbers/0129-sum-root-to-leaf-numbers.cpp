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
    vector<string> DFS(TreeNode* root){
        if(root == nullptr) return {};
        if(root->left == nullptr && root->right == nullptr){
            return {to_string(root->val)};
        }

        vector<string> ret;

        ret = DFS(root->left);
        auto vec = DFS(root->right);
        ret.insert(ret.end(), vec.begin(), vec.end());

        for(int i = 0 ; i < ret.size(); i++){
            ret[i] = to_string(root->val) + ret[i];
        }

        return ret;
    }

    int sumNumbers(TreeNode* root) {
        int ret = 0;
        auto vec = DFS(root);

        for(const string& str : vec){
            ret += stoi(str);
        }
        
        return ret;
    }
};