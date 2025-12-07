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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return nullptr;
        int n1 = root1 == nullptr ? 0 : root1->val;
        int n2 = root2 == nullptr ? 0 : root2->val;

        TreeNode* Cur = new TreeNode(n1+n2);
        
        TreeNode* l1 = root1 == nullptr ? nullptr : root1->left;
        TreeNode* l2 = root2 == nullptr ? nullptr : root2->left;
        TreeNode* r1 = root1 == nullptr ? nullptr : root1->right;
        TreeNode* r2 = root2 == nullptr ? nullptr : root2->right;
        Cur->left = mergeTrees(l1, l2);
        Cur->right = mergeTrees(r1, r2);

        return Cur;
    }
};