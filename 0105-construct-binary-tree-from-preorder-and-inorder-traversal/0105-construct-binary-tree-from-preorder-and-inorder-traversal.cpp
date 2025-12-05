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
    vector<int> m_pre;
    vector<int> m_in;
    TreeNode* BST(int pl, int pr, int il, int ir){
        if(pl > pr || il > ir) return nullptr;

        // pre의 가장 왼쪽은 root
        // in의 root를 찾고 그 왼쪽과 오른쪽을 나눔
        int rootVal = m_pre[pl];
        int inIdx = -1;
        for(int idx = il; idx <= ir; idx++){
            if(rootVal == m_in[idx]){
                inIdx = idx;
                break;
            }
        }

        int leftSize = inIdx - il;
        int rightSize = ir - inIdx;

        auto lNode = BST(pl+1, pl+leftSize, il, inIdx-1);
        auto rNode = BST(pl+1+leftSize, pr, inIdx+1, ir);
        TreeNode* root = new TreeNode(rootVal);
        root->left = lNode;
        root->right = rNode;

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        m_pre = preorder;
        m_in = inorder;
        return BST(0, preorder.size()-1, 0, inorder.size()-1);
    }
};