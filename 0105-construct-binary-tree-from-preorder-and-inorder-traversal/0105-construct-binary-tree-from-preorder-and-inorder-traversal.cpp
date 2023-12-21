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
    void printVec(vector<int> vec){
        for(int i: vec){
            cout << i << " ";
        }
        cout << endl;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0||inorder.size() == 0){
            return nullptr;
        }

        int value = preorder[0];
        int cnt = find(inorder.begin(), inorder.end(), value) - inorder.begin();
        vector<int> preLeft(preorder.begin()+1, preorder.begin() + cnt + 1);
        vector<int> preRight(preorder.begin() + cnt + 1, preorder.end());

        // printVec(preLeft);
        // printVec(preRight);

        vector<int> inLeft(inorder.begin(), inorder.begin() + cnt);
        vector<int> inRight(inorder.begin() + cnt+ 1, inorder.end());
        // printVec(inLeft);
        // printVec(inRight);

        TreeNode* pNode = new TreeNode(value);
        pNode->left = buildTree(preLeft, inLeft);
        pNode->right = buildTree(preRight, inRight);


        return pNode;
    }
};