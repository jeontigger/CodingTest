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
    vector<int> m_in;
    vector<int> m_post;
    TreeNode* BST(int il, int ir, int pl, int pr){
        if(il > ir || pl > pr) return nullptr;

        // post의 pr 자리가 root
        // in에서 root의 자리를 찾고, 왼쪽과 오른쪽을 나누는 거임

        int rootVal = m_post[pr];
        int rootIdx = -1;
        for(int i = il; i <=ir; i++){
            if(m_in[i] == rootVal){
                rootIdx = i;
                break;
            }
        }

        auto l = BST(il, rootIdx-1, pl, pl + rootIdx - il - 1);
        auto r = BST(rootIdx+1, ir, pl + rootIdx - il, pr-1);
        TreeNode* root = new TreeNode(rootVal);
        root->left = l;
        root->right = r;

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m_in = inorder, m_post = postorder;

        return BST(0, inorder.size()-1, 0, postorder.size()-1);

    }
};